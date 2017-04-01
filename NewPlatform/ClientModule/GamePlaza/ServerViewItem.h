#ifndef SERVER_VIEW_ITEM_HEAD_FILE
#define SERVER_VIEW_ITEM_HEAD_FILE

#pragma once

#include "Stdafx.h"
#include "DlgStatus.h"
#include "DlgWhisper.h"
#include "ServerListData.h"
#include "ProcessManager.h"
#include "DlgSearchTable.h"
#include "TableViewFrame.h"
#include "DlgServerManager.h"
#include "PlatformPublicize.h"
#include "ChatHistory.h"
#include "DlgManageUser.h"
#include "UserInfoDlg.h"

//////////////////////////////////////////////////////////////////////////

//��Ϊ����
#define WM_ADD_FRIEND				(WM_USER+400)						//��Ϊ����
#define WM_SET_DETEST				(WM_USER+401)						//��Ϊ���

//////////////////////////////////////////////////////////////////////////////////

//����״̬
enum enServiceStatus
{
	ServiceStatus_Unknow,			//δ֪״̬
	ServiceStatus_Entering,			//����״̬
	ServiceStatus_Validate,			//��֤״̬
	ServiceStatus_RecvInfo,			//��ȡ״̬
	ServiceStatus_ServiceIng,		//����״̬
	ServiceStatus_NetworkDown,		//�ж�״̬
};

//��������
struct tagSearchTable
{
	bool							bOneNull;							//һ����λ
	bool							bTwoNull;							//������λ
	bool							bAllNull;							//ȫ��λ��
	bool							bNotFull;							//��ȫ��λ
	bool							bFilterPass;						//��������
	WORD							wStartTableID;						//��ʼ����
	WORD							wResultTableID;						//�������
	WORD							wResultChairID;						//�������
};

//�û�����
typedef CWHArray<IClientUserItem *> CClientUserItemArray;

//////////////////////////////////////////////////////////////////////////////////

//��Ϸ����
class CServerViewItem : public CDialog, public IServerViewItem, public ITCPSocketSink, public ISplitterEvent,
	public ITableViewFrameSink, public IUserManagerSink, public IProcessManagerSink, public IExpressionSink,
	public IChatControlSink, public IGamePropertySink, public IStatusViewSink, public IFlashControlSink,public
	IGamePropertyUseSink
{
	//�������
protected:
	bool							m_bCreateFlag;						//������־
	bool							m_bRectifyHor;						//������־
	bool							m_bRectifyVor;						//������־
	bool							m_bHideUserList;					//���ر�־

	//��������
protected:
	WORD							m_wReqTableID;						//��������
	WORD							m_wReqChairID;						//����λ��
	WORD							m_wFindTableID;						//��������

	//�������
protected:
	DWORD							m_dwChatTime;						//����ʱ��
	CString							m_strChatString;					//������Ϣ

	//�û�����
protected:
	DWORD							m_dwUserRight;						//�û�Ȩ��
	DWORD							m_dwMasterRight;					//����Ȩ��
	IClientUserItem *				m_pIMySelfUserItem;					//�Լ�ָ��

	//��������
protected:
	WORD							m_wServerType;						//��������
	DWORD							m_dwServerRule;						//�������
	enServiceStatus					m_ServiceStatus;					//����״̬
	WORD							m_wAVServerPort;					//��Ƶ�˿�
	DWORD							m_dwAVServerAddr;					//��Ƶ��ַ

	//������Ϣ
protected:
	BYTE							m_cbColumnCount;					//�б���Ŀ
	BYTE							m_cbPropertyCount;					//������Ŀ
	tagColumnItem					m_ColumnItem[MAX_COLUMN];			//�б�����
	tagPropertyInfo					m_PropertyInfo[MAX_PROPERTY];		//��������

	//��������
protected:
	tagGameKind						m_GameKind;							//������Ϣ
	tagGameServer					m_GameServer;						//������Ϣ

	//���ò���
protected:
	CParameterGame *				m_pParameterGame;					//��Ϸ����
	CParameterServer *				m_pParameterServer;					//��������

	//�������
protected:
	CClientUserItemArray			m_MenuUserItemArray;				//�û�����

	//�������
protected:
	CDlgStatus						m_DlgStatus;						//״̬����
	CFlashControl					m_FlashControl;						//�����ؼ�
	CProcessManager					m_ProcessManager;					//���̹���
	CDlgWhisperItemArray			m_DlgWhisperItemArray;				//˽������
	CChatHistoryManager				m_ChatHistoryManager;				//�����¼����

	//�ؼ�����
protected:
	CDlgSearchTable *				m_pDlgSearchTable;					//��������
	CDlgInsureServer *				m_pDlgInsureServer;					//���ж���
	CDlgServerManager *				m_pDlgServerManager;				//��������
	CExpressionControl *			m_pExpressionControl;				//���鴰��
	CDlgTrumpetItem *               m_pTrumpetItem;                     //���ȴ��� 
	CUserInfoDlg                    m_UserInfoDlg;

	//�������
protected:
	CTCPSocketHelper				m_TCPSocketModule;					//��������
	CGameLevelParserHelper			m_GameLevelParserModule;			//��Ϸ�ȼ�
	CPlazaUserManagerHelper			m_PlazaUserManagerModule;			//�û�����

	//�������
public:
//	CSkinButton						m_btControl;						//���ư�ť
	CToolTipCtrl					m_ToolTipCtrl;						//��ʾ�ؼ�

	// iii����֧���϶�
//	CSkinSplitter					m_VorSplitter;						//��ֿؼ�
//	CSkinSplitter					m_HorSplitter;						//��ֿؼ�
	CWndChatControl					m_ChatControl;						//�������
	CUserListControl				m_UserListControl;					//�û��б�
	CGamePropertyCtrl				m_GamePropertyCtrl;					//��Ϸ����
	CPlatformPublicize				m_PlatformPublicize;				//����ؼ�

	//��Ϸ����
public:
	CSkinButton						m_btQuitServer;						//�뿪����
	CSkinButton						m_btTableButton1;					//[����]��ť
	CSkinButton						m_btTableButton2;					//���Ӱ�ť
	CSkinButton						m_btTableButton3;					//���Ӱ�ť
	CSkinButton						m_btTableButton4;					//[����]��ť
	CSkinButton						m_btTableButton5;					//���Ӱ�ť
	CSkinButton						m_btTableButton6;					//[��Ϸ����]��ť
	CTableViewFrame					m_TableViewFrame;					//���ӿ��

	//����ؼ�
public:
	CSkinEditEx						m_ChatEdit;							//��������
	CSkinButton						m_btSendChat;						//��������
	CSkinButton						m_btChatShort;						//�������
	CRichEditMessage				m_ChatMessage;						//������Ϣ

	//���찴ť
public:
	CSkinButton						m_btChatButton1;					//���찴ť
	CSkinButton						m_btChatButton2;					//���찴ť
	CSkinButton						m_btChatButton3;					//���찴ť
	CSkinButton						m_btChatButton4;					//���찴ť

	//��Դ����
protected:
	CEncircleBMP					m_ChatEncircle;						//������Դ
	CEncircleBMP					m_TableEncircle;					//������Դ
	CEncircleBMP					m_UserListEncircle;					//�û���Դ
	CPen							m_PenLine;							//����һ���ߵı�


	//�����ؼ�
public:
	//CDlgAndroid *					m_pDlgAndroid;						//��������
	CDlgManageUser *				m_pDlgManageUser;					//�û�����

	//��������
public:
	//���캯��
	CServerViewItem();
	//��������
	virtual ~CServerViewItem();

	//�����ӿ�
public:
	//�ͷŶ���
	virtual VOID Release() { delete this; }
	//�ӿڲ�ѯ
	virtual VOID * QueryInterface(REFGUID Guid, DWORD dwQueryVer);

	//���غ���
protected:
	//�ؼ���
	virtual VOID DoDataExchange(CDataExchange * pDX);
	//��Ϣ����
	virtual BOOL PreTranslateMessage(MSG * pMsg);
	//��������
	virtual BOOL OnInitDialog();
	//�����
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);

	//���ӽӿ�
public:
	//���˫��
	virtual VOID OnDButtonHitTable(WORD wTableID);
	//�������
	virtual VOID OnLButtonHitTable(WORD wTableID, WORD wChairID);
	//�Ҽ�����
	virtual VOID OnRButtonHitTable(WORD wTableID, WORD wChairID);
    virtual VOID OnMouseSetCursor(WORD wTableID, WORD wChairID,CPoint Point);
	//���Ӱ�ť
	virtual VOID OnHitTableButton(BYTE cbButton);

	//����ӿ�
protected:
	//�����¼�
	virtual bool OnEventTCPSocketLink(WORD wSocketID, INT nErrorCode);
	//�ر��¼�
	virtual bool OnEventTCPSocketShut(WORD wSocketID, BYTE cbShutReason);
	//��ȡ�¼�
	virtual bool OnEventTCPSocketRead(WORD wSocketID, TCP_Command Command, VOID * pData, WORD wDataSize);

	//���߽ӿ�
protected:
	//�������
	virtual VOID OnEventFlashFinish();
	//��ǰ���
	virtual bool OnEventBuyPropertyPrep(LPCTSTR pszNickName,WORD wPropertyIndex,LPTSTR pszMessage);
	//�������
	virtual bool OnEventBuyProperty(LPCTSTR pszNickName, WORD wItemCount, WORD wPropertyIndex);
	//��ѯ�û�
	virtual IClientUserItem * OnQueryClientUserItem() { return m_pIMySelfUserItem; };
	//ʹ�õ���
	virtual bool OnEventUseProperty(WORD wPropertyIndex);	


	//���̽ӿ�
public:
	//���̴���
	virtual bool OnGameProcessError();
	//���̹ر�
	virtual bool OnGameProcessClose(DWORD dwExitCode);
	//��������
	virtual bool OnGameProcessCreate(bool bAlreadyExist);
	//��������
	virtual bool OnProcessManagerData(WORD wMainCmdID, WORD wSubCmdID, VOID * pData, WORD wDataSize);

	//�û��ӿ�
public:
	//�û�����
	virtual VOID OnUserItemAcitve(IClientUserItem * pIClientUserItem);
	//�û�ɾ��
	virtual VOID OnUserItemDelete(IClientUserItem * pIClientUserItem);
	//�û�����
	virtual VOID OnUserFaceUpdate(IClientUserItem * pIClientUserItem);
	//�û�����
	virtual VOID OnUserItemUpdate(IClientUserItem * pIClientUserItem, tagUserScore & LastScore);
	//�û�����
	virtual VOID OnUserItemUpdate(IClientUserItem * pIClientUserItem, tagUserStatus & LastStatus);
	//�û�����
	virtual VOID OnUserItemUpdate(IClientUserItem * pIClientUserItem, tagUserAttrib & UserAttrib);

	//�¼��ӿ�
protected:
	//ȡ������
	virtual VOID OnStatusCancel();
	//����¼�
	virtual VOID OnSplitterEvent(UINT uControlID, INT nXPos, INT nYPos);
	//�û�ѡ��
	virtual VOID OnChangeChatTarget(IClientUserItem * pIClientUserItem);
	//�����¼�
	virtual VOID OnExpressionSelect(CExpression * pExpression, tagExpressionInfo * pExpressionInfo);

	//�˵��ӿ�
public:
	//��ʾ�˵�
	virtual VOID TrackUserItemMenu(IClientUserItem * pIClientUserItem);
	//��ʾ�˵�
	virtual VOID TrackUserItemMenu(IClientUserItem * pIClientUserItem[], WORD wUserCount);

	//��Ϣ����
public:
	//�����ʶ
	virtual WORD GetServerID() { return m_GameServer.wServerID; }
	//��������
	virtual WORD GetServerType() { return m_wServerType; }
	//�������
	virtual DWORD GetServerRule() { return m_dwServerRule; }
	//��������
	virtual LPCTSTR GetKindName() { return m_GameKind.szKindName; }
	//��������
	virtual LPCTSTR GetServerName() { return m_GameServer.szServerName; }
	//����״̬
	virtual enServiceStatus GetServiceStatus() { return m_ServiceStatus; }
	//��Ϸ����
	virtual CParameterGame * GetParameterGame() { return m_pParameterGame; }
	//��������
	virtual CParameterServer * GetParameterServer() { return m_pParameterServer; }

	//�������
public:
	//�������
	ITCPSocket * GetTCPSocket() { return m_TCPSocketModule.GetInterface(); }
	//�ȼ����
	IGameLevelParser * GetGameLevelParser() { return m_GameLevelParserModule.GetInterface(); }
	//�û����
	IPlazaUserManager * GetPlazaUserManager() { return m_PlazaUserManagerModule.GetInterface(); }

	//���ܺ���
public:
	//��ʾ����
	VOID ShowInsureView();
	//�ϰ��¼�
	VOID NotifyBossCome(bool bBossCome);
	//��������
	VOID SearchGameTable(tagSearchTable & SearchTable);
	//����ͷ��
	VOID UpdateUserCustomFace(DWORD dwUserID, DWORD dwCustomID, tagCustomFaceInfo & CustomFaceInfo);
	//��ѯ��Ϸ�ͻ���
	bool IsGameClientReady();
	//�Լ�״̬
	bool IsPlayingMySelf();

	//˽�ĺ���
public:
	//˽�ĻỰ
	VOID WhisperConversation(IClientUserItem * pIClientUserItem[], WORD wUserCount);
	//����˽��
	CDlgWhisper * CreateWhisperWnd(DWORD dwConversationID, DWORD dwUserID[], WORD wUserCount, bool bCreate);

	//�����¼�
protected:
	//�û�����
	bool OnSocketMainUser(WORD wSubCmdID, VOID * pData, WORD wDataSize);
	//��¼����
	bool OnSocketMainLogon(WORD wSubCmdID, VOID * pData, WORD wDataSize);
	//���ô���
	bool OnSocketMainConfig(WORD wSubCmdID, VOID * pData, WORD wDataSize);
	//״̬����
	bool OnSocketMainStatus(WORD wSubCmdID, VOID * pData, WORD wDataSize);
	//���д���
	bool OnSocketMainInsure(WORD wSubCmdID, VOID * pData, WORD wDataSize);
	//��������
	bool OnSocketMainManager(WORD wSubCmdID, VOID * pData, WORD wDataSize);
	//ϵͳ����
	bool OnSocketMainSystem(WORD wSubCmdID, VOID * pData, WORD wDataSize);
	//��Ϸ����
	bool OnSocketMainGameFrame(WORD wMainCmdID, WORD wSubCmdID, VOID * pData, WORD wDataSize);
	//��������
	bool OnSocketMainMatch(WORD wSubCmdID, VOID * pData, WORD wDataSize);

	//�����¼�
protected:
	//�û�����
	bool OnSocketSubUserEnter(VOID * pData, WORD wDataSize);
	//�û�����
	bool OnSocketSubUserScore(VOID * pData, WORD wDataSize);
	//�û�״̬
	bool OnSocketSubUserStatus(VOID * pData, WORD wDataSize);
	//��¼���
	bool OnSocketSubLogonFinish(VOID * pData, WORD wDataSize);
	//��¼�ɹ�
	bool OnSocketSubLogonSuccess(VOID * pData, WORD wDataSize);
	//��¼ʧ��
	bool OnSocketSubLogonFailure(VOID * pData, WORD wDataSize);
	//������ʾ
	bool OnSocketSubUpdateNotify(VOID * pData, WORD wDataSize);
	//����ʧ��
	bool OnSocketSubRequestFailure(VOID * pData, WORD wDataSize);
	//�û�����
	bool OnSocketSubUserChat(VOID * pData, WORD wDataSize);
	//�û�����
	bool OnSocketSubExpression(VOID * pData, WORD wDataSize);
	//�û�˽��
	bool OnSocketSubWisperUserChat(VOID * pData, WORD wDataSize);
	//˽�ı���
	bool OnSocketSubWisperExpression(VOID * pData, WORD wDataSize);
	//ϵͳ��Ϣ
	bool OnSocketSubSystemMessage(VOID * pData, WORD wDataSize);
	//������Ϣ
	bool OnSocketSubActionMessage(VOID * pData, WORD wDataSize);
	//�������
	bool OnSocketSubUserInvite(VOID * pData, WORD wDataSize);
	//���߳ɹ�
	bool OnSocketSubPropertySuccess(VOID * pData, WORD wDataSize);
	//����ʧ��
	bool OnSocketSubPropertyFailure(VOID * pData, WORD wDataSize);
	//����ЧӦ
	bool OnSocketSubPropertyEffect(VOID * pData, WORD wDataSize);
	//������Ϣ
	bool OnSocketPropertyMessage(VOID * pData, WORD wDataSize);
	//��������
	bool OnSocketPropertyTrumpet(VOID * pData, WORD wDataSize);
	//��������
	bool OnSocketSubMatchFee(VOID * pData, WORD wDataSize);
	//��������
	bool OnSocketSubMatchNum(VOID *pData, DWORD wDataSize);
	//�ȴ�����
	bool OnSocketSubWaitDistribute(VOID *pData, WORD wDataSize);

	//���溯��
public:
	//�����ؼ�
	VOID RectifyControl(INT nWidth, INT nHeight);
	//���÷���
	VOID InitServerViewItem(CGameServerItem * pGameServerItem,WORD wAVServerPort,DWORD dwAVServerAddr);
	//���ý���
	VOID InitServerViewCtrl(CSkinRenderManager * pSkinRenderManager);

	//��������
public:
	//���͵�¼
	bool SendLogonPacket();
	//���͹���
	bool SendUserRulePacket();
	//�����Թ�
	bool SendLookonPacket(WORD wTableID, WORD wChairID, LPCTSTR lpszPassword=NULL);
	//��������
	bool SendSitDownPacket(WORD wTableID, WORD wChairID, LPCTSTR lpszPassword=NULL);
	//��������
	bool SendStandUpPacket(WORD wTableID, WORD wChairID, BYTE cbForceLeave);
	//���ͱ���
	bool SendExpressionPacket(DWORD dwTargetUserID, WORD wItemIndex);
	//��������
	bool SendUserChatPacket(DWORD dwTargetUserID, LPCTSTR pszChatString, COLORREF crColor);

	//��������
public:
	//ִ���Թ�
	bool PerformLookonAction(WORD wTableID, WORD wChairID, bool bEfficacyPass);
	//ִ������
	bool PerformStandUpAction(WORD wTableID, WORD wChairID);
	//ִ������
	bool PerformSitDownAction(WORD wTableID, WORD wChairID, bool bEfficacyPass);
	//ִ�й���
	bool PerformBuyProperty(BYTE cbRequestArea,LPCTSTR pszNickName, WORD wItemCount, WORD wPropertyIndex);

	//��������
protected:
	//����״̬
	VOID SetServiceStatus(enServiceStatus ServiceStatus);
	//��ԴĿ¼
	VOID GetGameResDirectory(TCHAR szResDirectory[], WORD wBufferCount);

	//�ڲ�����
protected:
	//����Ч��
	bool EfficacyUserChat(LPCTSTR pszChatString, WORD wExpressionIndex);
	//����Ч��
	bool EfficacyTableRule(WORD wTableID, WORD wChairID, bool bReqLookon, CString & strDescribe);
	//���������˵�
	VOID CreateServerManagerMenu( CSkinMenu &ManageMenu );

	//��������
protected:
	//������ɫ
	VOID OnSelectMoreColor();
	//ѡ����ɫ
	VOID OnSelectChatColor(UINT nCommandID);
	//ѡ�����
	VOID OnSelectChatShort(UINT nCommandID);

	//��������
protected:
	//��ֹ�û���������
	VOID OnLimitUserRoomChat();
	//�����û���������
	VOID OnAllowUserRoomChat();
	//��ֹ�û���Ϸ����
	VOID OnLimitUserGameChat();
	//�����û���Ϸ����
	VOID OnAllowUserGameChat();
	//��ֹ�û�˽��
	VOID OnLimitUserWhispChat();
	//�����û�˽��
	VOID OnAllowUserWhispChat();

	//��������
protected:
	//������ť
	VOID OnBnClickedServerManage();
	//�������
	VOID OnManageServer();
	//�û�����
	VOID OnManageUser();
	//ϵͳ��Ϣ����
	VOID OnManageSystemMsg();
	//���ӹ������
	VOID OnManageTableRule();
	//�����˹���
	VOID OnManageUserAndior();

	//��Ϣ����
protected:
	//������Ϣ
	VOID OnNcDestroy();
	//�滭����
	BOOL OnEraseBkgnd(CDC * pDC);
	//λ����Ϣ
	VOID OnSize(UINT nType, INT cx, INT cy);

	//�ؼ���Ϣ
protected:
	//�Ҽ��б�
	VOID OnNMRclickUserList(NMHDR * pNMHDR, LRESULT * pResult);
	//˫���б�
	VOID OnNMDblclkUserList(NMHDR * pNMHDR, LRESULT * pResult);
	//˫���б�
	VOID OnNMClickUserList(NMHDR * pNMHDR, LRESULT * pResult);
	//��Ϊ����
	LRESULT OnWhisperAddFriend(WPARAM wParam, LPARAM lPara);
	//��Ϊ���
	LRESULT OnWhisperSetDetest(WPARAM wParam, LPARAM lPara);

	DECLARE_MESSAGE_MAP()

	//�ڲ�����
protected:
	//���Ŷ�������
	bool PlayChatShortSound(BYTE cbGender, BYTE cbIndex);
	//��ö����±�
	BYTE GetChatShortIndex(LPCTSTR pChat);
};

//////////////////////////////////////////////////////////////////////////////////

#endif