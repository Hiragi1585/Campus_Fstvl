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
#include "BaseScene.h"
#include "Title.h"
#include "Game.h"
#include "Result.h"
#include "Credit.h"


void Main()
{
		//System Initialize
	Window::Resize(WIDTH, HEIGHT);
	Graphics::SetTargetFrameRateHz(REFRESHRATE);
		//Scene Initialize
	int scene = eScene::TITLE;

	BaseScene* title,game,result,credit;

	title = new Title();


	title->init();

	while (System::Update())
	{
		switch (scene) {

			case eScene::TITLE: {
				title->all();
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
