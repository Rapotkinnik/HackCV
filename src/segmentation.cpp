#include "segmentation.h"

cv::Mat1b PickOutRedColor(cv::Mat image) {
  cv::Mat3b hsv;
  cvtColor(image, hsv, cv::COLOR_BGR2HSV);

  cv::Mat1b mask1, mask2;
  cv::inRange(hsv, cv::Scalar(0, 70, 50), cv::Scalar(10, 255, 255), mask1);
  cv::inRange(hsv, cv::Scalar(170, 70, 50), cv::Scalar(180, 255, 255), mask2);

  return mask1 | mask2;
}

cv::Mat1b PickOutWhiteColor(cv::Mat image) {
	cv::Mat3b hsv;
	cvtColor(image, hsv, cv::COLOR_BGR2HSV);

	cv::Mat1b mask1, mask2;

	cv::inRange(hsv, cv::Scalar(0, 0, 150, 0), cv::Scalar(180, 255, 255, 0), mask1);
	return mask1;
}


cv::Mat1b PickOutBlueColor(cv::Mat image) {
	cv::Mat3b hsv;
	cvtColor(image, hsv, cv::COLOR_BGR2HSV);

	cv::Mat1b mask1;
	cv::inRange(hsv, cv::Scalar(100, 70, 50), cv::Scalar(130, 255, 255), mask1);
	return mask1;
}


std::vector<cv::Vec3f> findCircleRoadSigns(cv::Mat image)
{
  cv::medianBlur(image, image, 1);
  std::vector<cv::Vec3f> circles;

  cv::HoughCircles(image, circles, cv::HOUGH_GRADIENT, 1,
                   image.rows/16,  // change this value to detect circles with different distances to each other
               100, 20, 10, 60 // change the last two parameters
    // (min_radius & max_radius) to detect larger circles
  );

  return circles;
}

std::vector<std::vector<cv::Point>> findContours(cv::Mat image)
{
	int erosion_size = 6;
	cv::Mat element = getStructuringElement(cv::MORPH_ELLIPSE,
		cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
		cv::Point(erosion_size, erosion_size));

	cv::Mat dilate_img;
	cv::dilate(image, dilate_img, element);

	std::vector<std::vector<cv::Point>> contours;
	cv::findContours(dilate_img, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

	return contours;
}