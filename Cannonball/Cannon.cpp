//
//  Cannon.cpp
//  Cannonball
//
//  Created by Dipti Karmarkar on 8/17/16.
//  Copyright © 2016 Dipti Karmarkar. All rights reserved.
//

#include "Cannon.hpp"

Cannon::Cannon(sf::RenderWindow &window, sf::Texture &cannon_icon): window(window)
{
    cannon.setTexture(cannon_icon);
    cannon.setPosition(50, 550);
    cannon.setScale(0.3,0.3);
    origin = cannon.getGlobalBounds();
    cannon.setOrigin(0,origin.height/2);
    
}

void Cannon::draw()
{
    window.draw(cannon);

}

void Cannon::set_rotation(int direction)
{
    if (direction ==1 & rotation >-65)
    {
        rotation -= rotation_speed;
    }
    if (direction ==2 & rotation <0)
    {
        rotation += rotation_speed;
    }
    cannon.setRotation(rotation);
}

int Cannon::get_rotation()
{
    return rotation;
}

int Cannon::get_width()
{
    return origin.width;
}

int Cannon::get_midpoint()
{
    return origin.height/2;
}