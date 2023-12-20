#include "../Headers/Functions.hpp"

cv::Mat Functions::grayScale(const cv::Mat& image){

    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    return gray;
}

void Functions::markCorners(cv::Mat& image,const std::vector<cv::Point> &corners){
    
    static const cv::Scalar COLOR = cv::Scalar(0, 0, 255);

    for(const auto& point : corners){
        cv::circle(image, point, 2, COLOR, 1);
    }

}

void Functions::showGIF(std::vector<cv::Mat>& frames, const int FPS = 20, const bool looped = true){

    const int DELAY = std::max(1, 1000 / FPS);
    const int SIZE = frames.size();

    do{
        for(int i = 0;i < SIZE;++i){
            cv::imshow("GIF", frames[i]);
            if(cv::waitKey(DELAY) != -1){
                return;
            }
        }
        
    }while(looped);
}