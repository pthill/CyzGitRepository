#ifndef GAME_FRAME_APP_HEAD_FILE
#define GAME_FRAME_APP_HEAD_FILE

#pragma once

#include "GameFrameWnd.h"
#include "GameFrameView.h"
#include "GameFrameEngine.h"
#include "GameFrameAvatar.h"
#include "GameFrameService.h"
#include "GameFrameHead.h"

//�����ļ�
#include "Other\\IDispimp.h"
#include "Other\\Custsite.h"

//////////////////////////////////////////////////////////////////////////////////

//Ӧ�ó���
class GAME_FRAME_CLASS CGameFrameApp : public CWinApp
{
	//��������
public:
	CImpIDispatch *					m_pIDispatch;						//�Զ��ӿ�
	CCustomOccManager *				m_pCustomOccManager;				//��������

	//��������
protected:
	CGameFrameWnd *					m_pGameFrameWnd;					//��ܴ���
	CGameFrameEngine *				m_pGameFrameEngine;					//�������

	//��Ϸ����
protected:
//	CD3DSound						m_D3DSound;							//��������
	CGameFrameAvatar				m_GameFrameAvatar;					//ͷ�����
	CGameFrameService				m_GameFrameService;					//��ܷ���
	//CVideoServiceManager			m_VideoServiceManager;				//��Ƶ���
	CBassSound						m_BassSound;						//��������

	//��������
public:
	//���캯��
	CGameFrameApp();
	//��������
	virtual ~CGameFrameApp();

	//���غ���
public:
	//���ú���
	virtual BOOL InitInstance();
	//�˳�����
	virtual BOOL ExitInstance();

	//�̳к���
public:
	//�������
	virtual CGameFrameWnd * GetGameFrameWnd();
	//��������
	virtual CGameFrameEngine * GetGameFrameEngine(DWORD dwSDKVersion)=NULL;

	DECLARE_MESSAGE_MAP()
};

//////////////////////////////////////////////////////////////////////////////////


#endif