//////////////////////////////////////////////
//		For Campus Festival Game
//		Programmed by Hiragi and Sekiya
//      Created in 5/8
//		
//		Use OpenSiv3D Version 0.2.5
//		CC License BY SA NC
//////////////////////////////////////////////

#include <Siv3D.hpp> // OpenSiv3D v0.2.5
#include "Define.h"

enum eScene{
	TITLE,
	GAME,
	RESULT,
	CREDIT,
};

class BaseScene {
	//Base class of scene
};

class Title {
private:
	Array<String> _menutext = {
		U"Game Start!",
		U"Results",
		U"Credit",
		U"Exit"
	};

	Font font;


	int _sceneparam;

public:
	Title() {
		font = Font(32);
	}

	int all() {
		update();
		draw();
	}
private:
	bool update() {
		return true;
	}

	bool draw() {
		for (auto [i,text] : Indexed(_menutext)) {
			font(text).draw(0, i * 32, ColorF(1.0, 1.0, 1.0));
		}
		return true;
	}
};

void Main()
{
		//System Initialize
	Window::Resize(WIDTH, HEIGHT);
	Graphics::SetTargetFrameRateHz(REFRESHRATE);

	int scene = eScene::TITLE;

	Title title;

	while (System::Update())
	{
		title.all();
	}
}
