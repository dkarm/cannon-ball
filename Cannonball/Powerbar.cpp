//
//  Powerbar.cpp
//  Cannonball
//
//  Created by Dipti Karmarkar on 8/17/16.
//  Copyright © 2016 Dipti Karmarkar. All rights reserved.
//

#include "Powerbar.hpp"

Powerbar::Powerbar(sf::RenderWindow &window): window(window)
{
    //initialize the outside rectangle
    outside.setPosition(5,5);
    pos.x = 100;
    pos.y = 20;
    
    outside.setSize(pos);
    outside.setFillColor(sf::Color::Black);
    outside.setOutlineColor(sf::Color::White);
    outside.setOutlineThickness(2.0);
    
    
    //initialize the inside rectangle
    inside.setPosition(5,5);
    //initialize number
    charge = 100;
    pos.x = charge;
    inside.setSize(pos);
    inside.setFillColor(sf::Color::Cyan);
}

void Powerbar::draw()
{
    window.draw(outside);
    window.draw(inside);
}

void Powerbar::startbar()
{
    if (activated==0)
    {
    charge -= speed;
    if (charge==0)
    {
        speed= -speed;
    }
    if (charge ==100)
    {
        speed = -speed;
    }
    pos.x = charge;
    inside.setSize(pos);
    }
}

int Powerbar::getstrength()
{
    return charge;
}

void Powerbar::stopbar()
{
    activated = 1;
}
