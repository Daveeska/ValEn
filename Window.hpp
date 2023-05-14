#pragma once

#include <SDL.h>
#include <string>


namespace valen {
	class Window {
	private:
		//Window property
		std::string title;
		int width, height;
		bool isClosed;

		//SDL stuff
		SDL_Window* sdl_window;
		SDL_Event sdl_event;

	public:

		//Getter
		bool& isWindowClosed();
		int getWidth();
		int getHeight();
		std::string getTitle();

		SDL_Renderer* sdl_renderer;
		
		//Functions
		void Init();
		void Update();
		void pollEvents();

		Window(std::string title, int width, int height);
		~Window();

	};
}