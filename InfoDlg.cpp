// InfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "研究生初试录取系统.h"
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
	
	//这是获取操纵list控件IDC_LIDT1的指针
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST1);
	//插入一个列，学号，左对齐，宽度为100，之后一次类推，就是list控件里面的标题栏
	pList ->InsertColumn(0, "考号", LVCFMT_LEFT, 150);
	pList ->InsertColumn(1, "姓名", LVCFMT_LEFT, 100);
	pList ->InsertColumn(2, "专业", LVCFMT_LEFT, 100);
	pList ->InsertColumn(3, "数学", LVCFMT_LEFT, 100);
	pList ->InsertColumn(4, "政治", LVCFMT_LEFT, 100);
	pList ->InsertColumn(5, "英语", LVCFMT_LEFT, 100);
	pList ->InsertColumn(6, "专业课", LVCFMT_LEFT, 100);
	pList ->InsertColumn(7, "总分", LVCFMT_LEFT, 100);


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CInfoDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
		//这是获取操纵list控件IDC_LIST1的指针
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
		AfxMessageBox("请选中要确认修改的项！", MB_OK);
		else
		{
			if(AfxMessageBox("确认修改？",MB_YESNO) == IDYES){
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
		AfxMessageBox("请选中要删除的项！", MB_OK);
		else
		{
			if(AfxMessageBox("确认删除: \n考号为:" + pList->GetItemText(nSel, 0) + "\n姓名为:" + pList->GetItemText(nSel, 1) + 
				"\n专业为：" + pList->GetItemText(nSel, 2) + "\n数学为:" + pList->GetItemText(nSel, 3) + "\n政治为:" + pList->GetItemText(nSel, 4) + 
				"\n英语为:" + pList->GetItemText(nSel, 5) + "\n专业课为:" + pList->GetItemText(nSel, 6) + "\n的学生吗?", MB_YESNO) == IDYES)
				pList->DeleteItem(nSel);
		}		
}

void CInfoDlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	//指针
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST1);
	//获得list控件里面的总行数
	int line = pList ->GetItemCount();
	//计算成绩
	for (int i = 0; i < line; i++) {
		//先将list控件中成绩的数据提取出来并转换成int型
		int shuxue = atoi (pList ->GetItemText(i, 3));
		int zhengzhi = atoi (pList ->GetItemText(i, 4));
		int yingyu = atoi (pList ->GetItemText(i, 5));
		int zhuanyeke = atoi (pList ->GetItemText(i, 6));
		//计算出总成绩和平均成绩
		int num = shuxue + zhengzhi + yingyu + zhuanyeke;
		//将计算出的int型总成绩和平均成绩转换成string型

		char a[8];
		itoa(num, a, 10);
		//将转成string的num， 写进list控件中
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
	//当前打开目录的一个user.dat文件，没有则创建
	CString filename = dlg.GetPathName();
	CFile file;
	if (!file.Open(filename, CFile::modeCreate | CFile::modeWrite)) {
		AfxMessageBox("打开文件失败！");
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
