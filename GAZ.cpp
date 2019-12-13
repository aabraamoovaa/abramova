#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cmath>
#include "vector.h"

const float dt = 0.1;
const int vmax = 15;
const float height = 600;
const float weight = 800;

class Ball
{
    public:
	    Vector2f position;
	    Vector2f velocity;

	    float r = 10;
	    float red = 138;
	    float green= 43;
	    float blue = 226;

	    Ball(Vector2f position, Vector2f velocity, float r, int red, int green, int blue); 
	    Ball();

	    void drawBall(sf::RenderWindow* window)
	    {
	        sf::CircleShape shape(this->r);
	        for (int i = this->r; i > 1; i = i - 1)
	        {
	            shape.setRadius(i);
	            shape.setFillColor(sf::Color(this->red -(this->red * i / this->r), this->green -(this->green * i / this->r), this->blue -(this->blue * i / this->r)));
	            shape.setPosition(this->position.x - i, this->position.y - i);
	            window->draw(shape);
	        }
	    }
	    
	   void moveBall(float dt)
	    {   
	        this->position.x += this->velocity.x * dt;
	        this->position.y += this->velocity.y * dt;

	        if ( this->position.x > (weight - this->r) or this->position.x < this->r)
	            this->velocity.x = -this->velocity.x;
	        if ( this->position.y > (height - this->r) or this->position.y < this->r)
	            this->velocity.y = -this->velocity.y;
	    } 
}; 

Ball::Ball(Vector2f position, Vector2f velocity, float r, int red, int green, int blue) 
{
    this->position = position;
    this->velocity = velocity;
    this->r = r;
    this->red = red;
    this->green = green;
    this->blue = blue;
}

Ball::Ball()
{
}

void array(Ball* ball, int number)
{
    srand(time(NULL));
    for (int i = 0; i < number/(20); i++)
    {
        for(int j = 1; j < 20; j++)
        {
            ball[i * (number / 20) + j].position.x = (j + 1) * 45;
            ball[i * (number / 20) + j].position.y = (i + 1) * 35;
            ball[i * (number / 20) + j].velocity.x = rand() % vmax;
            ball[i * (number / 20) + j].velocity.y = rand() % vmax;
        }
    }
}

void CollideBall(Ball* ball1, Ball* ball2)
{
    if (sqrt((((*ball1).position.x - (*ball2).position.x) * ((*ball1).position.x - (*ball2).position.x)) + ((((*ball1).position.y - (*ball2).position.y) * ((*ball1).position.y - (*ball2).position.y))) <= ((*ball1).r + (*ball2).r)))
    {
        Vector2f center = sub((*ball2).position, (*ball1).position);
        Vector2f V1 = mul(normalize(center), ((scalar((*ball1).velocity, center)) / len(center)));
        Vector2f V2 = mul(normalize(center), ((scalar((*ball2).velocity, center)) / len(center)));

        (*ball1).velocity = sub((*ball1).velocity, V1);
        (*ball2).velocity = sub((*ball2).velocity, V2);
        }    
    
} 

void drawAllballs(Ball* ball, int number, sf::RenderWindow* window)
{
    for(int i = 0; i < number; i++)
    {
        ball[i].drawBall(window);
    }
}

void moveAllballs(Ball* ball, int number)
{
    for(int i = 0; i < number; i++)
    {
        ball[i].moveBall(dt);
    }
}

void collideAllballs(Ball* ball, int number)
{
    for (int i = 0; i < number; i++)
    {
        for(int j = 0; j < number; j++)
        {
            if(i != j)
            {    
                CollideBall(&ball[i], &ball[j]);
            }
        }
    }
}

int main()
{
    int number = 0;
    std::cout << "How many balls?" << '\n';
    std::cin >> number;

    sf::RenderWindow window(sf::VideoMode(weight, height), "SFML window");

    Ball* ball = new Ball[number];
    array(ball, number);

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {   
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        for(;;)
        {               
        	window.clear();
            drawAllballs(ball, number, &window);
            moveAllballs(ball, number);
            collideAllballs(ball, number);
            window.display();
        }
    }
    return 0;
}
