#include "Window.h"

#pragma comment(lib,"SDL2_image.lib")
#pragma comment(lib,"SDL2_ttf.lib")

#include "SDL_image.h"
#include "SDL_ttf.h"
#include <stdexcept>

namespace siri {

	Window::Window()
	{
		//Initialize the unique_ptr's deleters here
		mWindow = nullptr;
		mRenderer = nullptr;
		mPicture = nullptr;
		mMusic = nullptr;
	}


	Window::~Window()
	{
		SDL_DestroyRenderer(mRenderer);
		SDL_DestroyWindow(mWindow);

		delete mPicture;
		delete mMusic;
	}

	/**
	*  Initialize SDL, setup the window and renderer
	*  @param title The window title
	*/
	void Window::Init(std::string title, const int SCREEN_WIDTH, const int SCREEN_HEIGHT)
	{
		//initialize all SDL subsystems
		if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
			throw std::runtime_error("SDL Init Failed");
		if (TTF_Init() == -1)
			throw std::runtime_error("TTF Init Failed");
		if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == -1)
			throw std::runtime_error("IMG Init Failed");

		//Setup our window size
		mBox.x = 0;
		mBox.y = 0;
		mBox.w = SCREEN_WIDTH;
		mBox.h = SCREEN_HEIGHT;
		//Create our window
		mWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mBox.w, mBox.h, SDL_WINDOW_SHOWN);
		//Make sure it created ok
		if (mWindow == nullptr)
			throw std::runtime_error("Failed to create window");

		//Create the renderer
		mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);//SDL_RENDERER_PRESENTVSYNC 同步垂直 稳定帧数与显示器一样为60帧
																										  //Make sure it created ok
		if (mRenderer == nullptr)
			throw std::runtime_error("Failed to create renderer");

		//init Picture
		mPicture = new Picture(mRenderer);
		if (mPicture == nullptr)
			throw std::runtime_error("Picture Init Failed");

		//init Music
		mMusic = new Music;
		if (mMusic == nullptr)
			throw std::runtime_error("Music Init Failed");

		SDL_SetWindowIcon(mWindow, mPicture->icon);
	}

	void Window::Quit()
	{
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
	}

	void Window::Draw(SDL_Texture * tex, SDL_Rect & dstRect, SDL_Rect * clip, float angle, int xPivot, int yPivot, SDL_RendererFlip flip)
	{
		siri::Draw(mRenderer, tex, dstRect, clip, angle, xPivot, yPivot, flip);
	}

	void Window::Draw(SDL_Texture * tex, int x, int y)
	{
		siri::Draw(mRenderer, tex, x, y);
	}

	SDL_Texture * Window::RenderText(const std::string & message, const std::string & fontFile, int fontSize, SDL_Color color)
	{
		return siri::RenderText(mRenderer, message, fontFile, fontSize, color);
	}

	void Window::RenderText(const std::string & message, const std::string & fontFile, int x, int y, int fontSize, SDL_Color color)
	{
		siri::RenderText(mRenderer, message, fontFile, x, y, fontSize, color);
	}

	void Window::Clear()
	{
		SDL_RenderClear(mRenderer);
	}

	void Window::Present()
	{
		SDL_RenderPresent(mRenderer);
	}

	SDL_Rect& Window::getSDLRect()
	{
		//Update mBox to match the current window size
		SDL_GetWindowSize(mWindow, &mBox.w, &mBox.h);
		return mBox;
	}

	Size& Window::getSize() {
		return Size(mBox.w, mBox.h);
	}

	SDL_Renderer* Window::getRenderer()
	{
		return mRenderer;
	}

}


