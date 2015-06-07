#include <iostream>
#include <opencv2/opencv.hpp>
#include "include/Properties.h"
#include "include/QueueHandler.h"
#include "include/ALPRHandler.h"
#include <fstream>
#include <vector>

using namespace std;

Properties readPropertiesFromFile(const string &fileName) {
	Properties properties;
	ifstream configFileStream(fileName.c_str());

	configFileStream >> properties.host;
	configFileStream >> properties.port;
	configFileStream >> properties.username;
	configFileStream >> properties.password;
	configFileStream >> properties.inputQueueName;
	configFileStream >> properties.outputQueueName;

	configFileStream.close();
	return properties;
}

int main() {
	Properties properties = readPropertiesFromFile("config");

	QueueHandler queueHandler(properties.host, properties.port, properties.username, properties.password,
			properties.inputQueueName, properties.outputQueueName);
	ALPRHandler alprHandler;

	//while (1) {
	string binaryImage = queueHandler.waitForMessageString();
	vector<char> charImage(binaryImage.c_str(), binaryImage.c_str() + binaryImage.length());
	cv::Mat image = cv::imdecode(cv::Mat(charImage), 1);
	string result = alprHandler.getPlatesFromImage(image);
	queueHandler.sendString(result);
	//}

	return 0;
}
