#pragma once
class Triangle
{
	double a;
	double b;
	double c;
	double h;
	double angle;
	double triangleArea;
public:
	Triangle() {};
	double getTriangleA() const;
	double getTriangleB() const;
	double getTriangleC() const;
	double getTriangleH() const;
	double getTriangleAngle() const;
	double getTriangleArea() const;
	void setABCHAngleTriangle(const unsigned, const unsigned, const unsigned, const unsigned, const unsigned);
	void setTriangleHeightArea(const double, const double);
	void setTriangleAngleArea(const double, const double, const double);
	void setTriangleABCArea(const double, const double, const double);
    void PrintArea();
	~Triangle() {};
};

