
// TimeReminderDlg.h : header file
//

#pragma once


// CTimeReminderDlg dialog
class CTimeReminderDlg : public CDialog
{
// Construction
public:
	CTimeReminderDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIMEREMINDER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStartTimer();
	afx_msg void OnStopTimer();
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnTimer( UINT_PTR nIDEvent );
	CButton _btnStart;
	CButton _btnEnd;

private:
	int _minutes;
};
