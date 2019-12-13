#include <cmath>

struct Vector2f
{
     float x = 0;
     float y = 0;
};

Vector2f add(Vector2f v1, Vector2f v2)
{
    Vector2f result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    return result;
}

Vector2f sub(Vector2f v1, Vector2f v2)
{
    Vector2f result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    return result;
}

Vector2f mul(Vector2f v1, float a)
{
    Vector2f result;
    result.x = v1.x * a;
    result.y = v1.y * a;
    return result;
}

float len(Vector2f v1)
{
    float result;
    result = sqrt(v1.x * v1.x + v1.y * v1.y);
    return result;
}

float scalar(Vector2f v1, Vector2f v2)
{
    float result;
    result = v1.x * v2.x + v1.y + v2.y;
    return result;
}

float angle(Vector2f v1, Vector2f v2)
{
    float result;
    Vector2f v = sub(v1, v2);
    if (len(v) != 0)
        {
        result = (scalar(v1, v2))/(len(v));
        return result;
        }
    else
        return result = 0;
}

Vector2f normalize(Vector2f v1)
{
    Vector2f result;
    result = mul(v1, 1/len(v1));
    return result;
}
