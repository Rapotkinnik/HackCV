#pragma once

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

cv::Mat1b PickOutRedColor(cv::Mat3b image);


std::vector<cv::Vec3f> findCircleRoadSigns(cv::Mat1b image);