#include <SFML/Graphics.hpp>
#include <ctime>
#include <cmath>

const float dt = 0.1;
const int vmax = 10;

struct Ball
{
    float x = 0;
    float y = 0;
    float vx = 0;
    float vy = 0;
    float r = 0;
    float red = 0;
    float green= 0;
    float blue = 0;
};

void drawBall(Ball ball, sf::RenderWindow* window)
{
    sf::CircleShape shape( 00, 200);
    for (int i = ball.r; i > 1; i = i - 1)
    {
        shape.setRadius(i);
        shape.setFillColor(sf::Color(ball.red -(ball.red * i / ball.r), ball.green -(ball.green * i / ball.r), ball.blue -(ball.blue * i / ball.r)));
        shape.setPosition(-i + ball.x, -i + ball.y);
        window->draw(shape);
    }
}

void moveBall(Ball* ball)
{
    (*ball).x += (*ball).vx * dt;
    (*ball).y += (*ball).vy * dt;
    if ((*ball).y > 590 || (*ball).y < 10)
        (*ball).vy = -(*ball).vy;
    if ((*ball).x < 10 || (*ball).x > 790)
        (*ball).vx = -(*ball).vx;
}

void controllBall(Ball* ball)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        (*ball).vx = (*ball).vx - 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        (*ball).vx = (*ball).vx + 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        (*ball).vy = (*ball).vy - 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        (*ball).vy = (*ball).vy + 1;
}

void CollideBall(Ball* ball, Ball* ball1)
{
    if (sqrt((((*ball).x - (*ball1).x) * ((*ball).x - (*ball1).x)) + (((*ball).y - (*ball1).y) * ((*ball).y - (*ball1).y))) <= ((*ball).r + (*ball1).r))
    {
        (*ball).vx = -(*ball).vx;
        (*ball).vy = -(*ball).vy;
        (*ball1).vx = -(*ball1).vx;
        (*ball1).vy = -(*ball1).vy;
    }
}

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::CircleShape shape( 200,200);
    Ball *ball = new Ball [300];
    for (int i = 0; i < 15; i++)
    {
        for(int j = 1; j < 20; j++)
        {
            ball[i * 15 + (j - 1)].x = (j + 1) * 45;
            ball[i * 15 + (j - 1)].y = (i + 1) * 35;
            ball[i * 15 + (j - 1)].red = 138;
            ball[i * 15 + (j - 1)].green = 43;
            ball[i * 15 + (j - 1)].blue = 226;
            ball[i * 15 + (j - 1)].r = 10;
            ball[i * 15 + (j - 1)].vx = rand() % vmax;
            ball[i * 15 + (j - 1)].vy = rand() % vmax;
        }
    }
    while(window.isOpen())
    {
    	window.clear();
    	for(;;)
   	 	{   
        	for(int i = 0; i < 300; i++)
        	{   
                drawBall(ball[i], &window);
        		moveBall(&ball[i]);
        		controllBall(&ball[i]);
            	for(int j = 0; j < 300; j++)
            	{
                	CollideBall(&ball[i], &ball[j]);
            	}
        	}
        	window.display();
    	}
    }
    return 0;
}
