
// Kolokvijum2017.h : main header file for the Kolokvijum2017 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CKolokvijum2017App:
// See Kolokvijum2017.cpp for the implementation of this class
//

class CKolokvijum2017App : public CWinApp
{
public:
	CKolokvijum2017App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CKolokvijum2017App theApp;
