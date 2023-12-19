#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "bin/Headers/CornderDetectionAlgorithms.hpp"

int main(int argc,char** argv){

    using namespace std;

    try{

        someFunc();

        cout << "Starting a program!\n";
        cout << "Loading an image...\n";

        const cv::String IMG_PATH = "D://code//cpp//projects//cmake_corner_detection//images//bubble_cat.jpg";
        cout << IMG_PATH << '\n';
        cv::Mat image = cv::imread(IMG_PATH);

        // Check if the image was successfully loaded
        if (image.empty()) {
            std::cerr << "Error: Could not open or find the image.\n";
            return -1;
        }

        // Display the image in a window
        cv::imshow("Image", image);

        // Wait for a key press and then close the window
        cv::waitKey(0);
        cv::destroyAllWindows();
    }
    catch(const exception& ex) {

        cout << ex.what() << '\n';

    }

    return 0;
}