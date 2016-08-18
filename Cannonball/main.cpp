

#include <SFML/Graphics.hpp>


#include "Powerbar.hpp"
#include "Cannon.hpp"
#include "Target.hpp"
#include "Ball.hpp"
#include <sstream>

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    
    //create the powerbar
    Powerbar bar(window);
    
    //create text
    sf::Text message;
    
    //set text color
    message.setColor(sf::Color::White);
    
    //load a font
    sf::Font font;
    font.loadFromFile("/Users/diptikarmarkar/Documents/GD/Cannonball/Cannonball/Sansation.ttf");
    
    //set a font
    message.setFont(font);
    
    //set size
    message.setCharacterSize(25);
    
    //set position
    message.setPosition(110, 0);
    
    //set frame
    window.setFramerateLimit(60);
    
    //control on the power
    int power = 0;
    
    //load the cannon image
    sf::Texture cannon_icon;
    cannon_icon.loadFromFile("/Users/diptikarmarkar/Documents/GD/Cannonball/Cannonball/A_cannon.png");
    
    //create a class using the cannon
    Cannon cannon1(window, cannon_icon);
    
    //create a ball object
    Ball ball(cannon1.get_rotation(), cannon1.get_midpoint(), cannon1.get_width(),0, window);
    
    //to see if shot fired
    int shot = 0;
    
    //set target
    Target target(window);
    
    //set new text
    sf::Text winner;
    winner.setFont(font);
    winner.setCharacterSize(100);
    winner.setPosition(250,250);
    winner.setColor(sf::Color::White);

    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        
        //start moving the bar
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            bar.startbar();
            power++;
        }
        
        //stop the bar once the space key is released & assign a power number
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && power>0)
        {
            bar.stopbar();
        }
        
            
        //set message text
        std::stringstream ss;
        ss << bar.getstrength();
        message.setString(ss.str());
        
        
        //rotate the cannon
        if (power>0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            cannon1.set_rotation(1);
            ball.update_position(cannon1.get_rotation(), cannon1.get_width(), cannon1.get_midpoint());
        }
    
        if (power>0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            cannon1.set_rotation(2);
            ball.update_position(cannon1.get_rotation(), cannon1.get_width(), bar.getstrength());
        }
        
        if (power >0 && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                shot =1;
            }
        
        if (shot >0)
            {
                ball.shoot();
            }
        
        if(ball.get_position().intersects(target.get_position()))
        {
            winner.setString("You win");
        }
        

        // Clear screen
        window.clear();

        //show the bar
        bar.draw();
        
        //show the cannon
        cannon1.draw();
        
        //draw the ball
        ball.draw();
        
        //draw target
        target.draw();
        
        //draw the winner message
        window.draw(winner);
        
        //show message
        window.draw(message);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
