// Vector2D.cpp : This file contains the 'main' function. Program execution begins and ends there. It tests the Vector2 class, which includes operator overloads and the ability to do basic 
// 2D Vector operations.

#include <iostream>
#include "Vector2.h"

using namespace std;

int main()
{
    
    Vector2 v{};

    Vector2 u{};

    double x{};
    double y{};

    cout << "Enter vx:" << endl;
    cin >> x;
    v.setX(x);
    cout << "Enter vy:" << endl;
    cin >> y;
    v.setY(y);

    v.printVector2();
    
}