// CMessageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TimeReminder.h"
#include "CMessageDlg.h"
#include "afxdialogex.h"


// CMessageDlg dialog

IMPLEMENT_DYNAMIC(CMessageDlg, CDialog)

CMessageDlg::CMessageDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MESSAGE, pParent)
{

}

CMessageDlg::~CMessageDlg()
{
}

void CMessageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMessageDlg, CDialog)
END_MESSAGE_MAP()


// CMessageDlg message handlers


void CMessageDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

//	CDialog::OnOK();
}


void CMessageDlg::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class

	CDialog::OnCancel();
}
