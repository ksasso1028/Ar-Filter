// ArFilter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include"detectAndShow.h"
#include "prepCascade.h"
;
int main()
{
	//cREATE CAM OBJECT AND OPEN FIRST CAM READY.
	cv::VideoCapture cam(0);
	if (!cam.isOpened()) {
		std::cout << "Cam could not be opened" << std::endl;
	}
	
	while (1) {
		cv::Mat frame;
		cam >> frame;
		//NEED TO PROCESS FRAME HERE WITH CASCADES
		//THEN ADD  IMAGE TO OVERLAY
		prepCascade(frame);
		detectAndShow(frame);
		imshow("AR-FILTER", frame);

		//add Key event function
		if (cv::waitKey(30)>= 0) break;
	}
	cam.release();
	cv::destroyAllWindows();
	return 0;
}

