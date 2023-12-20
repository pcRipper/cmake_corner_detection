# Instalation
1) in CMakeLists.txt replace "D://code//cpp//libraries" (5th line) with actual path to opencv library;
2) include in project or environment of your system opencv_world481.dll if .exe file doesnt work (the path for dll should opencv//build//x64//vc16//bin);
3) run ```cmake . -G "Visual Studio 16 2019" -A x64``` command in project directory;
4) build the project via desired software;


# Results
## Fast 
![Screenshot 2023-12-20 125313](https://github.com/pcRipper/cmake_corner_detection/assets/73016803/a084bea9-48f7-4392-a4d6-2a06cea42bbb)
![Screenshot 2023-12-20 125404](https://github.com/pcRipper/cmake_corner_detection/assets/73016803/986a5d0b-c300-4324-8a91-887257f30776)
## KLT

