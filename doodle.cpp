#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
    
const int weight = 500;
const int height = 700;
int number_of_points = 0;

struct Plat
{ 
    int x = 0;
    int y = 0;
    float dy = 0;
};

void Platform(Plat* plat,  sf::RenderWindow* window) 
{ 
    int weightPlarform = 80;
    int heightPlatform = 15;

    sf::RectangleShape platform(sf::Vector2f(weightPlarform, heightPlatform)); 
    platform.setFillColor(sf::Color(150, 50, 250)); 
    for (int i = 0; i < 10 ;i++)
    {
        platform.setPosition(plat[i].x, plat[i].y); 
        window->draw(platform); 
    }

    int scroll = 200;

    if (plat -> y < scroll)
        for (int i = 0; i < 10; i++)
        {
            plat -> y = scroll;
            plat[i].y -=  plat -> dy;
            if (plat[i].y > height) 
                {
                    plat[i].y = 0; 
                    plat[i].x = rand() % weight;
                }
        }

    for (int i = 0; i < 10; i++)
    { 
        if(((plat -> x + 50) > plat[i].x) && ((plat -> x + 30) < (plat[i].x + weightPlarform)) && (plat -> y + 75 > plat[i].y) && (plat -> y + 75 < plat[i].y + heightPlatform) && (plat -> dy > 0))               
        {
            plat -> dy = -10;
            number_of_points += 1;
        }    
    }
} 

void Monster(Plat* plat, sf::RenderWindow* window) 
{ 
    sf::Texture monster, gameover;
    monster.loadFromFile("monster.png");
    gameover.loadFromFile("gameover.png");
    sf::Sprite spriteMonster(monster), spriteGameOver(gameover);
    spriteGameOver.setPosition(sf::Vector2f(100, 250));
    spriteMonster.setPosition(plat -> x, plat -> y); 

    plat -> dy += 0.15;
    plat -> y += plat -> dy;

    if (plat -> x < 0)
        plat -> x += 3;
    if ((plat -> x) > (weight - 80))
        plat -> x -= 3;

    if (plat -> y > 700)  
    {
        window -> draw(spriteGameOver);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
        plat -> x += 3; 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
        plat -> x -= 3; 

    window -> draw(spriteMonster); 
} 

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(weight, height), "Doodle Game!");

    sf::Texture background, menu, play,records, gameover;
    background.loadFromFile("1.jpg");
    menu.loadFromFile("menu.png");
    play.loadFromFile("play1.png");
    records.loadFromFile("records1.png");
    sf::Sprite spriteBack(background), spriteMenu(menu), spritePlay(play), spriteRecords(records);
    spritePlay.setPosition(sf::Vector2f(150, 200));
    spriteRecords.setPosition(sf::Vector2f(150, 320));
    int a = 0;
    int rec = 0;

    Plat* plat = new Plat[20];
    for (int i = 0; i < 10; i++) 
    { 
        plat[i].x = rand() % weight; 
        plat[i].y = rand() % height; 
    } 


    sf :: Font font;
    font.loadFromFile("calibri.ttf");
    sf::Text text; 
    text.setFont(font); 
    text.setCharacterSize(30);
    text.setFillColor(sf::Color(255, 255, 255));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.draw(spriteMenu);
        window.draw(spritePlay);
        window.draw(spriteRecords);

        if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (sf::IntRect(150, 200, 200, 100).contains(sf::Mouse::getPosition(window))))
        {
            a = a + 1;
        }

        if (a > 0)          
        {
            window.clear();
            window.draw(spriteBack);
            Platform(plat, &window);
            Monster(plat, &window);
        }

        if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (sf::IntRect(150, 320, 200, 100).contains(sf::Mouse::getPosition(window))))
        {
            rec = rec + 1;
        }

        if (rec > 0)          
        {
            window.clear();
            window.draw(spriteBack);
            text.setString("NUMBERS OF POINTS");
            text.setString(std::to_string(number_of_points));
            window.draw(text);

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
        {
            window.clear();
            a = 0;  
            rec = 0;      
        }

        window.display();
    }
    return 0;
}
