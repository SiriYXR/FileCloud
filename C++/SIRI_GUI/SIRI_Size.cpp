#include "Size.h"

namespace siri {

	


	Size::Size()
	{
		m_w = 0;
		m_h = 0;
	}

	Size::Size(int w, int h)
	{
		m_w = w;
		m_h = h;
	}

	Size::~Size()
	{
	}

	int Size::getW()
	{
		return m_w;
	}

	int Size::getH()
	{
		return m_h;
	}

	void Size::setW(int w)
	{
		m_w = w;
	}

	void Size::setH(int h)
	{
		m_h = h;
	}

}