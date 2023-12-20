#include <math.h>
#include <iostream>
#include <opencv2/opencv.hpp>

bool isCorner(const cv::Mat& image, const int x, const int y, const int threshold);
std::vector<cv::Point>* FAST(const cv::Mat& image,int threshold);