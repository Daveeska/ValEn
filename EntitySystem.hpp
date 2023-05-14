#pragma once

#include <vector>
#include <memory>

#include "Actor.hpp"

namespace valen {

	class EntitySystem {
	private:
		std::vector<std::unique_ptr<Actor>> actors;
	public:

		//Getter
		std::vector<std::unique_ptr<Actor>>& getActors();

		//Functions
		void AddActor(std::unique_ptr<Actor> actor);

		void UpdateActors(float dt);
		void InitActors();

		EntitySystem();


	};

}