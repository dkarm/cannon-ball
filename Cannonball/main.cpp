

#include <SFML/Graphics.hpp>


#include "Powerbar.hpp"
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
    window.setFramerateLimit(30);
    
    //control on the power
    int power = 0;

    
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
    
        

        // Clear screen
        window.clear();

        //show the bar
        bar.draw();
        
        //show message
        window.draw(message);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
