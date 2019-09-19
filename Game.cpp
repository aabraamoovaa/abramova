#include "TXLib.h"

const float dt = 0.1;

void drawBall(float x, float y, int r, int R, int G, int B)
{
    for(int i = r; r > 0; r = r - 1)
    {
        int R1 = R -(R * r / i);
        int G1 = G -(G * r / i);
        int B1 = B -(B * r / i);
        txSetFillColor(RGB(R1, G1, B1));
        txSetColor(RGB(R1, G1, B1));
        txCircle(x, y, r);
        txSetFillColor(RGB(0,0,0));
    }
}

void drawRectangle(float X1, float Y1, float X2, float Y2)
{
    txSetFillColor(RGB(255, 255, 255));
    txSetColor(RGB(255, 255, 255));
    txRectangle(X1, Y1, X2, Y2);
}

void moveBall(float *x, float *y, float *vx, float *vy, float dt, float x0, float y0)
{
    *x += *vx * dt;
    *y += *vy * dt;
    if (*y > 570 || *y < 30)
        *vy = -*vy;
    if (*x < 30)
    {
        *x = x0;
        *y = y0;
    }
    if (*x > 770)
    {
        *x = x0;
        *y = y0;
    }
}

void moveRectangle(float *y3, float *vy3)
{

    if (*y3 > 400 || *y3 < 0)
        *vy3 = - *vy3;
}

void controllBall1(float *x1, float *y1, float *vx1, float *vy1)
{
    if  (GetAsyncKeyState('J'))
            *vx1 = *vx1 - 1;
    if  (GetAsyncKeyState('L'))
            *vx1 = *vx1 + 1;
    if  (GetAsyncKeyState('K'))
            *vy1 = *vy1 - 1;
    if  (GetAsyncKeyState('O'))
            *vy1 = *vy1 + 1;
}

void controllBall2(float *x2, float *y2, float *vx2, float *vy2)
{
    if  (GetAsyncKeyState('F'))
            *vx2 = *vx2 - 1;
    if  (GetAsyncKeyState('H'))
            *vx2 = *vx2 + 1;
    if  (GetAsyncKeyState('G'))
            *vy2 = *vy2 - 1;
    if  (GetAsyncKeyState('T'))
            *vy2 = *vy2 + 1;
}

void controllRectangle3(float *y3, float *vy3, float dt)
{
    if  (GetAsyncKeyState('W'))
    {
        *y3 += *vy3 * dt;
    }
    if  (GetAsyncKeyState('S'))
    {
        *y3 += -*vy3 * dt;
    }
}

void controllRectangle4(float *y4, float *vy4, float dt)
{
    if  (GetAsyncKeyState(VK_UP))
    {
        *y4 += *vy4 * dt;
    }
    if  (GetAsyncKeyState(VK_DOWN))
    {
        *y4 += -*vy4 * dt;
    }
}

void Collide(float *x1, float *y1, float *vx1, float *vy1, float *x2, float *y2, float *vx2, float *vy2, float *r1, float *r2, float *x3, float *x4, float *y3, float *y4)
{
    if (sqrt(((*x1-*x2) * (*x1-*x2)) + ((*y1-*y2) * (*y1-*y2))) <= (*r1 + *r2))
    {
        *vx1 = -*vx1;
        *vy1 = -*vy1;
        *vx2 = -*vx2;
        *vy2 = -*vy2;
    }
    if ((*x1 - *x3 <= *r1) && (*y1 >= *y3) && (*y1 <= *y3 + 200))
    {
        *vx1 = -*vx1;
        *vy1 = -*vy1;
    }
    if ((*x2 - *x3 <= *r2) && (*y2 >= *y3) && (*y2 <= *y3 + 200))
    {
        *vx2 = -*vx2;
        *vy2 = -*vy2;
    }
    if ((*x4 - *x1 <= *r1) && (*y1 >= *y4) && (*y1 <= *y4 + 200))
    {
        *vx1 = -*vx1;
        *vy1 = -*vy1;
    }
    if ((*x4 - *x2 <= *r2) && (*y2 >= *y4) && (*y2 <= *y4 + 200))
    {
        *vx2 = -*vx2;
        *vy2 = -*vy2;
    }
}

int main()
{
    txCreateWindow(800, 600);
    float x1 = 200;
    float y1 = 200;
    float x2 = 400;
    float y2 = 450;
    float x3 = 50;
    float y3 = 100;
    float x4 = 750;
    float y4 = 100;

    float vx1 = 4;
    float vy1 = 4;
    float vx2 = 4;
    float vy2 = 4;
    float vy3 = 15;
    float vy4 = 15;

    float r1 = 30;
    float r2 = 30;
    float x01 = 200;
    float y01 = 200;
    float x02 = 400;
    float y02 = 450;
    for(;;)
    {
        txClear();
        drawRectangle(x3 - 25, y3, x3, y3 + 200);
        drawRectangle(x4, y4, x4 + 25, y4 + 200);
        drawBall(x1, y1, r1, 138, 43, 226);
        drawBall(x2, y2, r2, 50, 255, 50);
        moveRectangle(&y3, &vy3);
        moveRectangle(&y4, &vy4);
        moveBall(&x1, &y1, &vx1, &vy1, dt, x01, y01);
        moveBall(&x2, &y2, &vx2, &vy2, dt, x02, y02);
        controllBall1(&x1,&y1,&vx1, &vy1);
        controllBall2(&x2,&y2,&vx2,  &vy2);
        controllRectangle3(&y3, &vy3, dt);
        controllRectangle4(&y4, &vy4, dt);
        Collide(&x1, &y1, &vx1, &vy1, &x2, &y2, &vx2, &vy2, &r1, &r2, &x3, &x4, &y3, &y4);
        txSleep(dt);
    }
    return 0;
}
