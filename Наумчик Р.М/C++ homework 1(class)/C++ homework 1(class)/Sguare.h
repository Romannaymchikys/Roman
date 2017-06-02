#pragma once
class Sguare
{
	double side;
	double sguareArea;
public:
	Sguare() {};
	double getSguareSide() const;
	double getSguaresArea() const;
	void setSguareSide(const unsigned);
	void setSguaresArea(const double);
	void PrintSguares();
	~Sguare() {};
};

