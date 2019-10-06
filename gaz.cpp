#include "TXLib.h"
#include <ctime>
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

void drawBall(Ball ball)
{
    for(int i = ball.r; ball.r > 0; ball.r = ball.r - 1)
    {
        txSetFillColor(RGB(ball.red -(ball.red * ball.r / i), ball.green -(ball.green * ball.r / i), ball.blue -(ball.blue * ball.r / i)));
        txSetColor(RGB(ball.red -(ball.red * ball.r / i), ball.green -(ball.green * ball.r / i), ball.blue -(ball.blue * ball.r / i)));
        txCircle(ball.x, ball.y, ball.r);
        txSetFillColor(RGB(0,0,0));
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
    if  (GetAsyncKeyState(VK_LEFT))
            (*ball).vx = (*ball).vx - 1;
    if  (GetAsyncKeyState(VK_RIGHT))
            (*ball).vx = (*ball).vx + 1;
    if  (GetAsyncKeyState(VK_UP))
            (*ball).vy = (*ball).vy - 1;
    if  (GetAsyncKeyState(VK_DOWN))
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
    txCreateWindow(800, 600);
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

    for(;;)
    {
        txBegin();
        txClear();
        for(int i = 0; i < 300; i++)
        {

            drawBall(ball[i]);
            moveBall(&ball[i]);
            controllBall(&ball[i]);
            txSetFillColor(RGB(0,0,0));
            for(int j = 0; j < 300; j++)
            {
                CollideBall(&ball[i], &ball[j]);
            }
        }

        txSleep(dt);

        txEnd();
    }
    return 0;
}

