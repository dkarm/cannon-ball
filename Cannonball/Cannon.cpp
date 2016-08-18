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
    cannon.setPosition(10, 400);
    cannon.setScale(0.5,0.5);
    origin = cannon.getGlobalBounds();
    cannon.setOrigin(origin.left,-origin.height);
    
}

void Cannon::draw()
{
    window.draw(cannon);

}

void Cannon::set_rotation(int direction)
{
    if (direction ==1 & rotation >-45)
    {
        rotation -= rotation_speed;
    }
    if (direction ==2 & rotation <45)
    {
        rotation += rotation_speed;
    }
        
    cannon.setRotation(rotation);
}

