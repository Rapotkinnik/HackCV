// opencvexample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
using namespace std;
using namespace cv;

char window_name[] = "Demo";



int test_template_match()
{
	cv::Mat src_img, template_img;
	cv::Mat result_mat;
	cv::Mat debug_img;

	template_img = cv::imread("C:\\Users\\Anton\\Desktop\\примеры\\test.png", CV_LOAD_IMAGE_GRAYSCALE);
	if (template_img.data == NULL) {
		printf("cv::imread() failed...\n");
		return -1;
	}

	src_img = cv::imread("C:\\Users\\Anton\\Desktop\\примеры\\стоянка запрещена.JPG", CV_LOAD_IMAGE_GRAYSCALE);
	if (src_img.data == NULL) {
		printf("cv::imread() failed...\n");
		return -1;
	}
	cv::cvtColor(src_img, debug_img, CV_GRAY2BGR);

	while (true) {
		// method: CV_TM_SQDIFF, CV_TM_SQDIFF_NORMED, CV_TM _CCORR, CV_TM_CCORR_NORMED, CV_TM_CCOEFF, CV_TM_CCOEFF_NORMED
		int match_method = CV_TM_SQDIFF_NORMED;
		cv::matchTemplate(src_img, template_img, result_mat, match_method);
		cv::normalize(result_mat, result_mat, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());

		double minVal; double maxVal;
		cv::Point minLoc, maxLoc, matchLoc;
		cv::minMaxLoc(result_mat, &minVal, &maxVal, &minLoc, &maxLoc, cv::Mat());
		if (match_method == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED)  matchLoc = minLoc;
		else matchLoc = maxLoc;

		cv::rectangle(
			debug_img,
			matchLoc,
			cv::Point(matchLoc.x + template_img.cols, matchLoc.y + template_img.rows),
			CV_RGB(255, 0, 0),
			3);

		cv::imshow("debug_img", debug_img);

		int c = cv::waitKey(1);
		if (c == 27) break;
	}

	return 0;
}

