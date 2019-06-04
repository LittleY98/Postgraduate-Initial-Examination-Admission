#if !defined(AFX_LUQUDLG_H__E078FAEC_813B_4C47_B13F_901A96D56AB1__INCLUDED_)
#define AFX_LUQUDLG_H__E078FAEC_813B_4C47_B13F_901A96D56AB1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LuquDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLuquDlg dialog

class CLuquDlg : public CDialog
{
// Construction
public:
	CLuquDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLuquDlg)
	enum { IDD = IDD_DIALOG3 };
	long	m_EDIT;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLuquDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLuquDlg)
	afx_msg void OnButton1();
	virtual BOOL OnInitDialog();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LUQUDLG_H__E078FAEC_813B_4C47_B13F_901A96D56AB1__INCLUDED_)
