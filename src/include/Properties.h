/*
 * Properties.h
 *
 *  Created on: 6 Jun 2015
 *      Author: mateusz
 */

#ifndef INCLUDE_PROPERTIES_H_
#define INCLUDE_PROPERTIES_H_

using namespace std;

class Properties {
public:
	string host, username, password, inputQueueName, outputQueueName;
	int port;
};

#endif /* INCLUDE_PROPERTIES_H_ */
