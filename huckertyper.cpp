#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 700), "hucker");
    char s[3];
    int len = 0;
    int a = 0;
    std :: string c;
    while(window.isOpen())
    {    
        std :: fstream f("fail.txt");
        f.seekg(0, f.end);
        len = f.tellg();

        sf :: Font font;
        font.loadFromFile("calibri.ttf");
        sf::Text text;
        text.setFont(font); 
        text.setCharacterSize(15);
        text.setFillColor(sf::Color(0, 255, 0));

        sf::Event event;
        while (window.pollEvent(event)) 
        {   
            if (event.type == sf::Event::Closed) 
                window.close();
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code >= sf::Keyboard::Space)
                {                              
                    text.setString("ACCESS IS DENIED");
                    text.setCharacterSize(50);
                    text.setFillColor(sf::Color(255, 0, 0));
                    text.setPosition(230, 300);
                    window.draw(text);
                } 
                if(event.key.code >= sf::Keyboard::A && event.key.code <= sf::Keyboard::Z) 
                {   
                    window.clear();       
                    f.seekg(a, f.beg);
                    f.read(s, 3);
                    a += 3;
                    c += s;
                    text.setString(c);
                    window.draw(text);
                }                   
            }
            window.display();
        }
    }
    return 0;
}
