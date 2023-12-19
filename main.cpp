#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc,char** argv){

    cv::Mat image = cv::imread("C://Users//Maxim//Pictures//bubble_cat.jpg");

    // Check if the image was successfully loaded
    if (image.empty()) {
        std::cerr << "Error: Could not open or find the image.//n";
        return -1;
    }

    // Display the image in a window
    cv::imshow("Image", image);

    // Wait for a key press and then close the window
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}