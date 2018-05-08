#pragma once

#include "BaseScene.h"

class Credit : public BaseScene {
public:
	Credit();
	void init() override;
private:
	bool update() override;
	bool draw() override;
};
