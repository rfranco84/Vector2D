# Vector2D
C++ Class for 2D vectors capable of doing basic vector operations with various operators being overloaded.

Developed in Visual Studio 2019.

Vector2D.cpp contains the main function and is used to test the Vector2 class.

Use the + operator to add two Vector2 objects
For example:
v+u

The - and * operators work similarly. The * operator will compute the dot product.

The class is also able to print vectors in (x,y) cartesian coordinates and (magnitude, radiants) polar coordinates. Additionally these four numbers (x,y,mag,dir) are updated accordingly as the vectors are manipulated (i.e., if a magnitude changes, or if a direction changes, etc).

Other operations include normalizing a vector and calculating normal vector.

TO DO:
*Implement a rotation function that rotates a Vector2 object v by dir radiants:
static void rotate(double dir)

*Implement a function to print vectors in component form in unit vector form:
void printVector2UnitVector()

