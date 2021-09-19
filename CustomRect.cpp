#include "CustomRect.h"
#include <Windows.h>
using namespace std;
using namespace sf;

void CustomRect::update() {
	int rectSpeed = 15;
	checkForBound();
	if (isPlayerTwo) {
		if (GetAsyncKeyState(VK_UP)) {
			move(0, -rectSpeed);
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			move(0, rectSpeed);
		}
	}
	else {
		if (GetAsyncKeyState(0x57)) {
			move(0, -rectSpeed);
		}
		if (GetAsyncKeyState(0x53)) {
			move(0, rectSpeed);
		}
	}
	
}
bool CustomRect::checkForBound() {
	if (getPosition().y >= 800) {
		setPosition(getPosition().x, 800);
		return true;
	}
	else if (getPosition().y <= 0) {
		setPosition(getPosition().x, 0);
		return true;
	}
	return false;
}
