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
	cam.set(CV_CAP_PROP_BUFFERSIZE, 3);
	if (!cam.isOpened()) {
		std::cout << "Cam could not be opened" << std::endl;
	}
	
	while (1) {
		
		
		cv::Mat frame;
		cv::Mat detect;
		cam >> frame;
		
		detect = prepCascade(frame);//converts image to grey normalizes image
	
			detectAndShow(frame, detect);//Detects cascade in grey image and draws filter in color image
		
		
		
		imshow("AR-FILTER", frame);
		
		//add Key event function
		if (cv::waitKey(50)>= 0) break;
	}
	cam.release();
	cv::destroyAllWindows();
	return 0;
}

