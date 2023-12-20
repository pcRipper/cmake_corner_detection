#include "../../Headers/CornerDetectionAlgorithms/KLT.hpp"

std::vector<std::vector<cv::Point>>* KLT(const std::vector<cv::Mat> stream){

    std::vector<std::vector<cv::Point>>* keyPoints = new std::vector<std::vector<cv::Point>>();

    if(stream.size() < 2)return keyPoints;

    keyPoints->resize(stream.size());
    auto grayStream = *Functions::map<cv::Mat, cv::Mat>(stream, Functions::grayScale);


    //TODO:
    //transform image to grayscale -> gray
    //detect using FAST key points(corners)
    //iterate through the frames, using previous data, and detect points transition
    //write down array of tracked points into corresponding row of result matrix


    return keyPoints;
}