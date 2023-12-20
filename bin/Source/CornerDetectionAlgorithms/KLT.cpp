#include "../../Headers/CornerDetectionAlgorithms/KLT.hpp"

std::vector<cv::Mat>* pyramidRepresntation(const cv::Mat& image, const int levels){

    std::vector<cv::Mat>* pyramid = new std::vector<cv::Mat>({ image.clone() });
    pyramid->reserve(levels);
    
    int height = image.rows;
    int width = image.cols;

    // Generate the pyramid levels
    for (int i = 1; i < levels; ++i) {
        
        height /= 2;
        width /= 2;

        cv::Mat downsampled(height, width, pyramid->back().type());
        
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                
                //coefficients {4,8,16} - too bright 

                downsampled.at<cv::Vec3b>(y, x) = 
                    (*pyramid)[i - 1].at<cv::Vec3b>(2 * y, 2 * x) / 3 +
                    (
                        (*pyramid)[i - 1].at<cv::Vec3b>(2 * y, std::max(0, 2 * x - 1)) +
                        (*pyramid)[i - 1].at<cv::Vec3b>(2 * y,  2 * x + 1) +
                        (*pyramid)[i - 1].at<cv::Vec3b>(std::max(0, 2 * y - 1), 2 * x) +
                        (*pyramid)[i - 1].at<cv::Vec3b>(2 * y + 1, 2 * x)
                    ) / 5 +
                    (
                        (*pyramid)[i - 1].at<cv::Vec3b>(std::max(0, 2 * y - 1), std::max(0, 2 * x - 1)) + 
                        (*pyramid)[i - 1].at<cv::Vec3b>(2 * y + 1, 2 * x + 1) +
                        (*pyramid)[i - 1].at<cv::Vec3b>( 2 * y + 1,  std::max(0, 2 * x - 1)) + 
                        (*pyramid)[i - 1].at<cv::Vec3b>( std::max(0, 2 * y - 1),  2 * x + 1) 
                    ) / 13
                ;
            }
        }

        pyramid->push_back(downsampled.clone());
    }

    return pyramid;
}

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