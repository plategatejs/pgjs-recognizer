/*
 * QueueHandler.h
 *
 *  Created on: 6 Jun 2015
 *      Author: mateusz
 */

#ifndef QUEUEHANDLER_H_
#define QUEUEHANDLER_H_

#include <SimpleAmqpClient/SimpleAmqpClient.h>

using namespace std;
using namespace AmqpClient;

class QueueHandler {
public:
	QueueHandler(const string &host, const int port, const string &username, const string &password,
			const string &inputExchangeName, const string &outputExchangeName) :
			inputExchangeName_(inputExchangeName), outputExchangeName_(outputExchangeName), connection(Channel::Create(host, port, username, password)) {
		connection->DeclareExchange(outputExchangeName);
		connection->BasicConsume(inputExchangeName);
	}

	void sendString(const string &data);
	string waitForMessageString();

private:
	const string inputExchangeName_, outputExchangeName_;
	Channel::ptr_t connection;
};

#endif /* QUEUEHANDLER_H_ */
