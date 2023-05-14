#pragma once

#include "Window.hpp"
#include "SoundSystem.hpp"
#include "EntitySystem.hpp"
#include "InputManager.hpp"

#include <memory>

namespace valen {
	class World {
	private:
		Window* gameWindow;
		SoundSystem* w_SoundSystem;
		EntitySystem* w_EntitySystem;
		InputManager* w_InputManager;
	public:

		//Getter
		Window* getWindow();
		SoundSystem* getSoundSystem();
		EntitySystem* getEntitySystem();
		InputManager* getInputManager();

		//Functions
		void addActor(std::unique_ptr<Actor> actor);

		void Update();
		void Init();

		void initActor();

		World();

	};
}