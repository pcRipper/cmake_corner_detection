#include <opencv2/opencv.hpp>

class MediaLoader{
public:
    /// @brief 
    /// @param paths vector of paths to images, those need to be loaded
    /// @return vector of loaded images
    static std::vector<cv::Mat>* loadImages(const std::vector<std::pair<std::string, int>>& paths);
    /// @brief 
    /// @param path path to the gif 
    /// @return a vector of images, representing a gif
    static std::vector<cv::Mat>* loadGIF(const cv::String path);
};