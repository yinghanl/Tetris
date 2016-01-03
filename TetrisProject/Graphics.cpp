#include "Graphics.h"



Graphics::Graphics()
{
	mFactory = nullptr;
	mRenderTarget = nullptr;
}


Graphics::~Graphics()
{
	if (mFactory != nullptr)
	{
		mFactory->Release();
	}
	if (mRenderTarget != nullptr)
	{
		mRenderTarget->Release();
	}
}

bool Graphics::Init(HWND windowHandle)
{
	HRESULT result = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &mFactory);
	if (result != S_OK)
	{
		return false;
	}

	RECT rect;
	GetClientRect(windowHandle, &rect);

	result = mFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(windowHandle, D2D1::SizeU(rect.right, rect.bottom)), &mRenderTarget);

	if (result != S_OK)
	{
		return false;
	}

	return true;
}

void Graphics::BeginDraw()
{
	mRenderTarget->BeginDraw();
}

void Graphics::EndDraw()
{
	mRenderTarget->EndDraw();
}

void Graphics::ClearScreen(float r, float g, float b)
{
	mRenderTarget->Clear(D2D1::ColorF(r, g, b));
}

void Graphics::DrawCircle(float x, float y, float radius, float r, float g, float b, float a)
{
	ID2D1SolidColorBrush *brush;
	mRenderTarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b, a), &brush);

	mRenderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius), brush, 3.0F);

	brush->Release();
}

void Graphics::DrawRectangle(float x, float y, float h, float w, float r, float g, float b, float a)
{
	ID2D1SolidColorBrush *brush;
	mRenderTarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b, a), &brush);

	mRenderTarget->DrawRectangle(D2D1::Rect(x, y, x + w, y + h), brush, 3.0F);

	brush->Release();
}

void Graphics::FillRectangle(float x, float y, float h, float w, float r, float g, float b, float a)
{
	ID2D1SolidColorBrush *brush;
	mRenderTarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b, a), &brush);

	mRenderTarget->FillRectangle(D2D1::Rect(x, y, x + w, y + h), brush);

	brush->Release();
}