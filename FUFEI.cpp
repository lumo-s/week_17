// FUFEI.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "FUFEI.h"
#include "afxdialogex.h"

// FUFEI 对话框

IMPLEMENT_DYNAMIC(FUFEI, CDialogEx)

FUFEI::FUFEI(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

FUFEI::~FUFEI()
{
}

void FUFEI::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FUFEI, CDialogEx)
	ON_BN_CLICKED(IDOK, &FUFEI::OnBnClickedOk)
END_MESSAGE_MAP()


// FUFEI 消息处理程序


void FUFEI::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
