#include"FaceIDCompare.h"
using namespace cv;
using namespace std;
int main()
{
	Mat faceImg;
	Mat Idimg;
	faceImg = imread("face.jpg");
	Idimg = imread("fh.jpg");
	FaceIDCompare fc;
	fc.setFaceImg(faceImg);
	fc.setIdImg(Idimg);
	printf("the presult is :%d", fc.compare());
	return 0;

}