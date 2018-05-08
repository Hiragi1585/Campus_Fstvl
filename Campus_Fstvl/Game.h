#pragma once

#include "BaseScene.h"

class Game : public BaseScene {
public:
	Game();
	void init() override;
private:
	bool update() override;
	bool draw() override;
};