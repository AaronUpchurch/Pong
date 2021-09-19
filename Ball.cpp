#include "Ball.h"
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;

bool Ball::checkIfScore() {
	if (getPosition().x <= 10 || getPosition().x >= 1000) {
		if (getPosition().x <= 10) ++playerTwoScore;
		else ++playerOneScore;
		point.play();
		path.clear();
		setPosition(500, 500);
		do{
			xVel = rand() % 10 - 5;
			yVel = rand() % 10 - 5;
		} 
		while (xVel == 0 || yVel == 0);
		
		return true;
	};

	return false;
};
void Ball::updateRectInfor(int userY, int compY) {
	this->userY = userY;
	this->compY = compY;
};
bool Ball::checkIfHitBound() {
	
	if (getPosition().y <= 10 || getPosition().y >= 990) {
		
		yVel = 0 - yVel; //speeds up ball //
		if (yVel < 0) --yVel;
		else ++yVel;
		setFillColor(randColor());
		return true;
	}
	return false;
};

bool Ball::checkIfHitRect() {

	bool atLeftRectX = abs(getPosition().x - 40) <= 20;
	bool atLeftRectY = getPosition().y >= userY && getPosition().y <= userY + 200;
	bool atRightRectX = abs(getPosition().x - 960) <= 20;
	bool atRightRectY = getPosition().y >= compY && getPosition().y <= compY + 200;
	if ( (atLeftRectX && atLeftRectY) || (atRightRectX && atRightRectY)) {
		
		soundBounce.setVolume(25);
		soundBounce.play();
		xVel = 0 - xVel;
		if (xVel < 0) {
			--xVel;
		}
		else {
			++xVel;
		}
		
		setFillColor(randColor());
		return true;
	}
	return false;
};
void Ball::update() {
	CircleShape pathBall(1);
	pathBall.setPosition(getPosition().x + 10, getPosition().y + 10);
	pathBall.setFillColor(getFillColor());
	path.push_back(pathBall);

	checkIfHitBound();
	checkIfHitRect();

	checkIfScore();
	move(xVel, yVel);
};
const Color Ball::randColor() {
	unsigned char r = (char)(rand() % 205 + 50);
	unsigned char g = (char)(rand() % 205 + 50);
	unsigned char b = (char)(rand() % 205 + 50);
	Color retColor(r, g, b);
	return retColor;
}