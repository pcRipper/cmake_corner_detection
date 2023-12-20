//TODO:
//describe static class with such functions
// load images from paths,
// load all images from specific folder,
// load gifs from paths,
// load all gifs from specific folder

#include <opencv2/opencv.hpp>

class MediaLoader{
public:
    /// @brief 
    /// @param paths vector of paths to images, those need to be loaded
    /// @return vector of loaded images
    static std::vector<cv::Mat>* loadImages(const std::vector<std::pair<std::string, int>>& paths);
};