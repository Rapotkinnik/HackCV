#pragma once

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

cv::Mat1b PickOutRedColor(cv::Mat image);
cv::Mat1b PickOutWhiteColor(cv::Mat image);
cv::Mat1b PickOutBlueColor(cv::Mat image);


std::vector<cv::Vec3f> findCircleRoadSigns(cv::Mat image);
std::vector<std::vector<cv::Point>> findContours(cv::Mat image);