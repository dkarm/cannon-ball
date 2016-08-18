//
//  Cannon.hpp
//  Cannonball
//
//  Created by Dipti Karmarkar on 8/17/16.
//  Copyright © 2016 Dipti Karmarkar. All rights reserved.
//

#ifndef Cannon_hpp
#define Cannon_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Cannon
{
public:
    Cannon(sf::RenderWindow &window,sf::Texture &cannon_icon);
    int get_rotation();
    void set_rotation(int direction);
    void draw();
    
    
    
    
private:
    sf::RenderWindow &window;
    sf::Sprite cannon;
    float rotation;
    float rotation_speed = 1;
    sf::FloatRect origin;
    
    
    
};

#endif /* Cannon_hpp */
