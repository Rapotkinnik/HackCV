#include "segmentation.h"

cv::Mat1b PickOutRedColor(cv::Mat image) {
  cv::Mat3b hsv;
  cvtColor(image, hsv, cv::COLOR_BGR2HSV);

  cv::Mat1b mask1, mask2;
  cv::inRange(hsv, cv::Scalar(0, 70, 50), cv::Scalar(10, 255, 255), mask1);
  cv::inRange(hsv, cv::Scalar(170, 70, 50), cv::Scalar(180, 255, 255), mask2);

  return mask1 | mask2;
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