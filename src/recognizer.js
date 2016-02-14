'use strict';

import fs from 'fs';
import EventEmitter from 'events';
import config from 'config';
import OpenAlpr from 'node-openalpr';
import logger from './logger';

const Recognizer = function () {
  EventEmitter.call(this);

  const { tempPath, plateLimit } = config.get('recognition');

  const storeImage = (image) => new Promise((resolve, reject) => {
    fs.writeFile(tempPath, image.toString('binary'), 'binary', error => {
      if (error) {
        return reject(error);
      }

      resolve();
    });
  });

  const identifyPlates = () => new Promise((resolve, reject) => {
    OpenAlpr.IdentifyLicense(tempPath, (error, response) => {
      if (error) {
        return reject(error);
      }

      const plates = response.results
        .map(result => result.candidates)
        .reduce((previous, current) => previous.concat(current), [])
        .map(({plate, confidence}) => ({plate, confidence}))
        .sort(({confidence: a}, {confidence: b}) => a < b ? 1 : -1)
        .slice(0, plateLimit)
        .map(({plate}) => plate);

      resolve(plates);
    });
  });

  this.enqueue = (image) => {
    storeImage(image)
      .then(identifyPlates)
      .then((plates) => {
        if (plates.length) {
          logger.info(`recognized plates: ${plates.join(', ')}.`);
          this.emit('plates', plates);
        }
      })
      .catch(error => logger.error(error));
  };

  this.start = () => OpenAlpr.Start();
};

Recognizer.prototype = Object.create(EventEmitter.prototype);
Recognizer.prototype.constructor = Recognizer;

export default Recognizer;
