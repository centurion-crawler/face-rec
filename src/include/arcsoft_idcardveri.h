/*******************************************************************************
* Copyright(c) ArcSoft, All right reserved.
*
* This file is ArcSoft's property. It contains ArcSoft's trade secret, proprietary
* and confidential information.
*
* DO NOT DISTRIBUTE, DO NOT DUPLICATE OR TRANSMIT IN ANY FORM WITHOUT PROPER
* AUTHORIZATION.
*
* If you are not an intended recipient of this file, you must not copy,
* distribute, modify, or take any action in reliance on it.
*
* If you have received this file in error, please immediately notify ArcSoft and
* permanently delete the original and any copy of any file and any printout
* thereof.
*********************************************************************************/

#ifndef _ARCSOFT_SDK_FIC_H_
#define _ARCSOFT_SDK_FIC_H_

#include "amcomdef.h"
#include "asvloffscreen.h"

#ifdef __cplusplus
extern "C" {
#endif

	/*******************************************************************************************
	* FIC �汾��Ϣ
	*******************************************************************************************/
	typedef struct {
		MPChar Version;									// Version in string form
		MPChar BuildDate;									// Latest build Date
		MPChar CopyRight;									// Copyright
	}AFIC_FSDK_VERSION;

	/*******************************************************************************************
	* FIC FT/FD�����������
	*******************************************************************************************/
	typedef struct {
		MInt32 nFace;                        // number of faces detected
		MRECT rcFace;                        // The bounding box of face
	} AFIC_FSDK_FACERES, *LPAFIC_FSDK_FACERES;


	/************************************************************************
	* ����SDK
	************************************************************************/

	MRESULT ArcSoft_FIC_Activate(
		MPChar APPID,										// [in] APPID
		MPChar SDKKEY 									// [in] SDKKEY
		);

	/************************************************************************
	* ��ʼ������
	************************************************************************/
	MRESULT	ArcSoft_FIC_InitialEngine(
		MHandle	* phFICEngine								// [out] FIC ����Handle��ָ��
		);

	/************************************************************************
	* ����������ȡ
	************************************************************************/
	MRESULT ArcSoft_FIC_FaceDataFeatureExtraction(
		MHandle hFICEngine,								// [in]  FIC ����Handle
		MBool isVideo, 									// [in]  ������������ 1-��Ƶ 0-��̬ͼƬ
		LPASVLOFFSCREEN pInputFaceData,					// [in]  ����ͼ��ԭʼ����
		LPAFIC_FSDK_FACERES pFaceRes						// [out] �������� ������/������/�Ƕ�
		);

	/************************************************************************
	* ֤����������ȡ
	************************************************************************/
	MRESULT ArcSoft_FIC_IdCardDataFeatureExtraction(
		MHandle hFICEngine,                					// [in]  FIC ����Handle
		LPASVLOFFSCREEN pInputIdcardData      					// [in]  ͼ��ԭʼ����
		);

	/************************************************************************
	* ��֤�ȶ�
	************************************************************************/
	MRESULT ArcSoft_FIC_FaceIdCardCompare(
		MHandle hFICEngine,                				// [in]  FIC ����Handle
		MFloat threshold,									// [in]  �ȶ���ֵ
		MFloat * pSimilarScore,							// [out] �ȶԽ�����ƶ�
		MInt32 * pResult									// [out] �ȶԽ��
		);

	/************************************************************************
	* �ͷ�����
	************************************************************************/
	MRESULT ArcSoft_FIC_UninitialEngine(
		MHandle hFICEngine           						// [in]  FIC ����Handle
		);

	/************************************************************************
	* ��ȡ�汾��Ϣ
	************************************************************************/
	const AFIC_FSDK_VERSION *ArcSoft_FIC_GetVersion(MHandle hFICEngine);

#ifdef __cplusplus
}
#endif
#endif