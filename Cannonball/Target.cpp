//
//  Target.cpp
//  Cannonball
//
//  Created by Dipti Karmarkar on 8/17/16.
//  Copyright © 2016 Dipti Karmarkar. All rights reserved.
//

#include "Target.hpp"


Target::Target(sf::RenderWindow &window): window(window)
{
    target.setPosition(750, 300);
    target.setFillColor(sf::Color::Red);
    
    pos.x = 20;
    pos.y = 20;
    
    target.setSize(pos);
    
    
}

void Target::draw()
{
    return window.draw(target);
}

sf::FloatRect Target::get_position()
{
    return target.getGlobalBounds();
}