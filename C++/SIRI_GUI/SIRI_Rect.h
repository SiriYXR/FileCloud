#pragma once
#include "Point.h"
#include "Size.h"

namespace siri {

	class Rect
	{
	public:
		Rect();
		Rect(int x, int y, int w, int h);
		Rect(SDL_Rect rect);
		Rect(int x,int y,SDL_Texture* img);
		~Rect();
	private:
		int m_x;
		int m_y;
		int m_w;
		int m_h;
	public:

		Point& getPoint();
		Size& getSize();
		SDL_Point& getSDLPoint();

		int getX();
		int getY();
		int getW();
		int getH();

		void setX(int x);
		void setY(int y);
		void setW(int w);
		void setH(int h);

		SDL_Rect& toSDLRect();
	};

}

