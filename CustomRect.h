#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
using namespace sf;
class CustomRect : public RectangleShape {
public:
	bool isPlayerTwo;
	float yVel;
	void update();
	bool checkForBound();
	CustomRect(float yVel, Vector2f pos, bool isPlayerTwo) : RectangleShape(pos) {
		this->yVel = yVel;
		this->isPlayerTwo = isPlayerTwo;
	};
	
};