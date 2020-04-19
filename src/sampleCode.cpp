//#include<opencv2/opencv.hpp>
//#include <opencv2/highgui.hpp>
//#include "arcsoft_idcardveri.h"
//#include "asvloffscreen.h"
//#include "amcomdef.h"
//#include "merror.h"
//
//#pragma comment(lib,"libarcsoft_idcardveri.lib")
//
//#define APPID	"8RFuAJtQ5ch1yRNZVG4jLtFh4i3vHudxyPPrUhqH7YwK"			//APPID
//#define SDKKey	"3kCNnN4FiqS8X7F1LqNUtqZMCbpPf5gW5kr1SBFvy1xV"			//SDKKey
//using namespace cv;
//using namespace std;
//int main()
//{
//	Mat img0 = imread("face.jpg");//人脸
//	Mat img1 = imread("fh.jpg");//证件照
//	if (!(img0.empty() || img1.empty()))
//	{
//		MRESULT res = ArcSoft_FIC_Activate((MPChar)APPID, (MPChar)SDKKey);
//		if (res != MOK && res != MERR_ASF_ALREADY_ACTIVATED)
//		{
//			printf("Activate failed, error code: %d\n", res);
//			return -1;
//		}
//
//		/* 初始化人证比对引擎*/
//		MHandle hEngine = { 0 };
//		res = ArcSoft_FIC_InitialEngine(&hEngine);
//		if (res != MOK)
//		{
//			printf("Initial Engine failed, error code: %d\n", res);
//			return -1;
//		}
//		/* 读取预览静态图片信息，并保存到ASVLOFFSCREEN结构体 （以ASVL_PAF_RGB24_B8G8R8格式为例） 图片数据为BGR原始数据 */
//		ASVLOFFSCREEN imgInfo0 = { 0 };
//		imgInfo0.i32Width = img0.cols;
//		imgInfo0.i32Height = img0.rows;
//		imgInfo0.u32PixelArrayFormat = ASVL_PAF_RGB24_B8G8R8;
//		imgInfo0.pi32Pitch[0] = imgInfo0.i32Width * 3;
//		imgInfo0.ppu8Plane[0] = (MUInt8*)img0.data;
//		/* 人脸特征提取 0-静态图片 1-视频 */
//		LPAFIC_FSDK_FACERES pFaceRes = (LPAFIC_FSDK_FACERES)malloc(sizeof(AFIC_FSDK_FACERES));
//		res = ArcSoft_FIC_FaceDataFeatureExtraction(hEngine, 0, &imgInfo0, pFaceRes);
//		if (res != MOK)
//		{
//			printf("Face Feature Extraction failed, error code: %d\n", res);
//			return -1;
//		}
//
//		/* 读取证件照静态图片信息，并保存到ASVLOFFSCREEN结构体 （以ASVL_PAF_RGB24_B8G8R8格式为例） 图片数据为BGR原始数据 */
//		ASVLOFFSCREEN imgInfo1 = { 0 };
//		imgInfo1.i32Width = img1.cols;
//		imgInfo1.i32Height = img1.rows;
//		imgInfo1.u32PixelArrayFormat = ASVL_PAF_RGB24_B8G8R8;
//		imgInfo1.pi32Pitch[0] = imgInfo1.i32Width * 3;
//		imgInfo1.ppu8Plane[0] = (MUInt8*)img1.data;
//
//		/* 证件照特征提取 */
//		res = ArcSoft_FIC_IdCardDataFeatureExtraction(hEngine, &imgInfo1);
//		if (res != MOK)
//		{
//			printf("IdCard Feature Extraction failed, error code: %d\n", res);
//			return -1;
//		}
//
//		/* 人证比对 */
//		MFloat pSimilarScore = 0.0f;
//		MInt32 pResult = 0;
//		MFloat g_threshold = 0.82;
//		res = ArcSoft_FIC_FaceIdCardCompare(hEngine, g_threshold, &pSimilarScore, &pResult);
//		if (res != MOK)
//		{
//			printf("Face IdCard Compare failed, error code: %d\n", res);
//			return -1;
//		}
//
//		/* 反初始化引擎 */
//		res = ArcSoft_FIC_UninitialEngine(hEngine);
//		if (res != MOK)
//		{
//			printf("Uninitial Engine failed, error code: %d\n", res);
//			return -1;
//		}
//		printf("the presult is %d", pResult);
//	}
//	//cvReleaseImage(&img0);		//video模式下如果在compare接口之前图像数据被
//						//释放可能会导致比对失败或carsh；
//
//	//cvReleaseImage(&img1);
//	return 0;
//}
