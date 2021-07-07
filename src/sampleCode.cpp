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
//	Mat img0 = imread("face.jpg");//����
//	Mat img1 = imread("fh.jpg");//֤����
//	if (!(img0.empty() || img1.empty()))
//	{
//		MRESULT res = ArcSoft_FIC_Activate((MPChar)APPID, (MPChar)SDKKey);
//		if (res != MOK && res != MERR_ASF_ALREADY_ACTIVATED)
//		{
//			printf("Activate failed, error code: %d\n", res);
//			return -1;
//		}
//
//		/* ��ʼ����֤�ȶ�����*/
//		MHandle hEngine = { 0 };
//		res = ArcSoft_FIC_InitialEngine(&hEngine);
//		if (res != MOK)
//		{
//			printf("Initial Engine failed, error code: %d\n", res);
//			return -1;
//		}
//		/* ��ȡԤ����̬ͼƬ��Ϣ�������浽ASVLOFFSCREEN�ṹ�� ����ASVL_PAF_RGB24_B8G8R8��ʽΪ���� ͼƬ����ΪBGRԭʼ���� */
//		ASVLOFFSCREEN imgInfo0 = { 0 };
//		imgInfo0.i32Width = img0.cols;
//		imgInfo0.i32Height = img0.rows;
//		imgInfo0.u32PixelArrayFormat = ASVL_PAF_RGB24_B8G8R8;
//		imgInfo0.pi32Pitch[0] = imgInfo0.i32Width * 3;
//		imgInfo0.ppu8Plane[0] = (MUInt8*)img0.data;
//		/* ����������ȡ 0-��̬ͼƬ 1-��Ƶ */
//		LPAFIC_FSDK_FACERES pFaceRes = (LPAFIC_FSDK_FACERES)malloc(sizeof(AFIC_FSDK_FACERES));
//		res = ArcSoft_FIC_FaceDataFeatureExtraction(hEngine, 0, &imgInfo0, pFaceRes);
//		if (res != MOK)
//		{
//			printf("Face Feature Extraction failed, error code: %d\n", res);
//			return -1;
//		}
//
//		/* ��ȡ֤���վ�̬ͼƬ��Ϣ�������浽ASVLOFFSCREEN�ṹ�� ����ASVL_PAF_RGB24_B8G8R8��ʽΪ���� ͼƬ����ΪBGRԭʼ���� */
//		ASVLOFFSCREEN imgInfo1 = { 0 };
//		imgInfo1.i32Width = img1.cols;
//		imgInfo1.i32Height = img1.rows;
//		imgInfo1.u32PixelArrayFormat = ASVL_PAF_RGB24_B8G8R8;
//		imgInfo1.pi32Pitch[0] = imgInfo1.i32Width * 3;
//		imgInfo1.ppu8Plane[0] = (MUInt8*)img1.data;
//
//		/* ֤����������ȡ */
//		res = ArcSoft_FIC_IdCardDataFeatureExtraction(hEngine, &imgInfo1);
//		if (res != MOK)
//		{
//			printf("IdCard Feature Extraction failed, error code: %d\n", res);
//			return -1;
//		}
//
//		/* ��֤�ȶ� */
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
//		/* ����ʼ������ */
//		res = ArcSoft_FIC_UninitialEngine(hEngine);
//		if (res != MOK)
//		{
//			printf("Uninitial Engine failed, error code: %d\n", res);
//			return -1;
//		}
//		printf("the presult is %d", pResult);
//	}
//	//cvReleaseImage(&img0);		//videoģʽ�������compare�ӿ�֮ǰͼ�����ݱ�
//						//�ͷſ��ܻᵼ�±ȶ�ʧ�ܻ�carsh��
//
//	//cvReleaseImage(&img1);
//	return 0;
//}
