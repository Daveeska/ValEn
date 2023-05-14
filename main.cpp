#include "World.hpp"
#include "Actor.hpp"

#include <iostream>
#include <memory>

class myActor : public valen::Actor {
public:

	myActor() {
		position = { 0,0 };
		size = { 100,100 };
		color = { 255,0,0 };
	}

	void Init() override {
	}

	void Update(float dt) override {
		//position.x += 100 * dt;
		std::cout << position.x << std::endl;
	}
	
	~myActor() {

	}

};

int main(int argc, char **argv) {

	valen::World* world = new valen::World();
	world->Init();

	world->addActor(std::make_unique<myActor>());

	world->initActor();
	world->Update();

	return 0;
}