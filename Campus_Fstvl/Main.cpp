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
protected:
	int _sceneparam;
	bool _isChange;
	int _next;

public:
	BaseScene() {}

	virtual void init() {
		_isChange = false;
		_next = -1;
	}
	virtual void all() {
		update();
		draw();
	}

private:
	virtual bool update() { return true; }
	virtual bool draw() { return true; }
};

class Title : public BaseScene{
private:
	Array<String> _menutext = {
		U"Game Start!",
		U"Results",
		U"Credit",
		U"Exit"
	};

	Font _font;

public:
	Title() {}

	void init() override {
		_isChange = false;
		_next = -1;
		_font = Font(32);
	}


private:
	bool update() override{
		return true;
	}

	bool draw() override {
		for (auto [i,text] : Indexed(_menutext)) {
			_font(text).draw(0, i * 32, ColorF(1.0, 1.0, 1.0));
		}
		return true;
	}
};

class Game : public BaseScene {

};

class Result : public BaseScene {

};

class Credit : public BaseScene {

};

void Main()
{
		//System Initialize
	Window::Resize(WIDTH, HEIGHT);
	Graphics::SetTargetFrameRateHz(REFRESHRATE);

	int scene = eScene::TITLE;

	Title title;
	Game game;
	Result result;
	Credit credit;
	title.init();

	while (System::Update())
	{
		switch (scene) {

			case eScene::TITLE: {
				title.all();
				break;
			}

			case eScene::GAME: {
				break;
			}

			case eScene::RESULT: {
				break;
			}

			case eScene::CREDIT: {
				break;
			}

		}
	}
}
