#include "World.hpp"

#include <iostream>

valen::Window* valen::World::getWindow()
{
    return gameWindow;
}

valen::SoundSystem* valen::World::getSoundSystem()
{
    return w_SoundSystem;
}

valen::EntitySystem* valen::World::getEntitySystem()
{
    return w_EntitySystem;
}

valen::InputManager* valen::World::getInputManager()
{
    return w_InputManager;
}

void valen::World::Init() {

    std::cout << "\" " << gameWindow->getTitle() << " \"" << "Is staring... \n";

    this->gameWindow->Init();
    this->w_SoundSystem->Init();
    this->w_InputManager->Init();
}

void valen::World::initActor() {
    this->w_EntitySystem->InitActors();
}

valen::World::World()
{
    this->gameWindow = new valen::Window("TDS-Reworked 0.1a (engine build test b). ValEn 2.0a", 1280, 720);
    this->w_EntitySystem = new valen::EntitySystem();
    this->w_InputManager = new valen::InputManager();
    this->w_SoundSystem = new valen::SoundSystem();
}

void valen::World::addActor(std::unique_ptr<Actor> actor)
{
    this->w_EntitySystem->AddActor(std::move(actor));
}

void valen::World::Update() {
    while (!gameWindow->isWindowClosed()) {
        this->gameWindow->Update();
        this->w_SoundSystem->Update(1.0f);
        this->w_InputManager->Update(1.0f);
        this->w_EntitySystem->UpdateActors(1.0f);

        for (std::unique_ptr<Actor>& e : w_EntitySystem->getActors()) {
            SDL_Rect rect = {e->getPos().x, e->getPos().y, e->getSize().x, e->getSize().y};
            SDL_SetRenderDrawColor(gameWindow->sdl_renderer, e->getColor().r, e->getColor().g, e->getColor().b, 255);
            SDL_RenderFillRect(gameWindow->sdl_renderer, &rect);
        }

    }

    std::cout << "\" " << gameWindow->getTitle() << " \"" << "has ended... \n";
}