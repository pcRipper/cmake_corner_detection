#include <iostream>
#include <opencv2/opencv.hpp>

class Functions{
public:
    static void markCorners(cv::Mat& image,const std::vector<cv::Point> &corners);
};