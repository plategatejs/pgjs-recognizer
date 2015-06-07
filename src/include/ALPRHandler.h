/*
 * ALPRHandler.h
 *
 *  Created on: 6 Jun 2015
 *      Author: mateusz
 */

#ifndef ALPRHANDLER_H_
#define ALPRHANDLER_H_

#include <vector>
#include <alpr.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace alpr;
using namespace std;

class ALPRHandler {
public:
	ALPRHandler() :
			alpr_("eu") {
	}

	string getPlatesFromImage(const cv::Mat &image);

private:
	Alpr alpr_;
};

#endif /* ALPRHANDLER_H_ */
