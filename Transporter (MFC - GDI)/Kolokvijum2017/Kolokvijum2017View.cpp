
// Kolokvijum2017View.cpp : implementation of the CKolokvijum2017View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Kolokvijum2017.h"
#endif

#include "Kolokvijum2017Doc.h"
#include "Kolokvijum2017View.h"
#include "DImage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKolokvijum2017View

IMPLEMENT_DYNCREATE(CKolokvijum2017View, CView)

BEGIN_MESSAGE_MAP(CKolokvijum2017View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_ERASEBKGND()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CKolokvijum2017View construction/destruction

CKolokvijum2017View::CKolokvijum2017View() noexcept
{
	// TODO: add construction code here
	imgLeg1 = new DImage();		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	imgLeg1->Load(CString("Leg1.bmp"));

	imgLeg2 = new DImage();
	imgLeg2->Load(CString("Leg2.bmp"));

	imgLeg3 = new DImage();
	imgLeg3->Load(CString("Leg3.bmp"));

	imgBody = new DImage();
	imgBody->Load(CString("Body.bmp"));

	imgBack2 = new DImage();  
	imgBack2->Load(CString("Back2.jpg"));

	pomeraj = 0;
	pomerajUgao = 0.0;
	pomerajUgao2 = 0.0;
	pom = true;
	pomerajScale = 0.0;
	x11 = 0;
	y11 = 0;
}

CKolokvijum2017View::~CKolokvijum2017View()
{
	delete imgLeg1;
	delete imgLeg2;
	delete imgLeg3;
	delete imgBody;
	delete imgBack2;
}

BOOL CKolokvijum2017View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CKolokvijum2017View drawing

void CKolokvijum2017View::OnDraw(CDC* pDC)
{
	CKolokvijum2017Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CRect rect;
	GetClientRect(&rect);

	CDC* pMemDC = new CDC();
	pMemDC->CreateCompatibleDC(pDC);

	CBitmap bitMap;
	bitMap.CreateCompatibleBitmap(pDC, rect.right, rect.bottom);

	pMemDC->SelectObject(&bitMap);  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	DrawScene(pMemDC, &rect);
	
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), pMemDC, 0, 0, SRCCOPY);
	pMemDC->DeleteDC();
	delete pMemDC;

}


void CKolokvijum2017View::LoadIdentity(CDC* pDC) {

}

void CKolokvijum2017View::Translate(CDC* pDC, float x, float y, bool right) {
	XFORM form;
	form.eM11 = 1.0;
	form.eM12 = 0.0;
	form.eM21 = 0.0;
	form.eM22 = 1.0;
	form.eDx = x;
	form.eDy = y;
	if (right)
		pDC->ModifyWorldTransform(&form, MWT_RIGHTMULTIPLY); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	else
		pDC->ModifyWorldTransform(&form, MWT_LEFTMULTIPLY);
}

void CKolokvijum2017View::Rotate(CDC * pDC, float angle, bool right){
	float angle2 = 3.14159 * angle / 180.0;
	
	XFORM form;
	form.eM11 = cos(angle2);
	form.eM12 = sin(angle2);
	form.eM21 = -sin(angle2);
	form.eM22 = cos(angle2);
	form.eDx = 0.0;
	form.eDy = 0.0;
	if (right)
		pDC->ModifyWorldTransform(&form, MWT_RIGHTMULTIPLY);
	else
		pDC->ModifyWorldTransform(&form, MWT_LEFTMULTIPLY);
}

void CKolokvijum2017View::Scale(CDC * pDC, float scaleX, float scaleY, bool right){
	XFORM form;
	form.eM11 = scaleX;
	form.eM12 = 0.0;
	form.eM21 = 0.0;
	form.eM22 = scaleY;
	form.eDx = 0.0;
	form.eDy = 0.0;
	if (right)
		pDC->ModifyWorldTransform(&form, MWT_RIGHTMULTIPLY);
	else
		pDC->ModifyWorldTransform(&form, MWT_LEFTMULTIPLY);
}

void CKolokvijum2017View::DrawScene(CDC * pDC, CRect rect){
	XFORM transOld;
	int gm = pDC->SetGraphicsMode(GM_ADVANCED);
	pDC->GetWorldTransform(&transOld);   //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	int startPos = 100 + pomeraj;

	float angel1 = 10.0 + pomerajUgao;
	float angel2 = -10.0 - pomerajUgao;
	float angel3 = 0.0 + pomerajUgao2;
	float angel4 = 0.0 - pomerajUgao2;
	imgBack2->Draw(pDC, CRect(x11, y11, rect.Width()+x11, rect.Height()+y11), CRect(0, 0, rect.Width(), rect.Height()));
	//pDC->SetBkColor(RGB(255,255,255));
	Translate(pDC, startPos, 100, true);
	Scale(pDC, 1.0 + pomerajScale, 1.0 + pomerajScale, true);
	imgBody->DrawTransparent(pDC, CRect(0, 0, imgBody->Width(), imgBody->Height()), CRect(0, 0, imgBody->Width(), imgBody->Height()), RGB(255, 255, 255));
	
	DrawLeg(pDC, angel1, 270, 168); //prednja iza
	DrawLeg(pDC, angel2, 270, 168); //prednja ispred
	DrawLeg(pDC, angel3, 54, 168); //zadnja iza
	DrawLeg(pDC, angel4, 54, 168); //zadnja ispred


	pDC->SetWorldTransform(&transOld);
	pDC->SetGraphicsMode(gm);
}

void CKolokvijum2017View::DrawLeg(CDC * pDC, float angle, double dx, double dy){
	XFORM transOld;
	int gm = pDC->SetGraphicsMode(GM_ADVANCED);
	pDC->GetWorldTransform(&transOld);

	Translate(pDC, dx, dy, false);
	Rotate(pDC, angle, false);
	Translate(pDC, -28, -28, false);
	Translate(pDC, 28, 28, true);

	imgLeg1->DrawTransparent(pDC, CRect(0, 0, imgLeg1->Width(), imgLeg1->Height()), CRect(0, 0, imgLeg1->Width(), imgLeg1->Height()), RGB(255, 255, 255));
	
	pDC->SetWorldTransform(&transOld);
	
	Translate(pDC, (dx - angle*2.2)*(1.0+pomerajScale*0.9), (dy + imgLeg1->Height() - 45 - apsolutna(angle/2))*(1.0 + pomerajScale * 0.9), true);
	imgLeg2->DrawTransparent(pDC, CRect(0, 0, imgLeg2->Width(), imgLeg2->Height()), CRect(0, 0, imgLeg2->Width(), imgLeg2->Height()), RGB(255, 255, 255));

	//pDC->SetWorldTransform(&transOld);
	
	Translate(pDC, -32, imgLeg2->Height() - 22, false);
	imgLeg3->DrawTransparent(pDC, CRect(0, 0, imgLeg3->Width(), imgLeg3->Height()), CRect(0, 0, imgLeg3->Width(), imgLeg3->Height()), RGB(255, 255, 255));

	
	pDC->SetWorldTransform(&transOld);
	pDC->SetGraphicsMode(gm);
}

// CKolokvijum2017View printing

BOOL CKolokvijum2017View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CKolokvijum2017View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CKolokvijum2017View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CKolokvijum2017View diagnostics

#ifdef _DEBUG
void CKolokvijum2017View::AssertValid() const
{
	CView::AssertValid();
}

void CKolokvijum2017View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKolokvijum2017Doc* CKolokvijum2017View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKolokvijum2017Doc)));
	return (CKolokvijum2017Doc*)m_pDocument;
}
#endif //_DEBUG


// CKolokvijum2017View message handlers


BOOL CKolokvijum2017View::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	//return CView::OnEraseBkgnd(pDC);

	return true;
}


void CKolokvijum2017View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	if (nChar == VK_RIGHT) {
		if (pomerajUgao == -30.0) pom = true;
		if (pomerajUgao < 20.0 && pom) {
			pomerajUgao += 10.0;
			if(pomerajUgao == 10.0)
				pom = false;
		}
		else
			pomerajUgao -= 10.0;

		if (pomerajUgao2 == -20.0) pom = true;
		if (pomerajUgao2 < 30.0 && pom) {
			pomerajUgao2 += 10.0;
			if (pomerajUgao2 == 20.0)
				pom = false;
		}
		else
			pomerajUgao2 -= 10.0;

		pomeraj += 10;

		Invalidate();
	}
	if (nChar == VK_LEFT) {
		if (pomerajUgao == -30.0) pom = true;
		if (pomerajUgao < 20.0 && pom) {
			pomerajUgao += 10.0;
			if (pomerajUgao == 10.0)
				pom = false;
		}
		else
			pomerajUgao -= 10.0;


		if (pomerajUgao2 == -20.0) pom = true;
		if (pomerajUgao2 < 30.0 && pom) {
			pomerajUgao2 += 10.0;
			if (pomerajUgao2 == 20.0)
				pom = false;
		}
		else
			pomerajUgao2 -= 10.0;

		pomeraj -= 10;

		Invalidate();
	}

	if (nChar == VK_UP) {
		pomerajScale += 0.1;

		Invalidate();
	}
	if (nChar == VK_DOWN) {
		pomerajScale -= 0.1;

		Invalidate();
	}

	if (nChar == 'D' && x11 < 2400) {
		x11 += 200;

		Invalidate();
	}
	if (nChar == 'A' && x11 > 0) {
		x11 -= 200;

		Invalidate();
	}
	if (nChar == 'W' && y11 > 0) {
		y11 -= 200;

		Invalidate();
	}
	if (nChar == 'S' && y11 < 1800) {
		y11 += 200;

		Invalidate();
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

int CKolokvijum2017View::apsolutna(int a) {
	if (a < 0)
		return -1 * a;
	else
		return a;
}