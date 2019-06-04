// LuquDlg.cpp : implementation file
//

#include "stdafx.h"
#include "�о�������¼ȡϵͳ.h"
#include "LuquDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLuquDlg dialog
struct SInfo1 {
	char examid[20];
	char user[20];
	char zy[20];
	char math[20];
	char zz[20];
	char english[20];
	char zyk[20];
	char zf[20];
};

CLuquDlg::CLuquDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLuquDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLuquDlg)
	m_EDIT = 0;
	//}}AFX_DATA_INIT
}


void CLuquDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLuquDlg)
	DDX_Text(pDX, IDC_EDIT1, m_EDIT);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLuquDlg, CDialog)
	//{{AFX_MSG_MAP(CLuquDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLuquDlg message handlers

void CLuquDlg::OnButton1() 
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
	SInfo1 info;
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

BOOL CLuquDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//���ǻ�ȡ����list�ؼ�IDC_LIDT1��ָ��
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST1);
	//����һ���У�ѧ�ţ�����룬���Ϊ100��֮��һ�����ƣ�����list�ؼ�����ı�����
	pList ->InsertColumn(0, "����", LVCFMT_LEFT, 100);
	pList ->InsertColumn(1, "����", LVCFMT_LEFT, 100);
	pList ->InsertColumn(2, "רҵ", LVCFMT_LEFT, 100);
	pList ->InsertColumn(3, "��ѧ", LVCFMT_LEFT, 100);
	pList ->InsertColumn(4, "����", LVCFMT_LEFT, 100);
	pList ->InsertColumn(5, "Ӣ��", LVCFMT_LEFT, 100);
	pList ->InsertColumn(6, "רҵ��", LVCFMT_LEFT, 100);
	pList ->InsertColumn(7, "�ܷ�", LVCFMT_LEFT, 100);
	pList ->InsertColumn(8, "�Ƿ�¼ȡ", LVCFMT_LEFT, 100);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
	//int a = atoi (pList ->GetItemText(i, 7));
}
void CLuquDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	//��ȡ��Listָ��
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST1);
		//���list�ؼ������������
	int line = pList ->GetItemCount();
	for(int i = 0; i < line; i++)
	{
		int s;
		CString str;
		//j���ܷ�ת����������
		s = atoi (pList ->GetItemText(i, 7));
		//ȡ��¼ȡ������
	//	GetDlgItem(IDC_EDIT1)->GetWindowText(str);
	//	itoa(S, str, 10);
		int nEdit = 0;  
        nEdit = GetDlgItemInt(IDC_EDIT1); 
		
		if(s >= nEdit)
		{
			char a[8] = "��";
			pList ->SetItemText(i, 8, a);
		}
		else
		{
			char b[8] = "��";
			pList ->SetItemText(i, 8, b);
		}
	}


}
