
// Kolokvijum2017View.h : interface of the CKolokvijum2017View class
//

#pragma once
#include "DImage.h"

class CKolokvijum2017View : public CView
{
protected: // create from serialization only
	CKolokvijum2017View() noexcept;
	DECLARE_DYNCREATE(CKolokvijum2017View)

// Attributes
public:
	CKolokvijum2017Doc* GetDocument() const;
	DImage* imgLeg1;
	DImage* imgLeg2;
	DImage* imgLeg3;
	DImage* imgBody;
	DImage* imgBack2;
	int pomeraj;
	float pomerajUgao;
	float pomerajUgao2;
	bool pom;
	float pomerajScale;
	int x11, y11;

// Operations
public:
	void LoadIdentity(CDC* pDC);
	void Translate(CDC* pDC, float x, float y, bool right);
	void Rotate(CDC* pDC, float angle, bool right);
	void Scale(CDC* pDC, float scaleX, float scaleY, bool right);

	void DrawScene(CDC* pDC, CRect rect);
	void DrawLeg(CDC* pDC, float angle, double dx, double dy);

	int apsolutna(int a);
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CKolokvijum2017View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in Kolokvijum2017View.cpp
inline CKolokvijum2017Doc* CKolokvijum2017View::GetDocument() const
   { return reinterpret_cast<CKolokvijum2017Doc*>(m_pDocument); }
#endif

