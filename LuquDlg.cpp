// LuquDlg.cpp : implementation file
//

#include "stdafx.h"
#include "研究生初试录取系统.h"
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
	//CFileDialog dlg (TRUE, "ifo", "", OFN_OVERWRITEPROMPT, "学生信息(*.ifo) | *.ifo | 所有文件(*.*) | *.* ||");
	if (IDCANCEL == dlg.DoModal()) {
		return;
	}
	CString filename = dlg.GetPathName();
	CFile file;
	if (!file.Open(filename, CFile::modeRead | CFile::shareDenyNone)) {
		AfxMessageBox("打开文件失败！");
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
	//这是获取操纵list控件IDC_LIDT1的指针
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST1);
	//插入一个列，学号，左对齐，宽度为100，之后一次类推，就是list控件里面的标题栏
	pList ->InsertColumn(0, "考号", LVCFMT_LEFT, 100);
	pList ->InsertColumn(1, "姓名", LVCFMT_LEFT, 100);
	pList ->InsertColumn(2, "专业", LVCFMT_LEFT, 100);
	pList ->InsertColumn(3, "数学", LVCFMT_LEFT, 100);
	pList ->InsertColumn(4, "政治", LVCFMT_LEFT, 100);
	pList ->InsertColumn(5, "英语", LVCFMT_LEFT, 100);
	pList ->InsertColumn(6, "专业课", LVCFMT_LEFT, 100);
	pList ->InsertColumn(7, "总分", LVCFMT_LEFT, 100);
	pList ->InsertColumn(8, "是否录取", LVCFMT_LEFT, 100);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
	//int a = atoi (pList ->GetItemText(i, 7));
}
void CLuquDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	//获取；List指针
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST1);
		//获得list控件里面的总行数
	int line = pList ->GetItemCount();
	for(int i = 0; i < line; i++)
	{
		int s;
		CString str;
		//j将总分转化成整数型
		s = atoi (pList ->GetItemText(i, 7));
		//取出录取分数线
	//	GetDlgItem(IDC_EDIT1)->GetWindowText(str);
	//	itoa(S, str, 10);
		int nEdit = 0;  
        nEdit = GetDlgItemInt(IDC_EDIT1); 
		
		if(s >= nEdit)
		{
			char a[8] = "是";
			pList ->SetItemText(i, 8, a);
		}
		else
		{
			char b[8] = "否";
			pList ->SetItemText(i, 8, b);
		}
	}


}
