#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <chrono>
#include <thread>
#include "CustomRect.h"
#include "Ball.h"
#include <iostream>
#include <vector>
using namespace std;
using namespace sf;
void sleepMili(int num);
bool gameOver(Ball& ball);
const Color randColor();
int main() {

    
    RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    Music music;
    if (music.openFromFile("C:/Users/aaron/source/repos/Pong/Pong/music.wav")) {
        music.play();
    }
    music.setLoop(true);
    Text score;
    int playerOneScore = 0;
    int playerTwoScore = 0;
    Font font;
    font.loadFromFile("C:/Users/aaron/source/repos/Pong/Pong/Minecraft.ttf");
    score.setFont(font);
    score.setString(to_string(playerOneScore) + " : " + to_string(playerTwoScore));
    score.setCharacterSize(30);
    score.setFillColor(Color::White);
    score.setPosition({ 470,480 });
    CustomRect user(0, { 20,200 }, false);
    CustomRect comp(0, { 20,200 }, true);
    Ball ball(rand() % 10 - 5, rand() % 10 - 5,10);
    vector<RectangleShape> starBackround;
    for (int i = 0; i < 400; ++i) {
        RectangleShape star;
        star.setPosition(rand() % 1000, rand() % 1000);
        star.setSize({ 1,1 });
        starBackround.push_back(star);
    };
    ball.setPosition(500, 500);
    user.setPosition(40, 100);
    comp.setPosition(960, 100);
    

    comp.setFillColor(Color::White);
    user.setFillColor(Color::White);
    ball.setFillColor(Color::Red);
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        sleepMili(15);

        if (gameOver(ball)) {
            Text winMessage;
            Font winFont;
            winFont.loadFromFile("C:/Users/aaron/source/repos/Pong/Pong/Minecraft.ttf");
            winMessage.setFont(winFont);
            if (ball.playerOneScore >= 3) {
                winMessage.setString("Player One Wins !");
            }
            else {
                winMessage.setString("Player TwoA Wins !");
            }
            winMessage.setCharacterSize(50);
            winMessage.setFillColor(Color::White);
            winMessage.setPosition({ 300,400 });
            
            window.draw(winMessage);
            window.display();
            sleepMili(3000);
            window.clear();
            ball.playerOneScore = 0;
            ball.playerTwoScore = 0;
        }
        
        user.update();
        ball.update();
        comp.update();

        ball.updateRectInfor(user.getPosition().y, comp.getPosition().y);

        window.clear();
        
        window.draw(user);
        window.draw(ball);
        window.draw(comp);
        score.setString(to_string(ball.playerOneScore) + " : " + to_string(ball.playerTwoScore));
        window.draw(score);
        for (int i = 0; i < ball.path.size(); ++i) {
            window.draw(ball.path.at(i));
        }
        for (int i = 0; i < starBackround.size(); ++i) {
            
            window.draw(starBackround.at(i));
        }
        
        window.display();
    }
}
void sleepMili(int num) {
    chrono::milliseconds dura(num);
    this_thread::sleep_for(dura);
}
bool gameOver(Ball& ball) {
    return(ball.playerOneScore >= 3 || ball.playerTwoScore >= 3);
}
const Color randColor() {
    unsigned char r = (char)(rand() % 255);
    unsigned char g = (char)(rand() % 255);
    unsigned char b = (char)(rand() % 255);
    Color retColor(r, g, b);
    return retColor;
}

