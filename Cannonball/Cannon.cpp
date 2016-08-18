//
//  Cannon.cpp
//  Cannonball
//
//  Created by Dipti Karmarkar on 8/17/16.
//  Copyright © 2016 Dipti Karmarkar. All rights reserved.
//

#include "Cannon.hpp"

Cannon::Cannon(sf::RenderWindow &window, sf::Texture cannon_icon): window(window)
{
    cannon.setTexture(cannon_icon);
    cannon.setPosition(400, 0);
}

void Cannon::draw()
{
    window.draw(cannon);
}