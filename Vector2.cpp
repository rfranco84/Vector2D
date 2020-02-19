#include "Vector2.h"

// Default Constructor
Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
	this->mag = 0;
	this->dir = 0;
}

// Constructor to 2D Vector
Vector2::Vector2(double x, double y)
{
	this->x = x;
	this->y = y;

	if (x != 0 || y != 0)
	{
		this->mag = sqrt(pow(x, 2) + pow(y, 2));

		if (y >= 0)
			this->dir = acos(x / mag);
		else
			this->dir = 2 * PI - acos(x / mag);
	}
	else
	{
		this->mag = 0;
		this->dir = 0;
	}
}

// Getter and Setter Functions
double Vector2::getX()
{
	return this->x;
}

double Vector2::getY()
{
	return this->y;
}

double Vector2::getMag()
{
	return this->mag;
}

double Vector2::getDir()
{
	return this->dir;
}

void Vector2::setX(double x)
{
	this->x = x;

	this->mag = sqrt(pow(this->x, 2) + pow(this->y, 2));

	// fix logic for direction
	if (mag == 0)
		this->dir = 0;
	else
	{
		if (this->y > 0)
			this->dir = acos(this->x / this->mag);
		else
			this->dir = 2 * PI - acos(this->x / this->mag);
	}
}

void Vector2::setY(double y)
{
	this->y = y;

	this->mag = sqrt(pow(this->x, 2) + pow(this->y, 2));

	// fix logic for direction

}

void Vector2::setMag(double mag)
{
	this->mag = mag;

	if (this->mag == 0)
	{
		this->x = 0;
		this->y = 0;
		this->dir = 0;
	}
	else
	{
		this->x = this->mag * cos(this->dir);
		this->y = this->mag * sin(this->dir);
	}
}

void Vector2::setDir(double dir)
{
	this->dir = dir;
}

// Returns 2-Dimensional Zero Vector
Vector2 Vector2::zeroVector()
{
	Vector2 zero{ 0,0 };
	return zero;
}

// Returns 2-Dimensional Identity Matrix in the form of a vector of Vector2 Objects
vector<Vector2> Vector2::identityMatrix()
{
	Vector2 idX{ 1,0 };
	Vector2 idY{ 0,1 };

	vector <Vector2> identity{ idX, idY };

	return identity;
}

// Prints 2 Vector in Magnitude-Direction format
void Vector2::printVector2MagnitudeDirection()
{
	cout << "Vector:\nMagnitude: " << this->mag << "\nDirection(rad): " << this->dir << endl;
}

// Prints Vector in (x,y) format
void Vector2::printVector2()
{
	cout << "(" << this->x << ", " << this->y << ")" << endl;
}

// Prints Matrix of 2D Vectors. For future project, make matrix class to work with
// Vector2 objects
void Vector2::printMatrix(vector <Vector2> matrix)
{

	cout << "(";
	for (size_t i{ 0 }; i < matrix.size(); i++)
	{
		if (i != matrix.size() - 1)
			cout << matrix.at(i).x << " ";
		else
			cout << matrix.at(i).x;
	}
	cout << ")\n(";
	for (size_t i{ 0 }; i < matrix.size(); i++)
	{
		if (i != matrix.size() - 1)
			cout << matrix.at(i).y << " ";
		else
			cout << matrix.at(i).y;
	}
	cout << ")" << endl;

}

// Normalizes vector
void Vector2::normalizeVector()
{
	this->x = x / mag;
	this->y = y / mag;

	this->mag = 1;
}

// Calculates perpendicular unit vector
Vector2 Vector2::calculateNormal()
{
	Vector2 u{};
	double direction{};
	direction = this->dir + PI / 2;

	if (direction > 2 * PI)
		direction = direction - 2 * PI;
	u.dir = direction;
	u.mag = 1;
	u.x = cos(u.dir);
	u.y = sin(u.dir);

	return u;

}

// Calculates scalar multiplication of vector
Vector2 Vector2::scalarMultiplication(double s, Vector2 v)
{
	v.x = s * v.x;
	v.y = s * v.y;

	v.mag = sqrt(pow(v.x, 2) + pow(v.y, 2));

	return v;
}

// Overloading "+" operator
Vector2 Vector2::operator+ (Vector2 const& obj)
{
	Vector2 vec;
	vec.x = x + obj.x;
	vec.y = y + obj.y;

	vec.mag = sqrt(pow(vec.x, 2) + pow(vec.y, 2));

	if (mag == 0)
	{
		vec.dir = 0;
	}
	else {
		if (y > 0)
			vec.dir = acos(vec.x / vec.mag);
		else
			vec.dir = 2 * PI - acos(vec.x / vec.mag);
	}

	return vec;
}

// Overloading "-" operator
Vector2 Vector2::operator- (Vector2 const& obj)
{
	Vector2 vec;
	vec.x = x - obj.x;
	vec.y = y - obj.y;

	if (mag == 0)
	{
		vec.dir = 0;
	}
	else {

		if (y > 0)
			vec.dir = acos(vec.x / vec.mag);
		else
			vec.dir = 2 * PI - acos(vec.x / vec.mag);

	}

	return vec;
}

// Overloading "*" operator for dot product.
double Vector2::operator* (Vector2 const& obj)
{
	double dotP;
	dotP = x * obj.x + y * obj.y;
	return dotP;
}