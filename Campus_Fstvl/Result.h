#pragma once

#include "BaseScene.h"

class Result : public BaseScene {
public:
	Result();
	void init() override;
private:
	bool update() override;
	bool draw() override;
};