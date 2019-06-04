// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "研究生初试录取系统.h"
#include "LoginDlg.h"
#include<fstream>
#include<iostream>
#include<string>
#include "研究生初试录取系统Dlg.h"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
	m_Username = _T("");
	m_Password = _T("");
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
	DDX_Text(pDX, IDC_EDIT1, m_Username);
	DDX_Text(pDX, IDC_EDIT2, m_Password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

void CLoginDlg::OnOK() 
{
	// TODO: Add extra validation here
	//CLoginDlg m_Dlg;
			CString userName, pwd;
			GetDlgItemText(IDC_EDIT1, userName);
			GetDlgItemText(IDC_EDIT2, pwd);


			CString temp1, temp2;
			string a="user.txt";
			ifstream infile(a.data());	
			string n,p;
			infile>>n>>p;
			while(n != ""){	
				temp1=n.c_str();
				temp2=p.c_str();
				if(temp1==userName&&temp2==pwd) {
					CDialog::EndDialog(IDD_DIALOG1);
					CMyDlg dlg;
					dlg.DoModal();
					return;	
				}
				
			infile >>n>>p;
			}

			infile.close(); 
			
			AfxMessageBox("登陆失败");
}

