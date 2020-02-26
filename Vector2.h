#pragma once
#include <iostream>
#include <cmath>
#include <vector>

#define PI 3.14

using namespace std;

class Vector2
{
private:
	double x;
	double y;
	double mag;
	double dir;

public:
	/*double x;
	double y;
	double mag;
	double dir; */

	// Constructor to initialize Vector2 object to a 2D Zero Vector
	Vector2();

	// Constructor to initialize Vector2 object to a 2D non-zero vector.
	Vector2(double x, double y);

	// Getter and Setter Functions
	double getX();

	double getY();

	double getMag();

	double getDir();

	void setX(double x);

	void setY(double y);

	void setMag(double mag);
	
	void setDir(double dir);

	// returns 2D Zero Vector
	static Vector2 zeroVector();

	// Returns Identity Matrix for 2D Vectors
	// For future project, make matrix class to work with Vector2D objects or MathVector
	// Objects
	static vector<Vector2> identityMatrix();

	// Prints Vector in Magnitude-Direction Format (Polar Coordinates)
	void printVector2MagnitudeDirection();

	// Prints Vector in (x,y) format (Cartesian Coordinates)
	void printVector2();

	// Prints Matrix of 2D Vectors. For future project, make matrix class to work with
	// Vector2D objects
	static void printMatrix(vector <Vector2> matrix);

	// Normalizes vector
	void normalizeVector();

	// Calculates perpendicular unit vector
	Vector2 calculateNormal();

	// Calculates scalar multiplication of vector
	static Vector2 scalarMultiplication(double s, Vector2 v);

	// Overloading "+" operator
	Vector2 operator+ (Vector2 const& obj);

	// Overloading "-" operator
	Vector2 operator- (Vector2 const& obj);


	// Overloading "*" operator for dot product.
	double operator* (Vector2 const& obj);

};