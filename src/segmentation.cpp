#include "segmentation.h"

cv::Mat1b PickOutRedColor(cv::Mat3b image) {
  cv::Mat3b bgr = cv::imread("path_to_image");

  cv::Mat3b hsv;
  cvtColor(bgr, hsv, cv::COLOR_BGR2HSV);

  cv::Mat1b mask1, mask2;
  cv::inRange(hsv, cv::Scalar(0, 70, 50), cv::Scalar(10, 255, 255), mask1);
  cv::inRange(hsv, cv::Scalar(170, 70, 50), cv::Scalar(180, 255, 255), mask2);

  return mask1 | mask2;
}



std::vector<cv::Vec3f> findCircleRoadSigns(cv::Mat1b image)
{
  cv::medianBlur(image, image, 5);
  std::vector<cv::Vec3f> circles;

  cv::HoughCircles(image, circles, cv::HOUGH_GRADIENT, 1,
                   image.rows/16,  // change this value to detect circles with different distances to each other
               100, 30, 1, 30 // change the last two parameters
    // (min_radius & max_radius) to detect larger circles
  );

  return circles;
}