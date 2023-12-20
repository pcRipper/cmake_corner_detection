#include <math.h>
#include <iostream>
#include <opencv2/opencv.hpp>

bool isCorner(const cv::Mat& image, const int x, const int y, const int THRESHOLD);
std::vector<cv::Point>* FAST(const cv::Mat& image,const int THRESHOLD);