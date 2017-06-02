#pragma once
class Point
{
	float x;
	float y;
public:
	Point() {};
	Point(float newx, float newy) : x(newx), y(newy) {};
	float getX() const;
	float getY() const;
	void setX(const float);
	void setY(const float);
	void Print();
	~Point() {};
};

