
// MFCApplication1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//CMFCApplication1Dlg *p1 = NULL;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)//构造函数
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	,muiPlateNum(0)
	, mPrint(_T(""))
	, v1(_T("( A , 1 , C )"))
	, v2(_T("( A , n , C )"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	newdlg = new FUFEI();
	newdlg->Create(IDD_DIALOG1, 0);

	pHanoi = NULL;
	muiPlateNum = 3;
	muiSpeed = 3;
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SPEED, muiSpeed);
	DDX_Text(pDX, IDC_EDIT_NUM, muiPlateNum);
	DDX_Text(pDX, IDC_EDIT_Print, mPrint);
	DDV_MinMaxUInt(pDX, muiPlateNum, 1, MAX_PLATE);;
	DDV_MinMaxUInt(pDX, muiSpeed, 1, 9);
	DDX_Control(pDX, IDC_SPIN_NUM, ctrNum);
	DDX_Control(pDX, IDC_SPIN_Speed, ctrSpeed);
	DDX_Control(pDX, IDC_BUTTON_START, BStart);
	DDX_Control(pDX, IDC_BUTTON_QUICKFANIAH, BQuick);
	DDX_Control(pDX, IDC_BUTTON_IN, BIn);
	DDX_Control(pDX, IDC_BUTTON_OUT, BOut);

	DDX_Control(pDX, IDC_BUTTON_A, BA);
	DDX_Control(pDX, IDC_BUTTON_B, BB);
	DDX_Control(pDX, IDC_BUTTON_C, BC);
	DDX_Control(pDX, IDC_BUTTON_RESET, BReset);
	DDX_Control(pDX, IDC_BUTTON_NO, BRules);
	DDX_Control(pDX, IDC_STATIC_PIC, ctrPicture);
	DDX_Text(pDX, IDC_STATIC_V1, v1);
	DDX_Text(pDX, IDC_STATIC_V2, v2);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_START, &CMFCApplication1Dlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_QUICKFANIAH, &CMFCApplication1Dlg::OnBnClickedButtonQuickfaniah)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CMFCApplication1Dlg::OnBnClickedButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_IN, &CMFCApplication1Dlg::OnBnClickedButtonIn)
	ON_BN_CLICKED(IDC_BUTTON_OUT, &CMFCApplication1Dlg::OnBnClickedButtonOut)
	ON_BN_CLICKED(IDC_BUTTON_NO, &CMFCApplication1Dlg::OnBnClickedButtonNo)
	ON_BN_CLICKED(IDC_BUTTON_A, &CMFCApplication1Dlg::OnBnClickedButtonA)
	ON_BN_CLICKED(IDC_BUTTON_B, &CMFCApplication1Dlg::OnBnClickedButtonB)
	ON_BN_CLICKED(IDC_BUTTON_C, &CMFCApplication1Dlg::OnBnClickedButtonC)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_NUM, &CMFCApplication1Dlg::OnDeltaposSpinNum)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_Speed, &CMFCApplication1Dlg::OnDeltaposSpinSpeed)
	ON_EN_CHANGE(IDC_EDIT_NUM, &CMFCApplication1Dlg::OnEnChangeEditNum)
	ON_EN_CHANGE(IDC_EDIT_SPEED, &CMFCApplication1Dlg::OnEnChangeEditSpeed)
	ON_STN_CLICKED(IDC_STATIC_PIC, &CMFCApplication1Dlg::OnStnClickedStaticPic)
	ON_EN_CHANGE(IDC_EDIT_Print, &CMFCApplication1Dlg::OnEnChangeEditPrint)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCApplication1Dlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCApplication1Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCApplication1Dlg::OnBnClickedRadio2)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	//p1 = this;

	ctrNum.SetRange(1, MAX_PLATE);//设置范围
	ctrNum.SetBuddy(GetDlgItem(IDC_EDIT_NUM));//设置绑定对象
	ctrSpeed.SetRange(1, 9);
	ctrSpeed.SetBuddy(GetDlgItem(IDC_EDIT_SPEED));//设置绑定对象
	pHanoi = new Hanoi((void *)this);

	model = 1;
	BOut.EnableWindow(0);
	BA.EnableWindow(0);
	BB.EnableWindow(0);
	BC.EnableWindow(0);
	BRules.EnableWindow(0);

	((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(TRUE); //选上
	((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(FALSE); //没选上

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		//初始画面
		CDC *pDC = ctrPicture.GetWindowDC();
		CRect rect;

		GetClientRect(&rect); //获取窗口客户区的大小
		pDC->FillSolidRect(rect, RGB(255, 255, 255));

		pHanoi->DrawPeg(pDC);

		UpdateData(TRUE);
		if ((muiPlateNum != pHanoi->PlateNum) || (muiSpeed != pHanoi->Speed) || (flag == 1))
		{
			mPrint = _T("");
			flag = 0;
			pHanoi->initPlateStatus(muiPlateNum, muiSpeed);
		}
		UpdateData(FALSE);

		for (int i = 0; i < muiPlateNum; i++)
			pHanoi->DrawPlate(pDC, i);
		ctrPicture.ReleaseDC(pDC);
		egg = 0;
		Pre = -1;
		Step = 0;
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication1Dlg::MPrint(CString Msg)
{
	UpdateData(TRUE);
	mPrint += Msg;
	v1 = Msg;
	v2 = Msg;
	UpdateData(FALSE);
	CEdit *p = (CEdit*)GetDlgItem(IDC_EDIT_Print); //定义一个指向编辑框的句柄的指针
	p->LineScroll(p->GetLineCount());//滚动条置底
	MSG   msg;
	while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) //神奇的操作,保留画面
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}


CDC * CMFCApplication1Dlg::GetDC()
{
	return ctrPicture.GetWindowDC();
}

void CMFCApplication1Dlg::Delay(DWORD x)
{
	DWORD timeBegin = timeGetTime();
	DWORD timeEnd = 0;
	do
	{
		timeEnd = timeGetTime();
	} while (timeEnd - timeBegin <= x);
}

void CMFCApplication1Dlg::HighSpeed()
{
	pHanoi->Speed = 0;
}


void CMFCApplication1Dlg::OnBnClickedButtonStart()//开始演示
{
	// TODO: 在此添加控件通知处理程序代码
	//SetTimer(1, 1000, NULL); //计时器1
	BStart.EnableWindow(0);
	BReset.EnableWindow(0);
	BIn.EnableWindow(0);
	ctrNum.EnableWindow(0);
	ctrSpeed.EnableWindow(0);
	pHanoi->Begin();
	BReset.EnableWindow(1);
	ctrNum.EnableWindow(1);
	ctrSpeed.EnableWindow(1);
	//KillTimer(1);
}


void CMFCApplication1Dlg::OnBnClickedButtonQuickfaniah()//快速完成，以最快速度完成
{
	// TODO: 在此添加控件通知处理程序代码
	HighSpeed();
}


void CMFCApplication1Dlg::OnBnClickedButtonReset()//复位
{
	// TODO: 在此添加控件通知处理程序代码
	flag = 1;
	Pre = -1;
	if (model == 1)
	{
		BStart.EnableWindow(1);
		BIn.EnableWindow(1);
	}
	noRules = 0;
	Invalidate();
	if (model == 2)
	{
		CString str;
		BRules.EnableWindow(1);
		str.Format(_T("您仍处于游玩模式！\r\n"));
		MessageBox(str,_T("提示"));
		//MPrint(str);
	}
}



void CMFCApplication1Dlg::OnBnClickedButtonIn()//进入游戏
{
	// TODO: 在此添加控件通知处理程序代码
	BStart.EnableWindow(0);
	BQuick.EnableWindow(0);
	ctrNum.EnableWindow(0);
	ctrSpeed.EnableWindow(0);
	BIn.EnableWindow(0);
	BOut.EnableWindow(1);
	BA.EnableWindow(1);
	BB.EnableWindow(1);
	BC.EnableWindow(1);
	Pre = -1;
	model = 2;
	noRules = 0;
	CString str;
	BRules.EnableWindow(1);
	str.Format(_T("您已进入游玩模式！\r\n"));
	//MPrint(str);
	MessageBox(str,_T("提示"));
}


void CMFCApplication1Dlg::OnBnClickedButtonOut()//退出游戏
{
	// TODO: 在此添加控件通知处理程序代码
	BStart.EnableWindow(1);
	BQuick.EnableWindow(1);
	ctrNum.EnableWindow(1);
	ctrSpeed.EnableWindow(1);
	BIn.EnableWindow(1);
	BOut.EnableWindow(0);
	BA.EnableWindow(0);
	BB.EnableWindow(0);
	BC.EnableWindow(0);
	flag = 1;
	model = 1;
	BRules.EnableWindow(0);
	Invalidate();
	CString str;
	str.Format(_T("您已退出游玩模式！\r\n"));
	MessageBox(str,_T("提示"));
}


void CMFCApplication1Dlg::OnBnClickedButtonNo()//无视规则
{
	// TODO: 在此添加控件通知处理程序代码
	newdlg->ShowWindow(SW_SHOWNORMAL); //展示新对话框
	noRules = 1;
	BRules.EnableWindow(0);
}


void CMFCApplication1Dlg::OnBnClickedButtonA()//buttonA
{
	// TODO: 在此添加控件通知处理程序代码
	int Top = pHanoi->findTop(0);
	if (Top == -1 && Pre == -1)
	{
		CString str;
		str.Format(_T("A上没有圆盘\r\n"));
		MessageBox(str, _T("提示"));
		//MPrint(str);
	}
	else {
		if (Pre == -1)
		{
			//CString str;
			//str.Format(_T("A上有圆盘\r\n"));
			//MPrint(str);
			pHanoi->DrawFrame(GetDC(), Top, 0);
			Pre = 0;
		}
		else
		{
			if (pHanoi->findTop(Pre) > Top && Top != -1 && (noRules == 0))
			{
				CString str;
				str.Format(_T("违反规则了哟\r\n"));
				MessageBox(str, _T("提示"));
				//MPrint(str);
				pHanoi->DrawFrame(GetDC(), pHanoi->findTop(Pre), 1);
				Pre = -1;
			}
			else
			{
				pHanoi->Move(Pre, 0);
				Step++;
				Pre = -1;
			}
		}
	}

}


void CMFCApplication1Dlg::OnBnClickedButtonB()//BUTTONb
{
	// TODO: 在此添加控件通知处理程序代码
	int Top = pHanoi->findTop(1);
	if (Top == -1 && Pre == -1)
	{
		CString str;
		str.Format(_T("B上没有圆盘\r\n"));
		MessageBox(str, _T("提示"));
		//MPrint(str);
	}
	else {
		if (Pre == -1)
		{
			//CString str;
			//str.Format(_T("A上有圆盘\r\n"));
			//MPrint(str);
			pHanoi->DrawFrame(GetDC(), Top, 0);
			Pre = 1;
		}
		else
		{
			if (pHanoi->findTop(Pre) > Top && Top != -1 && (noRules == 0))
			{
				CString str;
				str.Format(_T("违反规则了哟\r\n"));
				MessageBox(str, _T("提示"));
				//MPrint(str);
				pHanoi->DrawFrame(GetDC(), pHanoi->findTop(Pre), 1);
				Pre = -1;
			}
			else
			{
				pHanoi->Move(Pre, 1);
				Step++;
				Pre = -1;
			}
		}
	}
}


void CMFCApplication1Dlg::OnBnClickedButtonC()//BUTTONc
{
	// TODO: 在此添加控件通知处理程序代码
	int Top = pHanoi->findTop(2);
	if (Top == -1 && Pre == -1)
	{
		CString str;
		str.Format(_T("C上没有圆盘\r\n"));
		MessageBox(str, _T("提示"));
		//MPrint(str);
	}
	else {
		if (Pre == -1)
		{
			//CString str;
			//str.Format(_T("A上有圆盘\r\n"));
			//MPrint(str);
			pHanoi->DrawFrame(GetDC(), Top, 0);
			Pre = 2;
		}
		else
		{
			if (pHanoi->findTop(Pre) > Top && Top != -1 && (noRules == 0))
			{
				CString str;
				str.Format(_T("违反规则了哟\r\n"));
				MessageBox(str, _T("提示"));
				//MPrint(str);
				pHanoi->DrawFrame(GetDC(), pHanoi->findTop(Pre), 1);
				Pre = -1;
			}
			else
			{
				pHanoi->Move(Pre, 2);
				Step++;
				Pre = -1;
				if (pHanoi->findTop(0) == -1 && pHanoi->findTop(1) == -1) {
					CString str;
					str.Format(_T("恭喜你完成了！\r\n"));
					MessageBox(str, _T("提示"));
					//MPrint(str);
					str.Format(_T("你完成%d重塔使用了%d步！\r\n"), muiPlateNum, Step);
					//MPrint(str);
					MessageBox(str, _T("提示"));
					egg++;
					if (egg == 3)
					{
						str.Format(_T("恭喜你触发了彩蛋！\r\n"));
						//MPrint(str);
						MessageBox(str, _T("提示"));
					}
					/*if (noRules == 1 || pHanoi->PlateNum == 10) //没有规则或有10个盘子，完成后立即复位
									  //使用"无视规则"将无法触发彩蛋
					{                 // Bug已解决
						flag = 1;
						Pre = -1;
						/*if (model == 1)
						{
							BStart.EnableWindow(1);
							BIn.EnableWindow(1);
						}*/
						/*noRules = 0;
						BRules.EnableWindow(1);
						Invalidate();
					}*/
				}
			}
		}
	}

}



void CMFCApplication1Dlg::OnDeltaposSpinNum(NMHDR *pNMHDR, LRESULT *pResult)//调节盘子数目
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CMFCApplication1Dlg::OnDeltaposSpinSpeed(NMHDR *pNMHDR, LRESULT *pResult)//调节移动速度
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CMFCApplication1Dlg::OnEnChangeEditNum()//数目编辑框
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	if (model == 1)
	{
		BStart.EnableWindow(1);
		BIn.EnableWindow(1);
	}
	Invalidate();  //重绘
}


void CMFCApplication1Dlg::OnEnChangeEditSpeed()//速度编辑框
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	if (model == 1)
	{
		BStart.EnableWindow(1);
		BIn.EnableWindow(1);
	}
	Invalidate();
}


void CMFCApplication1Dlg::OnStnClickedStaticPic()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication1Dlg::OnEnChangeEditPrint()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

}


void CMFCApplication1Dlg::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
	((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(TRUE); //选上
	((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(FALSE); //没选上
}


void CMFCApplication1Dlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(TRUE); //选上
	((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(FALSE); //没选上
}
