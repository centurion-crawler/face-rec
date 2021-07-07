#include "FaceIDCompare.h"
FaceIDCompare::FaceIDCompare(Mat faceImg, Mat IdImg)
{
	this->faceImg = faceImg;
	this->IdImg = IdImg;
	hEngine = { 0 };
	activateSDK();
	initEngine(&hEngine);//初始化引擎
	setFaceImgInfo();
	setIdImgInfo();
}

FaceIDCompare::FaceIDCompare()
{
	hEngine = { 0 };
	activateSDK();
	initEngine(&hEngine);//初始化引擎
}

MRESULT FaceIDCompare::activateSDK()
{
	return ArcSoft_FIC_Activate((MPChar)APPID, (MPChar)SDKKey);//激活sdk
}

MRESULT FaceIDCompare::initEngine(MHandle* hEngine)
{
	return ArcSoft_FIC_InitialEngine(hEngine);
}

void FaceIDCompare::setFaceImgInfo()
{
	faceImgInfo = { 0 };
	faceImgInfo.i32Width = faceImg.cols;
	faceImgInfo.i32Height = faceImg.rows;
	faceImgInfo.u32PixelArrayFormat = ASVL_PAF_RGB24_B8G8R8;
	faceImgInfo.pi32Pitch[0] = faceImgInfo.i32Width * 3;
	faceImgInfo.ppu8Plane[0] = (MUInt8*)faceImg.data;
}
void FaceIDCompare::setIdImgInfo()
{
	IdImgInfo = { 0 };
	IdImgInfo.i32Width = IdImg.cols;
	IdImgInfo.i32Height = IdImg.rows;
	IdImgInfo.u32PixelArrayFormat = ASVL_PAF_RGB24_B8G8R8;
	IdImgInfo.pi32Pitch[0] = IdImgInfo.i32Width * 3;
	IdImgInfo.ppu8Plane[0] = (MUInt8*)IdImg.data;
}

bool FaceIDCompare::setFaceImg(Mat FaceImg)
{
	this->faceImg = FaceImg;
	return !(this->faceImg.empty());
}

bool FaceIDCompare::setIdImg(Mat IdImg)
{
	this->IdImg = IdImg;
	return !(this->IdImg.empty());
}

int FaceIDCompare::compare(MFloat g_threshold)
{
	setFaceImgInfo();
	setIdImgInfo();
	LPAFIC_FSDK_FACERES pFaceRes = (LPAFIC_FSDK_FACERES)malloc(sizeof(AFIC_FSDK_FACERES));
	ArcSoft_FIC_FaceDataFeatureExtraction(hEngine, 0, &faceImgInfo, pFaceRes);
	ArcSoft_FIC_IdCardDataFeatureExtraction(hEngine, &IdImgInfo);
	MFloat pSimilarScore = 0.0f;
	MInt32 pResult = 0;
	ArcSoft_FIC_FaceIdCardCompare(hEngine, g_threshold, &pSimilarScore, &pResult);
	return pResult;
}

FaceIDCompare::~FaceIDCompare()
{
	ArcSoft_FIC_UninitialEngine(hEngine);
}

