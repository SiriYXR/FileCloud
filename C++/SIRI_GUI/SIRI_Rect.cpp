#include "Rect.h"

#pragma comment(lib,"SDL2_image.lib")
#include "SDL_image.h"

namespace siri {

	Rect::Rect()
	{
		m_x = 0;
		m_y = 0;
		m_w = 0;
		m_h = 0;
	}

	Rect::Rect(int x, int y, int w, int h)
	{
		m_x = x;
		m_y = y;
		m_w = w;
		m_h = h;
	}

	Rect::Rect(SDL_Rect rect)
	{
		m_x = rect.x;
		m_y = rect.y;
		m_w = rect.w;
		m_h = rect.h;
	}

	Rect::Rect(int x, int y, SDL_Texture * img)
	{
		if (img) {
			m_x = x;
			m_y = y;
			SDL_QueryTexture(img, NULL, NULL, &m_w, &m_h);
		}
		else {
			m_x = 0;
			m_y = 0;
			m_w = 0;
			m_h = 0;
		}
	}


	Rect::~Rect()
	{
	}

	Point& Rect::getPoint()
	{
		return Point(m_x,m_y);
	}

	Size& Rect::getSize()
	{
		return Size(m_w,m_y);
	}

	SDL_Point& Rect::getSDLPoint()
	{
		return Point(m_x, m_y).toSDLPoint();
	}

	int Rect::getX()
	{
		return m_x;
	}
	int Rect::getY()
	{
		return m_y;
	}
	int Rect::getW()
	{
		return m_w;
	}
	int Rect::getH()
	{
		return m_h;
	}
	void Rect::setX(int x)
	{
		m_x = x;
	}
	void Rect::setY(int y)
	{
		m_y = y;
	}
	void Rect::setW(int w)
	{
		m_w = w;
	}
	void Rect::setH(int h)
	{
		m_h = h;
	}
	SDL_Rect& Rect::toSDLRect()
	{
		SDL_Rect rect;
		rect.x = m_x;
		rect.y = m_y;
		rect.w = m_w;
		rect.h = m_h;
		return rect;
	}
}


