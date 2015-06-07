/*
 * ALPRHandler.cpp
 *
 *  Created on: 6 Jun 2015
 *      Author: mateusz
 */

#include "include/ALPRHandler.h"

string ALPRHandler::getPlatesFromImage(const cv::Mat &image) {
	string jsonResults;
	vector<AlprRegionOfInterest> regionsOfInterest;
	AlprResults alprResults;

	regionsOfInterest.push_back(AlprRegionOfInterest(0, 0, image.cols, image.rows));
	alprResults = alpr_.recognize(image.data, image.elemSize(), image.cols, image.rows, regionsOfInterest);
	jsonResults = alpr_.toJson(alprResults);

	return jsonResults;
}

