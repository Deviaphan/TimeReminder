#include "stdafx.h"
#include "TimeReminderDlg.h"
#include "CMessageDlg.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTimeReminderDlg dialog

enum { REMIND_TIMER_ID = 3216 };

CTimeReminderDlg::CTimeReminderDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_TIMEREMINDER_DIALOG, pParent)
	, _minutes( 60 )
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTimeReminderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange( pDX );
	DDX_Control( pDX, IDC_START_TIMER, _btnStart );
	DDX_Control( pDX, IDC_STOP_TIMER, _btnEnd );
	DDX_Text( pDX, IDC_EDIT_TIME, _minutes );
	DDV_MinMaxInt(pDX, _minutes, 1, 480);
}

BEGIN_MESSAGE_MAP(CTimeReminderDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED( IDC_START_TIMER, OnStartTimer )
	ON_BN_CLICKED( IDC_STOP_TIMER, OnStopTimer )
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CTimeReminderDlg message handlers

BOOL CTimeReminderDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTimeReminderDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTimeReminderDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTimeReminderDlg::OnStartTimer()
{
	UpdateData();

	if( _minutes <= 0 )
		return;

	_btnStart.EnableWindow( FALSE );
	_btnEnd.EnableWindow( TRUE );

	UINT time = _minutes * 60 * 1000;
	SetTimer( REMIND_TIMER_ID, time, nullptr );
}


void CTimeReminderDlg::OnStopTimer()
{
	KillTimer( REMIND_TIMER_ID );

	_btnStart.EnableWindow( TRUE );
	_btnEnd.EnableWindow( FALSE );
}


void CTimeReminderDlg::OnCancel()
{
	OnStopTimer();

	CDialog::OnCancel();
}


void CTimeReminderDlg::OnOK()
{
	OnStopTimer();

	CDialog::OnOK();
}


void CTimeReminderDlg::OnTimer( UINT_PTR nIDEvent )
{
	if( nIDEvent )
	{
		CMessageDlg dlg;
		dlg.DoModal();
	}
	else
	{
		CDialog::OnTimer( nIDEvent );
	}
}
