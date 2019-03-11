
// Kolokvijum2017Doc.cpp : implementation of the CKolokvijum2017Doc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Kolokvijum2017.h"
#endif

#include "Kolokvijum2017Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CKolokvijum2017Doc

IMPLEMENT_DYNCREATE(CKolokvijum2017Doc, CDocument)

BEGIN_MESSAGE_MAP(CKolokvijum2017Doc, CDocument)
END_MESSAGE_MAP()


// CKolokvijum2017Doc construction/destruction

CKolokvijum2017Doc::CKolokvijum2017Doc() noexcept
{
	// TODO: add one-time construction code here

}

CKolokvijum2017Doc::~CKolokvijum2017Doc()
{
}

BOOL CKolokvijum2017Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CKolokvijum2017Doc serialization

void CKolokvijum2017Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CKolokvijum2017Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CKolokvijum2017Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CKolokvijum2017Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CKolokvijum2017Doc diagnostics

#ifdef _DEBUG
void CKolokvijum2017Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKolokvijum2017Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CKolokvijum2017Doc commands
