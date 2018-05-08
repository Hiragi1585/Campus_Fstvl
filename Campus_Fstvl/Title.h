#pragma once

#include "BaseScene.h"

class Title : public BaseScene {
private:
	Array<String> _menutext = {
		U"Game Start!",
		U"Results",
		U"Credit",
		U"Exit"
	};

	Font _font;

public:
	Title();
	void init() override;
private:
	bool update() override;
	bool draw() override;
};

