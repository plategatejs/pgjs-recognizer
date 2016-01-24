'use strict';

import Controller from './controller';
import Recognizer from './recognizer';

export default () => {
  const controller = new Controller;
  const recognizer = new Recognizer;

  controller.on('image', image => recognizer.enqueue(image));

  recognizer
    .on('plates', plates => controller.enqueue(plates))
    .start();

  controller.start();
}
