#pragma once

namespace siri {

	class Size
	{
	public:
		Size();
		Size(int w, int h);
		~Size();

	private:
		int m_w;
		int m_h;

	public:
		int getW();
		int getH();
		void setW(int w);
		void setH(int h);
	};

}