#include "Window.hpp"

#include <iostream>

bool& valen::Window::isWindowClosed() {
	return isClosed;
}

std::string valen::Window::getTitle()
{
    return title;
}

int valen::Window::getWidth()
{
    return width;
}

void valen::Window::Init() {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Failed to initialize SDL(video). \n";
        return;
    }
    else {
        std::cout << "SDL has been initialize. \n";
    }

    sdl_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (sdl_window == nullptr) {
        std::cerr << "Failed to create window. \n";
        return;
    }
    else {
        std::cout << "(SDL) Window has been created. \n";
    }

    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (sdl_renderer == nullptr) {
        std::cerr << "Failed to create renderer. \n";
        return;
    }
    else {
        std::cout << "(SDL) Renderer has been created. \n";
    }
}

int valen::Window::getHeight()
{
    return height;
}

void valen::Window::Update() {
    pollEvents();

    SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, 255);
    SDL_RenderClear(sdl_renderer);

    SDL_RenderPresent(sdl_renderer);

}

void valen::Window::pollEvents() {
	if (SDL_PollEvent(&sdl_event)) {
		switch (sdl_event.type) {
		case SDL_QUIT:
			isClosed = true;
			break;
		default:
			break;
		}
	}
}

valen::Window::Window(std::string title, int width, int height) {
	this->title = title;
	this->width = width;
	this->height = height;
}

valen::Window::~Window() {
	SDL_DestroyRenderer(sdl_renderer);
    SDL_DestroyWindow(sdl_window);

    SDL_Quit();
}