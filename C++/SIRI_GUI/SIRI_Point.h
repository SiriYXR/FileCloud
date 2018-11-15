#pragma once

#pragma comment(lib,"SDL2.lib")
#pragma comment(lib,"SDL2main.lib")

#include "SDL.h"

namespace siri {

	class Point
	{
	public:
		Point();
		Point(int x, int y);
		~Point();

	private:
		int m_x;
		int m_y;

	public:
		int getX();
		int getY();

		void setX(int x);
		void setY(int y);

		SDL_Point& toSDLPoint();
	};

}