#pragma once

//TODO kinda defeats the purpose of having components if they're in one big cluster file 
struct Color
{
	Color(float r, float g, float b, float a) : m_r(r), m_g(g), m_b(b), m_a(a) {};
	~Color() {};

	float m_r;
	float m_g;
	float m_b;
	float m_a;
};

class Collider
{

};

class Perceptible
{
public:
	Perceptible();
	~Perceptible();

	Color* m_pColor;
};

class Physics
{

};

struct Position
{
	float m_x;
	float m_y;
};
