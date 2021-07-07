#pragma once
#pragma comment(lib,"libarcsoft_idcardveri.lib")
#include<opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "arcsoft_idcardveri.h"
#include "asvloffscreen.h"
#include "amcomdef.h"
#include "merror.h"
#define APPID	"8RFuAJtQ5ch1yRNZVG4jLtFh4i3vHudxyPPrUhqH7YwK"			//APPID
#define SDKKey	"3kCNnN4FiqS8X7F1LqNUtqZMCbpPf5gW5kr1SBFvy1xV"			//SDKKey
using namespace cv;
using namespace std;
class FaceIDCompare
{
private:
	Mat faceImg;
	Mat IdImg;
	MHandle hEngine;
	ASVLOFFSCREEN faceImgInfo;
	ASVLOFFSCREEN IdImgInfo;
	MRESULT activateSDK();
	MRESULT initEngine(MHandle* hEngine);
	void setFaceImgInfo();
	void setIdImgInfo();
public:
	FaceIDCompare(Mat faceImg,Mat IdImg);
	FaceIDCompare();
	~FaceIDCompare();
	bool setFaceImg(Mat faceImg);
	bool setIdImg(Mat IdImg);
	int compare(MFloat g_threshold = 0.82);
};

