//
//  Ball.cpp
//  Cannonball
//
//  Created by Dipti Karmarkar on 8/17/16.
//  Copyright © 2016 Dipti Karmarkar. All rights reserved.
//

#include "Ball.hpp"
#include <math.h>


Ball::Ball(int rotation, int height, int width, int speed,sf::RenderWindow &window): window(window)
{
    ball.setRadius(10.0);
    xposition = 50 + width*cos(rotation * 3.14159 /180);
    yposition = 550;
    ball.setFillColor(sf::Color::White);
    ball.setPosition(xposition,yposition);
}

void Ball::draw()
{
    window.draw(ball);
}

void Ball::update_position(int rotation, int width,int speed)
{
    xposition = 50 + width*cos(rotation * 3.14159 /180);
    yposition = 550 + width*sin(rotation * 3.14159 / 180);
    xvelocity = speed*cos(rotation * 3.14159 / 180);
    yvelocity = speed*sin(rotation * 3.14159 / 180);
    ball.setFillColor(sf::Color::White);
    ball.setPosition(xposition,yposition);
}

void Ball::shoot()
{
    xposition += xvelocity;
    yposition += yvelocity;
    yvelocity = yvelocity+0.3;
    ball.setPosition(xposition,yposition);
}

sf::FloatRect Ball::get_position()
{
    return ball.getGlobalBounds();
}