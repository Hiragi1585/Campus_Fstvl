//////////////////////////////////////////////
//		For Campus Festival Game
//		Programmed by Hiragi and Sekiya
//      Created at 5/8
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
private:
	String _titleText = U"Prototype!!";
	Array<String> _menuText = {
		U"Game Start",
		U"Credit",
		U"Exit",
	};
	Array<Rect> _menuBoxes;
	Vec2 _basePos = Vec2(720, 380);
	Font _menuFont;
	Font _titleFont;
	Stopwatch _stopwatch;


public:
	Title(const InitData& init) : IScene(init) {
		_stopwatch.start();
		_menuFont = Font(48);
		_titleFont = Font(96);
		_menuBoxes.resize(_menuText.size());
		for (auto i : step(_menuBoxes.size())) {
				//箱の位置を指定
			_menuBoxes[i].set(_basePos.x + i * 30, _basePos.y + i * 100, _menuFont(_menuText[i]).region().w, _menuFont(_menuText[i]).region().h);
				//左右を少し拡張、上下もわずかに拡張
			_menuBoxes[i] = _menuBoxes[i].stretched(16,0);
		}
	}

	void update() override {
		for (auto i : step(_menuBoxes.size())) {
			const Quad quad = _menuBoxes[i].shearedX(4.0);
			
			if (quad.mouseOver()) {
				_menuBoxes[i].set(_basePos.x + i * 30-30, _basePos.y + i * 100, _menuFont(_menuText[i]).region().w+60, _menuFont(_menuText[i]).region().h);
			}
			else {
				_menuBoxes[i].set(_basePos.x + i * 30, _basePos.y + i * 100, _menuFont(_menuText[i]).region().w, _menuFont(_menuText[i]).region().h);
				_menuBoxes[i] = _menuBoxes[i].stretched(16, 0);
			}

			if (quad.leftClicked()) {
				switch (i) {
				case 0:
					changeScene(U"Game");
					break;
				case 1:
					changeScene(U"Credit");
					break;
				case 2:
					System::Exit();
					break;
				}
			}
		}
	}

	void draw() const override {

		_titleFont(_titleText).drawAt(Window::Center()-Point(200,200));

		for (auto i : step(_menuBoxes.size())) {
				//平行四辺形にして描画
			_menuBoxes[i].shearedX(4.0).draw();
			_menuFont(_menuText[i]).drawAt(_menuBoxes[i].center(),Palette::Black);
		}
	}
};

class Game : public MyGame::Scene {
private:
	String _text = U"Game Scene!";
	Font _font;

	class Bullet {
	private:
		Vec2 _pos;
		Vec2 _v;
		double ang;
		Circle _circle;
		bool rm = false;

	public:
		Bullet() {}
		void init(Vec2 pos,double speed,double angle,double r) {
			_pos = pos;
			_v = Vec2(Math::Cos(angle)*speed, Math::Sin(angle)*speed);
			_circle = Circle(_pos, r);
		}
		void update() {
			_pos = _pos.moveBy(_v);
			_circle.setPos(_pos);
			if (_pos.x < 0 || _pos.y < 0 || Window::Width() < _pos.x || Window::Height() < _pos.y) {
				rm = true;
			}
		}

		void draw() {
			//Print << _v;
			_circle.draw(Palette::Wheat);
		}

		Circle getBullet() {
			return _circle;
		}

		void erase() { delete this; }
		bool isErasable() { return rm; }


	};

	//Player class
	class Player {
	private:
		Vec2 _pos;
		Vec2 _v;
		Circle _circle;
		Array<Bullet*> bullets;

		
		int hp;
		const double speed = 10.0;
	public:
		Player() {}

		void init(Vec2 pos) {
			hp = 0;
			_v = Vec2::Zero();
			_pos = pos;
			_circle = Circle(_pos, 24);
		}

		void update() {
			if (KeyRight.pressed())
				_v = Vec2::Right(speed);
			if (KeyLeft.pressed())
				_v = Vec2::Left(speed);
			if (!(KeyLeft.pressed() || KeyRight.pressed()))
				_v = Vec2::Zero();

			if (KeyZ.pressed() && System::FrameCount()%1 == 0) {
				Bullet *tmp = new Bullet();
				tmp->init(_pos, (System::FrameCount()%10)*0.4+10,Math::Pi*6/4, 4);
				bullets.push_back(tmp);
			}


			for (auto itr = bullets.begin(); itr != bullets.end();) {
				if ((*itr)->isErasable()) {
					(*itr)->erase();
					itr = bullets.erase(itr);
				}
				else {
					(*itr)->update();
					itr++;
				}
			}

			_pos = _pos.moveBy(_v);
			_circle.setPos(_pos);
		}

		void draw() const {
			for (const auto& bullet : bullets) {
				bullet->draw();
			}
			_circle.draw();
		}
		
		
	};

	Player _player;

public:
	Game(const InitData& init) : IScene(init) {
		_player.init(Vec2(Window::Width()/2,600));
		_font = Font(50);
	}

	void update() override {
		_player.update();
		if (MouseL.pressed()) {
			changeScene(U"Title");
		}
	}

	void draw() const override {
		_player.draw();
	}
};

class Credit : public MyGame::Scene {
private:
	String _text = U"Credit Scene!";
	Font _font;
public:
	Credit(const InitData& init) : IScene(init) {
		_font = Font(50);
	}

	void update() override {
		if (MouseL.pressed()) {
			changeScene(U"Title");
		}
	}

	void draw() const override {
		_font(_text).draw(0, 0, Palette::Aqua);
	}
};

void Main()
{
		//System Initialize
	Window::Resize(WIDTH, HEIGHT);
	Graphics::SetTargetFrameRateHz(REFRESHRATE);

	MyGame manager;
	manager.add<Title>(U"Title");
	manager.add<Game>(U"Game");
	manager.add<Credit>(U"Credit");
	while (System::Update())
	{
		manager.update();
	}
}
