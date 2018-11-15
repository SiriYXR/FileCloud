#pragma once

#pragma comment(lib,"SDL2_gfx.lib")

#include "Window.h"
#include "SDL2_gfxPrimitives.h"

#include <string>

using namespace std;

namespace siri {

	class Button
	{
	private:
		Window * m_win;

		SDL_Rect m_rect;
		SDL_Color m_color;
		SDL_Texture* m_img;
		string m_text;

		int m_shadowSize;
		SDL_Color m_shadowColor;

		bool m_isOn;
		bool m_isHiden;
		bool m_isShadowHiden;
	public:
		Button(Window* win, SDL_Rect rect, SDL_Texture* img = NULL, string* text = NULL, SDL_Color* color = NULL, int shadowSize = 2, SDL_Color* shadowColor = NULL);
		Button(Window* win, Rect rect, SDL_Texture* img = NULL, string* text = NULL, SDL_Color* color = NULL, int shadowSize = 2, SDL_Color* shadowColor = NULL);
		~Button();

		void update();
		void render();
		void event(SDL_Event* events);

		void setIsHiden(bool ishiden);
		void setIsShadowHiden(bool isshadowhiden);

		Point& getPoint();
		SDL_Point& getSDLPoint();
		void setPoint(Point point);
		void setPoint(SDL_Point point);


		bool isOn();
	};

}