#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
using namespace std;
using namespace cv;

char window_name[] = "Demo";

int main(void)
{
	namedWindow(window_name, WINDOW_AUTOSIZE);
	auto src = imread("D:\\test\\1.jpg", IMREAD_COLOR);
    
	imshow(window_name, src);
	waitKey(0);
	return 0;
}