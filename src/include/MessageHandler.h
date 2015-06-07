/*
 * MessageHandler.h
 *
 *  Created on: 6 Jun 2015
 *      Author: mateusz
 */

#ifndef MESSAGEHANDLER_H_
#define MESSAGEHANDLER_H_

using namespace std;

class MessageHandler {
public:
	virtual void onMessage(const string &message) = 0;
	virtual ~MessageHandler() = 0;
};

#endif /* MESSAGEHANDLER_H_ */
