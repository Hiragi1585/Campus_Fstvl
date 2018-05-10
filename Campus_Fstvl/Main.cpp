//////////////////////////////////////////////
//		For Campus Festival Game
//		Programmed by Hiragi and Sekiya
//      Created in 5/8
//		
//		Use OpenSiv3D Version 0.2.5
//		CC License BY SA NC
//////////////////////////////////////////////

#include <Siv3D.hpp> // OpenSiv3D v0.2.5
#include <HamFramework.hpp>
#include "Define.h"


struct SharedData {
	int state;
	bool flag;
};

using MyGame = SceneManager<String, SharedData>;

class Title : public MyGame::Scene {
public:
	Title(const InitData& init) : IScene(init) {

	}

	void update() override {

	}

	void draw() const override {

	}
};

class Game : public MyGame::Scene {
public:
	Game(const InitData& init) : IScene(init) {

	}

	void update() override {

	}

	void draw() const override {

	}
};

class Credit : public MyGame::Scene {
public:
	Credit(const InitData& init) : IScene(init) {

	}

	void update() override {

	}

	void draw() const override {

	}
};

void Main()
{
		//System Initialize
	Window::Resize(WIDTH, HEIGHT);
	Graphics::SetTargetFrameRateHz(REFRESHRATE);

	MyGame manager;

	while (System::Update())
	{
		manager.update();
	}
}
