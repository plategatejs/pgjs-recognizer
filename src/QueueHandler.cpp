/*
 * QueueHandler.cpp
 *
 *  Created on: 6 Jun 2015
 *      Author: mateusz
 */

#include "include/QueueHandler.h"

void QueueHandler::sendString(const string &data) {
	BasicMessage::ptr_t outgoingMessage = BasicMessage::Create();
	outgoingMessage->Body(data);
	connection->BasicPublish(outputExchangeName_, "", outgoingMessage);
}

string QueueHandler::waitForMessageString() {
	BasicMessage::ptr_t incomingMessage = connection->BasicConsumeMessage()->Message();
	return incomingMessage->Body();
}
