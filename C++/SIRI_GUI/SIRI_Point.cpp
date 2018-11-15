#include "Point.h"

namespace siri {

	Point::Point()
	{
		m_x = 0;
		m_y = 0;
	}

	Point::Point(int x, int y)
	{
		m_x = x;
		m_y = y;
	}


	Point::~Point()
	{
	}

	int Point::getX()
	{
		return m_x;
	}

	int Point::getY()
	{
		return m_y;
	}

	void Point::setX(int x)
	{
		m_x = x;
	}

	void Point::setY(int y)
	{
		m_y = y;
	}

	SDL_Point& Point::toSDLPoint()
	{
		SDL_Point point;
		point.x = m_x;
		point.y = m_y;
		return point;
	}

}