#include "stdafx.h"
#include <math.h>

#ifdef _DEBUG
#pragma comment(lib,"sfml-graphics-d.lib")
#pragma comment(lib,"sfml-audio-d.lib")
#pragma comment(lib,"sfml-system-d.lib")
#pragma comment(lib,"sfml-window-d.lib")
#pragma comment(lib,"sfml-network-d.lib")
#else

#pragma comment(lib,"sfml-graphics.lib")
#pragma comment(lib,"sfml-audio.lib")
#pragma comment(lib,"sfml-system.lib")
#pragma comment(lib,"sfml-window.lib")
#pragma comment(lib,"sfml-network.lib")
#endif

#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")

#include "SFML/Graphics.hpp"
#include "SFML/OpenGL.hpp"
#include <iostream>

//class triangle;

int _tmain(int argc, _TCHAR* argv[])
{
	 // Create the main window
    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SFML OpenGL");
    // Create a clock for measuring time elapsed    
    sf::Clock Clock;
    //prepare OpenGL surface for HSR
    glClearDepth(1.f);
    glClearColor(0.3f, 0.3f, 0.3f, 0.f); //background colour
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
   
    //// Setup a perspective projection & Camera position
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
     
    //set up a 3D Perspective View volume
    //gluPerspective(90.f, 1.f, 1.f, 300.0f);//fov, aspect, zNear, zFar
 
    //set up a  orthographic projection same size as window
    //this mease the vertex coordinates are in pixel space
    glOrtho(0,800,0,600,0,1); // use pixel coordinates
	sf::Vector2f iroot =  sf::Vector2f(10, 10);


   
       
    // Start game loop
    while (App.isOpen())
    {
        // Process events
        sf::Event Event;
        while (App.pollEvent(Event))
        {
            // Close window : exit
            if (Event.type == sf::Event::Closed)
                App.close();
   
            // Escape key : exit
            if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
                App.close();
             
    
        }
           
        //Prepare for drawing
        // Clear color and depth buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   
        // Apply some transformations
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
         
        double angle=Clock.getElapsedTime().asMilliseconds();

		int jimX[10];
		int jimY[10];
		for (int i = 0; i < 10; i++)
		{
			jimX[i] = 80 * i;
			jimY[i] = 60 * i;
		}



		glBegin(GL_LINES);



		glEnd(); 




        // Finally, display rendered frame on screen
        App.display();
    }
   
    return EXIT_SUCCESS;
}

