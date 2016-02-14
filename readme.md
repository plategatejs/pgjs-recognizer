# pgjs-recognizer

[PlateGateJS](https://github.com/plategatejs/pgjs-docs) plate recognition component.

## Summary

This module:

* Subscribes to [Redis](http://redis.io) channel for images
* Uses [OpenAlpr](https://github.com/openalpr/openalpr) to recognize plates on the image
* Publishes plates to [Redis](http://redis.io) channel

Api:

* Incoming images must be _base64_ encoded, binary string
* Outgoing plates are _JSON_ array of strings
* Channel names, by default, are _images_ and _plates_

## Basic setup

Node.js ~5.0.0+ and Npm are required.

Also, [OpenAlpr](https://github.com/openalpr/openalpr) is required. Detailed instructions on how to install it can be found in its repository, but something like this should work too:

```
wget -O - http://deb.openalpr.com/openalpr.gpg.key | sudo apt-key add -
echo "deb http://deb.openalpr.com/master/ openalpr main" | sudo tee /etc/apt/sources.list.d/openalpr.list
sudo apt-get update
sudo apt-get install libopenalpr-dev

sudo apt-get install libopencv-dev libtesseract-dev git cmake build-essential libleptonica-dev
sudo apt-get install liblog4cplus-dev libcurl3-dev

git clone https://github.com/openalpr/openalpr.git
cd openalpr/src
mkdir build
cd build
make
sudo make install
```

And then just:

```
npm install
npm start
```

## License
[MIT](license.md)
