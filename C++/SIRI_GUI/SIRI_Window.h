#pragma once
#include "Picture.h"
#include "Music.h"

namespace siri {

	class Window
	{
	public:
		Window();
		~Window();

		//��ʼ�� SDL �� TTF, ����һ�����ں���Ⱦ��
		void Init(std::string title = "Window", const int SCREEN_WIDTH = 640, const int SCREEN_HEIGHT = 480);
		//�Ƴ� SDL �� TTF
		void Quit();
		//���� SDL_Texture
		void Draw(SDL_Texture *tex, SDL_Rect &dstRect, SDL_Rect *clip = NULL, float angle = 0.0, int xPivot = 0, int yPivot = 0, SDL_RendererFlip flip = SDL_FLIP_NONE);
		void Draw(SDL_Texture *tex, int x, int y);
		//�������
		SDL_Texture* RenderText(const std::string &message, const std::string &fontFile, int fontSize, SDL_Color color = { 255,255,255 });
		void RenderText(const std::string &message, const std::string &fontFile, int x, int y, int fontSize, SDL_Color color = { 255,255,255 });
		//��մ�������
		void Clear();
		//��ʾ��������
		void Present();
		//��ô��ڵĳߴ�
		SDL_Rect& getSDLRect();
		Size& getSize();

		SDL_Renderer* getRenderer();

	public:
		Picture *mPicture;
		Music *mMusic;

	private:
		SDL_Window *mWindow;
		SDL_Renderer *mRenderer;
		SDL_Rect mBox;

	};


}