#include "Title.h"

Title::Title() {

}

void Title::init() {
	_isChange = false;
	_next = -1;
	_font = Font(32);
}

bool Title::update() {
	return true;
}

bool Title::draw() {
	for (auto[i, text] : Indexed(_menutext)) {
		_font(text).draw(0, i * 32, ColorF(1.0, 1.0, 1.0));
	}
	return true;
}


