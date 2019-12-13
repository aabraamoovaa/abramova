#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

int main()
{
    int width = 900;
    int hight = 700;
    sf::RenderWindow window(sf::VideoMode(width, hight), "hack!");

    char s[3];
    int a = 0;
    int b = 0;
    int size = 15;
    int counter = 0;
    int number = hight / (size + 6);
    int yPos = 0;

    std :: string c;
    std :: fstream f("fail.txt");
    f.seekg(0, f.end);

    sf :: Font font;
    font.loadFromFile("calibri.ttf");
    sf::Text text; 
    text.setFont(font); 
    text.setCharacterSize(size);
    text.setFillColor(sf::Color(0, 255, 0));

    while(window.isOpen())
    {    
        sf::Event event;
        while (window.pollEvent(event)) 
        {   
            if (event.type == sf::Event::Closed) 
                window.close();
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code >= sf::Keyboard::A && event.key.code <= sf::Keyboard::Z) 
                {   
                    f.seekg(a, f.beg);
                    f.read(s, 3);
                    a += 3;
                    c += s;
                    text.setString(c);
                    window.draw(text);
                }    
                
                for (int i = 0; i < number; i++)  
                {
                    if(s[i] == '\n')
                    {
                        counter += 1;   
                        yPos = text.getPosition().y;
                        if(counter > number) 
                        {
                            window.clear();
                            yPos = yPos - text.getCharacterSize();
                            text.setPosition(0, yPos);
                            window.draw(text);
                        }
                    }                    
                } 
            }
            window.display();
        }
    }
    return 0;
}
