
// MFCApplication1Dlg.h: 头文件
//

#pragma once
#include "Hanoi.h"
#include "FUFEI.h"

// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	int muiPlateNum; //输入的盘数
	int muiSpeed;
	Hanoi *pHanoi;
	// 静态控件类
	CStatic ctrPicture;
	CDC * GetDC(); //设备环境对象类（上下文
	void MPrint(CString msg);
	//void MPrint1(CString msg);//代码联动部分
	CString mPrint;//message
	CSpinButtonCtrl ctrNum, ctrSpeed;
	FUFEI* newdlg;

	void Delay(DWORD x);
	void HighSpeed();
	bool flag; // 复位
	int Pre; // 源or目标,从哪一根移动
	int model; //模式 1、演示 2、游玩
	int egg; // 彩蛋 
	int Step; // 用了多少步
	bool noRules;

	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonQuickfaniah();
	afx_msg void OnBnClickedButtonReset();
	afx_msg void OnBnClickedButtonIn();
	afx_msg void OnBnClickedButtonOut();
	afx_msg void OnBnClickedButtonNo();
	afx_msg void OnBnClickedButtonA();
	afx_msg void OnBnClickedButtonB();
	afx_msg void OnBnClickedButtonC();
	CButton BStart;
	CButton BQuick;
	CButton BIn;
	CButton BOut;
	CButton BA;
	CButton BB;
	CButton BC;
	CButton BReset;
	CButton BRules;
	afx_msg void OnDeltaposSpinNum(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinSpeed(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditNum();
	afx_msg void OnEnChangeEditSpeed();
	afx_msg void OnStnClickedStaticPic();
	afx_msg void OnEnChangeEditPrint();
	CString v1;
	CString v2;
	int m_radiogroup;
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio2();
};
