#include "EntitySystem.hpp"

#include <iostream>

std::vector<std::unique_ptr<valen::Actor>>& valen::EntitySystem::getActors() {
	return actors;
}

void valen::EntitySystem::UpdateActors(float dt) {
	for (std::unique_ptr<Actor>& e : actors) {
		e->Update(dt);
	}
}

void valen::EntitySystem::InitActors()
{
	for (std::unique_ptr<Actor>& e : actors) {
		e->Init();
	}
}

void valen::EntitySystem::AddActor(std::unique_ptr<Actor> actor) {
	this->actors.emplace_back(std::move(actor));
}

valen::EntitySystem::EntitySystem() {
	std::cout << "Entity system has been constructed with 0 member initialized. \n";
}