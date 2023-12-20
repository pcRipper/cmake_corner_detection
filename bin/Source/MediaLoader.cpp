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

std::vector<cv::Mat>* MediaLoader::loadGIF(const cv::String path){

    std::vector<cv::Mat>* result =  new std::vector<cv::Mat>();
    cv::VideoCapture gif(path, cv::CAP_FFMPEG);

    if(!gif.isOpened()){
        return result;
    }

    cv::Mat frame;
    while(true){
        gif >> frame;
        if(frame.empty())break;
        result->push_back(frame.clone());
    }

    gif.release();

    return result;
}