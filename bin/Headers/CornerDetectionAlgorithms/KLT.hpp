#pragma once

#include <math.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "../Functions.hpp"
#include "FAST.hpp"

/// @brief 
/// @param stream list of consecutive images
/// @return the key points, locations of corners for each frame(image)
std::vector<std::vector<cv::Point>>* KLT(const std::vector<cv::Mat> stream);