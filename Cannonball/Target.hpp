//
//  Target.hpp
//  Cannonball
//
//  Created by Dipti Karmarkar on 8/17/16.
//  Copyright © 2016 Dipti Karmarkar. All rights reserved.
//

#ifndef Target_hpp
#define Target_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Target
{
public:
    Target(sf::RenderWindow &window);
    sf::FloatRect get_position();
    void draw();
    
    
private:
    sf::RectangleShape target;
    sf::RenderWindow &window;
    sf::Vector2f pos;
    
    
    
    
};

#endif /* Target_hpp */
