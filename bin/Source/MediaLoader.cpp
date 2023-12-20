#include "../Headers/MediaLoader.hpp"

std::vector<cv::Mat>* MediaLoader::loadImages(const std::vector<std::pair<std::string, int>>& paths){

    std::vector<cv::Mat>* images = new std::vector<cv::Mat>();

    for(const auto& pair : paths){
        cv::Mat image = cv::imread(pair.first, pair.second);
        if(!image.empty()){
            images->push_back(image);
        }
    }

    return images;
}