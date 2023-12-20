#pragma once

#include <iostream>
#include <functional>
#include <opencv2/opencv.hpp>

class Functions {
public:
    
    template<class InputType, class OutputType>
    static std::vector<OutputType>* map(const std::vector<InputType>& data, std::function<OutputType(const InputType&)> functor){
        std::vector<OutputType> *result = new std::vector<OutputType>();
        result->reserve(data.size());

        for(const auto& element : data){
            result->push_back(functor(element));
        }

        return result;
    }
    
    static void markCorners(cv::Mat& image,const std::vector<cv::Point> &corners);
    static void showGIF(std::vector<cv::Mat>& frames, const int FPS, const bool looped);

    static cv::Mat grayScale(const cv::Mat& image);
};