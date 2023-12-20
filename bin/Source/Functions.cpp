#include "../Headers/Functions.hpp"

void Functions::markCorners(cv::Mat& image,const std::vector<cv::Point> &corners){
    
    static const cv::Scalar COLOR = cv::Scalar(0, 255, 0);

    for(const auto& point : corners){
        cv::circle(image, point, 3, COLOR, 1);
    }

}