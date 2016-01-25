'use strict';

import EventEmitter from 'events';
import config from 'config';
import { publishClient, subscribeClient } from './redis';
import logger from './logger';

const Controller = function () {
  EventEmitter.call(this);

  const channels = config.get('redis.channels');

  subscribeClient.on('message', (channel, message) => {
    if (channel === channels.images) {
      logger.info('image received');
      const image = new Buffer(message, 'base64');
      this.emit('image', image);
    }
  });

  this.enqueue = (plates) => {
    publishClient.publish(channels.plates, JSON.stringify(plates));
  };

  this.start = () => subscribeClient.subscribe(channels.images);
};

Controller.prototype = Object.create(EventEmitter.prototype);
Controller.prototype.constructor = Controller;

export default Controller;
