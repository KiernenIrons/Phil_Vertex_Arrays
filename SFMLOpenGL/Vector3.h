#pragma once
#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>

class Vector3
{
public:

	// Constructor 1
	Vector3();

	// Constructor 2
	Vector3(double x1, double y1, double z1);

	double Length();
	double LengthSquared();
	void Normalise();

	Vector3 operator+(const Vector3 t_right);

	Vector3 operator-(Vector3 V1);

	Vector3 operator-();

	double operator*(Vector3 V1);

	Vector3 operator*(double k);

	Vector3 operator*(float k);

	Vector3 operator*(int k);

	Vector3 operator^(Vector3 V1);

	std::string ToString();

	double m_x;
	double m_y;
	double m_z;



private:

	
};