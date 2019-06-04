#if !defined(AFX_USERMANAGE_H__8939F4B8_DF08_4560_92A2_A2978A930F3C__INCLUDED_)
#define AFX_USERMANAGE_H__8939F4B8_DF08_4560_92A2_A2978A930F3C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserManage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserManage dialog

class CUserManage : public CDialog
{
// Construction
public:
	CUserManage(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUserManage)
	enum { IDD = IDD_DIALOG4 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserManage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserManage)
	afx_msg void OnInsert();
	afx_msg void OnDelete();
	afx_msg void OnUpDate();
	virtual BOOL OnInitDialog();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBaoCun();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERMANAGE_H__8939F4B8_DF08_4560_92A2_A2978A930F3C__INCLUDED_)
