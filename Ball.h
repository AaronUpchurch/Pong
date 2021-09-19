#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;
class Ball : public CircleShape {
public:
	int userY;
	int compY;
	float xVel;
	float yVel;
	int playerOneScore;
	int playerTwoScore;
	SoundBuffer bounce;
	Sound soundBounce;
	SoundBuffer pointBuffer;
	Sound point;
	
	vector<CircleShape> path;
	bool checkIfScore();
	bool checkIfHitBound();
	bool checkIfHitRect();
	void update();
	void updateRectInfor(int userY, int compY);
	const Color randColor();
	Ball(float xVel, float yVel, float radius) : CircleShape(radius) {
		this->xVel = xVel;
		this->yVel = yVel;
		bounce.loadFromFile("C:/Users/aaron/source/repos/Pong/Pong/bounce.wav");
		pointBuffer.loadFromFile("C:/Users/aaron/source/repos/Pong/Pong/point.wav");
		point.setBuffer(pointBuffer);
		soundBounce.setBuffer(bounce);
		int playerOneScore = 0;
		int playerTwoScore = 0;
	}
	
};