#include "stdafx.h"
//#include <SFML/System.hpp>
//#include <SFML/Graphics.hpp>

#include "MapManager.h"
#include "SpriteManager.h"
#include <iostream>
using namespace std;

// Sample program to demonstrate basic usage of SFML library. Can also be used as a starting
//  point for the spatial hashing assignment.

int main() {
	 
	sf::RenderWindow window(sf::VideoMode(DemoConstants::SCREEN_WIDTH, DemoConstants::SCREEN_HEIGHT), "SFML Window");

	// Define a single line.
	sf::Vertex line1H[] = {
		sf::Vertex(sf::Vector2f(0, 200)),
		sf::Vertex(sf::Vector2f(800, 200))
	};

	sf::Vertex line2H[] = { 
		(sf::Vector2f(0, 400)),
		sf::Vertex(sf::Vector2f(800, 400))
	};

	sf::Vertex line3H[] = { 
		(sf::Vector2f(0, 600)),
		sf::Vertex(sf::Vector2f(800, 600))
	};
	

	sf::Vertex line1V[] = { 
		(sf::Vector2f(200, 0)),
		sf::Vertex(sf::Vector2f(200, 800))
	};

	sf::Vertex line2V[] = { 
		(sf::Vector2f(400, 0)),
		sf::Vertex(sf::Vector2f(400, 800))
	};

	sf::Vertex line3V[] = { 
		(sf::Vector2f(600, 0)),
		sf::Vertex(sf::Vector2f(600, 800))
	};

	// How to load an image
	sf::Image image;
    
	MapManager mapMgr;

	// How to create a sprite from that image.
	CustomSprite::init("chromatic_circle.png");

	// Make an instance of our sprite manager.
	SpriteManager spriteManager;

	vector<CustomSprite> & allSprites = spriteManager.getAllSprites();

    // Start game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
	
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

		
        // Clear the screen (fill it with black color)
		window.clear(sf::Color::Black);
		
		
		// How to draw a line.		
	    //window.draw(line, 2, sf::Lines);	
		window.draw(line1H, 2, sf::Lines);
		window.draw(line2H, 2, sf::Lines);
		window.draw(line3H, 2, sf::Lines);

		window.draw(line1V, 2, sf::Lines);
		window.draw(line2V, 2, sf::Lines);
		window.draw(line3V, 2, sf::Lines);
		for(int k = 0; k < allSprites.size(); k++ )
		{
			mapMgr.registerSprite(allSprites.at(k));
		}
		
			
		// How to draw a container of sprites.
		for ( int i = 0; i < allSprites.size(); ++i ) {							
			window.draw( allSprites.at(i) );						
		}
						
		
        // Display window contents on screen
        window.display();
    }
	

    return EXIT_SUCCESS;
}
