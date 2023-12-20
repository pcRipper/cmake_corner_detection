#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "bin/Headers/CornderDetectionAlgorithms.hpp"
#include "bin/Headers/MediaLoader.hpp"
#include "bin/Headers/Functions.hpp"

void example_FAST(){
    using namespace std;
    using namespace cv;

    const vector<pair<string,int>> paths = {
        {"D://code//cpp/projects//cmake_corner_detection//images//examples_fast//signal-2023-12-14-212155_002.jpeg", IMREAD_GRAYSCALE},
        {"D://code//cpp/projects//cmake_corner_detection//images//examples_fast//signal-2023-12-14-212155_003.jpeg", IMREAD_GRAYSCALE}
    };
    const int THRESHOLD = 30;    

    try{
        auto images = *MediaLoader::loadImages(paths);
        if(images.size() == 0)throw exception("No images were loaded");

        for(const auto& image : images){
            
            auto corners = *FAST(image, THRESHOLD);
            Mat image_copy = image.clone();

            Functions::markCorners(image_copy, corners);

            imshow("Original Image", image);
            imshow("FAST Corner Detection", image_copy);
            waitKey(0);
        }
    }
    catch(const exception& ex) {

        cout << "Error occured: " << ex.what() << '\n';

    }
}

int main(int argc,char** argv){

    example_FAST();

    return 0;
}