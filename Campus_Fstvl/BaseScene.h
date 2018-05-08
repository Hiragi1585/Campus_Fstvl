#pragma once

#include <Siv3D.hpp>

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
	virtual bool all() {
		update();
		draw();
		return _isChange;
	}

private:
	virtual bool update() { return true; }
	virtual bool draw() { return true; }
};