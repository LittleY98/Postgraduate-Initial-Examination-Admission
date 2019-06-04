// UserManage.cpp : implementation file
//

#include "stdafx.h"
#include "�о�������¼ȡϵͳ.h"
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

	if (nSel < 0) {//С��0��ʾû��ѡ��
		AfxMessageBox("��ѡ��Ҫѡ����", MB_OK);
	} else {
		if(AfxMessageBox("ȷ��ɾ����",MB_YESNO)==IDYES){  
			pList->DeleteItem(nSel);//��ѡ�е���һ���������������ȫ������
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
        //û��ѡ���κζ������͵�����AfxMessageBox��MFC�еĺ�����ͬ������ʹ��Win32��MessageBox������  
        //�����������������������MessageBox�������õ����ı��⣬Ĭ��Ϊ���ǵĹ����������ô��ǲ���д�����˭  
        AfxMessageBox("��ѡ��Ҫ�޸ĵ��",MB_OK);  
    else{  
        //ѡ������������ѡ���û���AfxMessageBox�õ�IDYES��ֵ��Ҳ�����û������ǡ��Ž���������޸Ĵ���  
        if(AfxMessageBox("ȷ���޸ģ�",MB_YESNO)==IDYES){  
			CString str;        
            GetDlgItemText(IDC_EDIT1,str);  
            //����ʱIDC_EDIT1Ҳ���ǡ�ѧ�š��༭���ֵ�滻��ѡ�����еĵ�0�Ȼ��������ƣ��������޸�  
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

	//���ǻ�ȡ����list�ؼ�IDC_LIDT1��ָ��
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST1);
	//����һ���У�ѧ�ţ�����룬���Ϊ100��֮��һ�����ƣ�����list�ؼ�����ı�����
	pList ->InsertColumn(0, "�˺�", LVCFMT_LEFT, 150);
	pList ->InsertColumn(1, "����", LVCFMT_LEFT, 100);
	

	//CListCtrl *pList=(CListCtrl *)GetDlgItem(IDC_LIST1);  
	CString temp1, temp2;
	string a="user.txt";
	ifstream infile(a.data());
	if(!infile){
		MessageBox("��û�б������Ϣ","Error",MB_ICONERROR | MB_OKCANCEL);
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

	//���ǻ�ȡ����List�ؼ�IDC_LIST1��ָ��  
    CListCtrl *pList=(CListCtrl *)GetDlgItem(IDC_LIST1);  
    //�����ǻ�ȡѡ���λ�ã����û���κ�ѡ�������еĺ�������������nSelΪ-1�����ѡ���ˣ���nSelΪ����ѡ�������  
    POSITION pos=pList->GetFirstSelectedItemPosition();  
    int nSel=pList->GetNextSelectedItem(pos);
	
	
    
			
			CString str1,str2; //����һ����ʱ�ַ�������
    
	
			str1 = pList->GetItemText(nSel,0); //��һ������Ϊ�кţ��ڶ�������Ϊ��ʱ�ַ�������
			str2 = pList->GetItemText(nSel,1);//��һ������Ϊ�кţ��ڶ���λ��Ϊ�кţ�����������Ϊ��ʱ�ַ�������
	
			
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
	AfxMessageBox("����ɹ�");
	
}
