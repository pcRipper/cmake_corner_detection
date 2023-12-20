#include "../../Headers/CornerDetectionAlgorithms/FAST.hpp"

bool isCorner(const cv::Mat& image, const int x, const int y, const int threshold) {
    // Circle points
    static const int OFFSETS[16][2] = {
        {-3, 0}, {-3, 1}, {-2, 2}, {-1, 3},
        {0, 3}, {1, 3}, {2, 2}, {3, 1},
        {3, 0}, {3, -1}, {2, -2}, {1, -3},
        {0, -3}, {-1, -3}, {-2, -2}, {-3, -1}
    };

    // Count the number of brighter or darker pixels in the circle
    int pixelValue = image.at<uchar>(y, x);
    int brighterCount = 0;
    int darkerCount = 0;

    for (int i = 0; i < 16; ++i) {
        int offsetX = x + OFFSETS[i][0];
        int offsetY = y + OFFSETS[i][1];

        //Not necessary to check the range if this function called from FAST algorithm
        if (offsetX >= 0 && offsetX < image.cols && offsetY >= 0 && offsetY < image.rows) {
            int neighborValue = image.at<uchar>(offsetY, offsetX);

            if (neighborValue - pixelValue > threshold) {
                ++brighterCount;
            } else if (pixelValue - neighborValue > threshold) {
                ++darkerCount;
            }
        }
    }

    // Check if the pixel is a corner based on the counts
    return brighterCount >= 12 || darkerCount >= 12;
}

std::vector<cv::Point>* FAST(const cv::Mat& image,const int threshold) {

    const std::pair<int,int> range = std::make_pair(image.rows - 3, image.cols - 3);
    std::vector<cv::Point>* corner_positions = new std::vector<cv::Point>();

    for (int y = 3; y < image.rows - 3; ++y) {
        for (int x = 3; x < image.cols - 3; ++x) {
            if (isCorner(image, x, y, threshold)) {
                corner_positions->push_back(cv::Point(x,y));
            }
        }
    }

    return corner_positions;
}