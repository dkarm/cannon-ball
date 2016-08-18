//
//  Powerbar.hpp
//  Cannonball
//
//  Created by Dipti Karmarkar on 8/17/16.
//  Copyright © 2016 Dipti Karmarkar. All rights reserved.
//

#ifndef Powerbar_hpp
#define Powerbar_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Powerbar
{
public:
    Powerbar(sf::RenderWindow &window);
    void draw();
    void startbar();
    int getstrength();
    void stopbar();
    
    
private:
    int charge;
    sf::RenderWindow &window;
    sf::RectangleShape outside;
    sf::RectangleShape inside;
    sf::Text numberdisplay;
    sf::Vector2f pos;
    int speed = 1;
    int activated =0;
    
};

#endif /* Powerbar_hpp */
