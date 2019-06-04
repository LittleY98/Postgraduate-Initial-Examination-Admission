// InfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "�о�������¼ȡϵͳ.h"
#include "InfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInfoDlg dialog

struct SInfo {
	char examid[20];
	char user[20];
	char zy[20];
	char math[20];
	char zz[20];
	char english[20];
	char zyk[20];
	char zf[20];
};



CInfoDlg::CInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInfoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInfoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CInfoDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnDaoRu)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInfoDlg message handlers

BOOL CInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	//���ǻ�ȡ����list�ؼ�IDC_LIDT1��ָ��
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST1);
	//����һ���У�ѧ�ţ�����룬���Ϊ100��֮��һ�����ƣ�����list�ؼ�����ı�����
	pList ->InsertColumn(0, "����", LVCFMT_LEFT, 150);
	pList ->InsertColumn(1, "����", LVCFMT_LEFT, 100);
	pList ->InsertColumn(2, "רҵ", LVCFMT_LEFT, 100);
	pList ->InsertColumn(3, "��ѧ", LVCFMT_LEFT, 100);
	pList ->InsertColumn(4, "����", LVCFMT_LEFT, 100);
	pList ->InsertColumn(5, "Ӣ��", LVCFMT_LEFT, 100);
	pList ->InsertColumn(6, "רҵ��", LVCFMT_LEFT, 100);
	pList ->InsertColumn(7, "�ܷ�", LVCFMT_LEFT, 100);


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CInfoDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
		//���ǻ�ȡ����list�ؼ�IDC_LIST1��ָ��
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST1);
	int nCount = pList ->GetItemCount();
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	pList ->InsertItem(nCount, str);

	GetDlgItemText(IDC_EDIT2, str);
	pList ->SetItemText(nCount, 1, str);

	GetDlgItemText(IDC_EDIT3, str);
	pList ->SetItemText(nCount, 2, str);

	GetDlgItemText(IDC_EDIT4, str);
	pList ->SetItemText(nCount, 3, str);

	GetDlgItemText(IDC_EDIT5, str);
	pList ->SetItemText(nCount, 4, str);

	GetDlgItemText(IDC_EDIT6, str);
	pList ->SetItemText(nCount, 5, str);

	GetDlgItemText(IDC_EDIT7, str);
	pList ->SetItemText(nCount, 6, str);
}

void CInfoDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST1);
	POSITION pos = pList ->GetFirstSelectedItemPosition();
	int nSel = pList ->GetNextSelectedItem(pos);
	if(nSel < 0)
		AfxMessageBox("��ѡ��Ҫȷ���޸ĵ��", MB_OK);
		else
		{
			if(AfxMessageBox("ȷ���޸ģ�",MB_YESNO) == IDYES){
				CString str;
				GetDlgItemText(IDC_EDIT1, str);
				pList ->SetItemText(nSel, 0, str);
				GetDlgItemText(IDC_EDIT2, str);
				pList ->SetItemText(nSel, 1, str);
				GetDlgItemText(IDC_EDIT3, str);
				pList ->SetItemText(nSel, 2, str);
				GetDlgItemText(IDC_EDIT4, str);
				pList ->SetItemText(nSel, 3, str);
				GetDlgItemText(IDC_EDIT5, str);
				pList ->SetItemText(nSel, 4, str);
				GetDlgItemText(IDC_EDIT6, str);
				pList ->SetItemText(nSel, 5, str);
				GetDlgItemText(IDC_EDIT7, str);
				pList ->SetItemText(nSel, 6, str);
			}
		}	
}

void CInfoDlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST1);
	POSITION pos = pList ->GetFirstSelectedItemPosition();
	int nSel = pList ->GetNextSelectedItem(pos);
	if(nSel < 0)
		AfxMessageBox("��ѡ��Ҫɾ�����", MB_OK);
		else
		{
			if(AfxMessageBox("ȷ��ɾ��: \n����Ϊ:" + pList->GetItemText(nSel, 0) + "\n����Ϊ:" + pList->GetItemText(nSel, 1) + 
				"\nרҵΪ��" + pList->GetItemText(nSel, 2) + "\n��ѧΪ:" + pList->GetItemText(nSel, 3) + "\n����Ϊ:" + pList->GetItemText(nSel, 4) + 
				"\nӢ��Ϊ:" + pList->GetItemText(nSel, 5) + "\nרҵ��Ϊ:" + pList->GetItemText(nSel, 6) + "\n��ѧ����?", MB_YESNO) == IDYES)
				pList->DeleteItem(nSel);
		}		
}

void CInfoDlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	//ָ��
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST1);
	//���list�ؼ������������
	int line = pList ->GetItemCount();
	//����ɼ�
	for (int i = 0; i < line; i++) {
		//�Ƚ�list�ؼ��гɼ���������ȡ������ת����int��
		int shuxue = atoi (pList ->GetItemText(i, 3));
		int zhengzhi = atoi (pList ->GetItemText(i, 4));
		int yingyu = atoi (pList ->GetItemText(i, 5));
		int zhuanyeke = atoi (pList ->GetItemText(i, 6));
		//������ܳɼ���ƽ���ɼ�
		int num = shuxue + zhengzhi + yingyu + zhuanyeke;
		//���������int���ܳɼ���ƽ���ɼ�ת����string��

		char a[8];
		itoa(num, a, 10);
		//��ת��string��num�� д��list�ؼ���
		pList ->SetItemText(i, 7, a);
		shuxue = 0; zhengzhi = 0; yingyu = 0, zhuanyeke = 0;
	}
}

void CInfoDlg::OnButton8() 
{
	// TODO: Add your control notification handler code here
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST1);
	CFileDialog dlg(FALSE, "", "",  OFN_OVERWRITEPROMPT, "*.txt ||");
	if (IDCANCEL == dlg.DoModal()) {
		return;
	}
	//��ǰ��Ŀ¼��һ��user.dat�ļ���û���򴴽�
	CString filename = dlg.GetPathName();
	CFile file;
	if (!file.Open(filename, CFile::modeCreate | CFile::modeWrite)) {
		AfxMessageBox("���ļ�ʧ�ܣ�");
		return;
	}
	SInfo info;
	int nCount = pList ->GetItemCount();
	for (int i = 0; i < nCount; i++) {
		pList ->GetItemText(i, 0, info.examid, sizeof (info.examid));
		pList ->GetItemText(i, 1, info.user, sizeof (info.user));
		pList ->GetItemText(i, 2, info.zy, sizeof (info.zy));
		pList ->GetItemText(i, 3, info.math, sizeof (info.math));
		pList ->GetItemText(i, 4, info.zz, sizeof (info.zz));
		pList ->GetItemText(i, 5, info.english, sizeof (info.english));
		pList ->GetItemText(i, 6, info.zyk, sizeof (info.zyk));
		pList ->GetItemText(i, 7, info.zf, sizeof (info.zf));
		file.Write(&info, sizeof(info));
	}
	file.Close();
}

void CInfoDlg::OnDaoRu() 
{
	// TODO: Add your control notification handler code here
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST1);
	CFileDialog dlg(TRUE, "", "", OFN_HIDEREADONLY, "*.txt ||");
	//CFileDialog dlg (TRUE, "ifo", "", OFN_OVERWRITEPROMPT, "ѧ����Ϣ(*.ifo) | *.ifo | �����ļ�(*.*) | *.* ||");
	if (IDCANCEL == dlg.DoModal()) {
		return;
	}
	CString filename = dlg.GetPathName();
	CFile file;
	if (!file.Open(filename, CFile::modeRead | CFile::shareDenyNone)) {
		AfxMessageBox("���ļ�ʧ�ܣ�");
		return;
	}
	pList ->DeleteAllItems();
	SInfo info;
	CString str;
	for (int i = 0; file.Read(&info, sizeof(info)) == sizeof(info); i++) {
		pList ->InsertItem(i, info.examid);
		pList ->SetItemText(i, 1, info.user);
		
		pList ->SetItemText(i, 2, info.zy);
		pList ->SetItemText(i, 3, info.math);
		
		pList ->SetItemText(i, 4, info.zz);
		pList ->SetItemText(i, 5, info.english);
		pList ->SetItemText(i, 6, info.zyk);
		pList ->SetItemText(i, 7, info.zf);
	}
	file.Close();
}
