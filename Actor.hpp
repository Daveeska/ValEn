#pragma once

namespace valen {
	typedef struct {
		float x, y;
	} Vec2;

	typedef struct {
		int r, g, b;
	} Color;

	class Actor {
	protected:
		Vec2 position;
		Vec2 size;
		Color color;
	public:

		//Getter
		Vec2 getPos();
		Vec2 getSize();
		Color getColor();

		//Setter
		void setPos(Vec2 pos);
		void setSize(Vec2 size);
		void setColor(Color color);

		//Functions
		virtual void Init();
		virtual void Update(float dt);

		Actor();
		~Actor();
	};

}