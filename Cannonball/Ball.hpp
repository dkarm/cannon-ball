//
//  Ball.hpp
//  Cannonball
//
//  Created by Dipti Karmarkar on 8/17/16.
//  Copyright © 2016 Dipti Karmarkar. All rights reserved.
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Ball
{
    
public:
    Ball(int rotation, int height, int width, int speed, sf::RenderWindow &window);
    sf::FloatRect get_position();
    void draw();
    void update_position(int rotation, int width, int speed);
    void update_speed(int speed);
    void shoot();
    
    
    
private:
    float xposition;
    float yposition;
    float xvelocity;
    float yvelocity;
    sf::RenderWindow &window;
    sf::CircleShape ball;
    
    
};



#endif /* Ball_hpp */
