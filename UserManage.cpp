// UserManage.cpp : implementation file
//

#include "stdafx.h"
#include "研究生初试录取系统.h"
#include "UserManage.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserManage dialog


CUserManage::CUserManage(CWnd* pParent /*=NULL*/)
	: CDialog(CUserManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserManage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CUserManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserManage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserManage, CDialog)
	//{{AFX_MSG_MAP(CUserManage)
	ON_BN_CLICKED(IDC_BUTTON1, OnInsert)
	ON_BN_CLICKED(IDC_BUTTON2, OnDelete)
	ON_BN_CLICKED(IDC_BUTTON3, OnUpDate)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_BUTTON4, OnBaoCun)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserManage message handlers

void CUserManage::OnInsert() 
{
	// TODO: Add your control notification handler code here

	CString userName, pwd;
	GetDlgItemText(IDC_EDIT1, userName);
	GetDlgItemText(IDC_EDIT2, pwd);

	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST1);
	pList->InsertItem(0,userName);
	pList->SetItemText(0,1,pwd);

	SetDlgItemText(IDC_EDIT1,"");
	SetDlgItemText(IDC_EDIT2,""); 	
}

void CUserManage::OnDelete() 
{
	// TODO: Add your control notification handler code here
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST1);
	POSITION pos=pList->GetFirstSelectedItemPosition();  
    int nSel=pList->GetNextSelectedItem(pos);

	if (nSel < 0) {//小于0表示没有选中
		AfxMessageBox("请选中要选择的项！", MB_OK);
	} else {
		if(AfxMessageBox("确认删除？",MB_YESNO)==IDYES){  
			pList->DeleteItem(nSel);//将选中的那一行里面的所有数据全部清零
        }  
	}	
	
}

void CUserManage::OnUpDate() 
{
	// TODO: Add your control notification handler code here
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST1);
	POSITION pos=pList->GetFirstSelectedItemPosition();  
    int nSel=pList->GetNextSelectedItem(pos);
	
	  
	
	
    if(nSel<0)  
        //没有选到任何东西，就弹窗，AfxMessageBox是MFC中的函数，同样可以使用Win32的MessageBox弹窗，  
        //这里仅有两个参数，不能想MessageBox那样设置弹窗的标题，默认为我们的工程名，但好处是不用写句柄是谁  
        AfxMessageBox("请选中要修改的项！",MB_OK);  
    else{  
        //选择东西，弹出窗选择用户，AfxMessageBox得到IDYES的值，也就是用户按“是”才进行下面的修改代码  
        if(AfxMessageBox("确认修改？",MB_YESNO)==IDYES){  
			CString str;        
            GetDlgItemText(IDC_EDIT1,str);  
            //把现时IDC_EDIT1也就是“学号”编辑框的值替换掉选择那行的第0项，然后如此类推，这就完成修改  
            pList->SetItemText(nSel,0,str);
			
            GetDlgItemText(IDC_EDIT2,str);  
            pList->SetItemText(nSel,1,str);
			
         
			

			
	SetDlgItemText(IDC_EDIT1,""); 
	SetDlgItemText(IDC_EDIT2,""); 
	
			
        }  
    }  		
	
}

BOOL CUserManage::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	//这是获取操纵list控件IDC_LIDT1的指针
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST1);
	//插入一个列，学号，左对齐，宽度为100，之后一次类推，就是list控件里面的标题栏
	pList ->InsertColumn(0, "账号", LVCFMT_LEFT, 150);
	pList ->InsertColumn(1, "姓名", LVCFMT_LEFT, 100);
	

	//CListCtrl *pList=(CListCtrl *)GetDlgItem(IDC_LIST1);  
	CString temp1, temp2;
	string a="user.txt";
	ifstream infile(a.data());
	if(!infile){
		MessageBox("您没有保存过信息","Error",MB_ICONERROR | MB_OKCANCEL);
		return false;
	}	
	string n,p;

	infile >>n>>p;

	while(n != ""){	
	temp1=n.c_str();
	temp2=p.c_str();
	int nCurItem = pList->InsertItem(0,temp1);
	pList->SetItemText(nCurItem,1,temp2);

	infile >>n>>p;
	}

    infile.close(); 
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CUserManage::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here

	//这是获取操纵List控件IDC_LIST1的指针  
    CListCtrl *pList=(CListCtrl *)GetDlgItem(IDC_LIST1);  
    //这里是获取选择的位置，如果没有任何选择，这两行的函数最后求出来的nSel为-1，如果选择了，则nSel为现在选择的行数  
    POSITION pos=pList->GetFirstSelectedItemPosition();  
    int nSel=pList->GetNextSelectedItem(pos);
	
	
    
			
			CString str1,str2; //设置一个临时字符串变量
    
	
			str1 = pList->GetItemText(nSel,0); //第一个变量为行号，第二个变量为临时字符串变量
			str2 = pList->GetItemText(nSel,1);//第一个变量为行号，第二个位置为列号，第三个变量为临时字符串变量
	
			
			SetDlgItemText(IDC_EDIT1,str1);
			SetDlgItemText(IDC_EDIT2,str2); 
	*pResult = 0;
}

void CUserManage::OnBaoCun() 
{
	// TODO: Add your control notification handler code here
	string s;
	 CListCtrl *pList=(CListCtrl *)GetDlgItem(IDC_LIST1);  
	fstream outfile("user.txt",ios::out);
	int Count = pList->GetItemCount();
	for(int i = Count-1; i>=0; i--){
		for(int j=0; j<2; j++){
			s = pList->GetItemText(i,j);
			s+=' ';

			outfile<<s;
		}
		outfile<<endl;
	}
	outfile.close();	
	AfxMessageBox("保存成功");
	
}
