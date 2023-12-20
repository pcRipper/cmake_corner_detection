#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "bin/Headers/CornerDetectionAlgorithms/FAST.hpp"
#include "bin/Headers/CornerDetectionAlgorithms/KLT.hpp"
#include "bin/Headers/MediaLoader.hpp"
#include "bin/Headers/Functions.hpp"

void example_FAST(){
    using namespace std;
    using namespace cv;

    const vector<pair<string,int>> paths = {
        {"D://code//cpp/projects//cmake_corner_detection//images//examples_fast//signal-2023-12-14-212155_002.jpeg", IMREAD_GRAYSCALE},
        {"D://code//cpp/projects//cmake_corner_detection//images//examples_fast//signal-2023-12-14-212155_003.jpeg", IMREAD_GRAYSCALE}
    };
    const int THRESHOLD = 20;    

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

void example_KLT(){
    using namespace std;
    using namespace cv;

    try{
        const String PATH = "D://code//cpp/projects//cmake_corner_detection//images//examples_klt//4.gif";
        // auto gif = *MediaLoader::loadGIF(PATH);

        // if(gif.size() == 0){
        //     throw exception("Could not open the GIF file.\n");
        // }
        

        // auto g = pyramidRepresntation(gif[0], 3);

        // Functions::showGIF(*g, 1, true);

        cv::Mat img = cv::imread("D://code//cpp/projects//cmake_corner_detection//images//examples_fast//signal-2023-12-14-212155_002.jpeg");

        auto g = pyramidRepresntation(img, 4);

        Functions::showGIF(*g, 1 ,true);

        // auto gif_tracked = *Functions::map<Mat,Mat>(gif, [](const Mat& obj){
        //     Mat result = obj.clone();
        //     Functions::markCorners(result, *FAST(Functions::grayScale(result), 30));
        //     return result;
        // });

        // Functions::showGIF(gif_tracked, 50, true);


    }
    catch(const exception& ex) {

        cout << "Error occured: " << ex.what() << '\n';

    }
}

int main(int argc,char** argv){

    // example_FAST();

    example_KLT();

    return 0;
}