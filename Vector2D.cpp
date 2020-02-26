/*
*  Vector2D.cpp : This file contains the 'main' function. Program execution begins and ends there. 
*  It tests the Vector2 class, which includes operator overloads and the ability to do basic 
*  2D Vector operations.
*/

#include <iostream>
#include "Vector2.h"

using namespace std;

int main()
{
    
    Vector2 v{Vector2()};

    Vector2 w{ Vector2(3,4) };

    double x{};
    double y{};

    cout << "Enter vx:" << endl;
    cin >> x;
    v.setX(x);
    cout << "Enter vy:" << endl;
    cin >> y;
    v.setY(y);

    cout << "v = ";
    v.printVector2();
    
    cout << "w = ";
    w.printVector2();

    Vector2 u{ Vector2() };

    u = w + v;

    cout << "w + v= ";
    u.printVector2();

    double dot{};

    dot = v * w;

    cout << "v*w = " << dot << endl;

    cout << "Polar Coordinates for v: ";
    v.printVector2MagnitudeDirection();

    return 0;

}