
#include <iostream>
#include "Triangle.h"
#include "Student.h"
#include "Point.h"
#include "Sguare.h"
#include <string>
#include <stdlib.h>
#include <ctime>

bool ComparPoint(float getX1, float getY1, float getX2, float getY2)
{
	return getX1 == getX2 && getY1 == getY2;
}

float FieldCount()
{
	//srand(time(NULL)); - для проверки равных точек
	float  cad = rand();
	return cad;
}

void TestPointesFunctional()
{
	srand(time(NULL));
	Point pt1, pt2;
	pt1.setX(FieldCount());
	pt1.setY(FieldCount());
	pt2.setX(FieldCount());
	pt2.setY(FieldCount());
	if (ComparPoint(pt1.getX(), pt1.getY(), pt2.getX(), pt2.getY()))
	{
	    std::cout << "points coincide\n";
	}
	else { std::cout << "points not match\n"; }
	pt1.Print();
	pt2.Print();
}
//#######################################################################################
void TestStudentFunctional()
{
	Student stud;
	std::string auix;
	std::cout << "Student name: " << std::endl;
	std::cin >> auix;
	stud.setName(auix);
	std::cout << "Student surname: " << std::endl;
	std::cin >> auix;
	stud.setSurname(auix);
	std::cout << "Student patronymic: " << std::endl;
	std::cin >> auix;
	stud.setPatronymic(auix);
	std::cout << "Student cityaccomod: " << std::endl;
	std::cin >> auix;
	stud.setCityaccomod(auix);
	std::cout << "Student school: " << std::endl;
	std::cin >> auix;
	stud.setSchool(auix);
	std::cout << "Student groupnumber: " << std::endl;
	std::cin >> auix;
	stud.setGroupnumber(auix);
	std::cout << "Student yearbirth: " << std::endl;
	std::cin >> auix;
	stud.setYearbirth(auix);
	std::cout << "Student contnumber: " << std::endl;
	std::cin >> auix;
	stud.setContnumber(auix);
	stud.strPrint();
	stud.~Student();
}
//#########################################################################################
void TestTriangleFunctional()
{
	srand(time(NULL));
	Triangle figure;
	figure.setABCHAngleTriangle(rand(), rand(), rand(), rand(), rand());
	figure.setTriangleAngleArea(figure.getTriangleA(), figure.getTriangleB(), figure.getTriangleAngle());
	figure.PrintArea();
	figure.setTriangleHeightArea(figure.getTriangleC(), figure.getTriangleH());
	figure.PrintArea();
	figure.setTriangleABCArea(figure.getTriangleA(), figure.getTriangleB(), figure.getTriangleC());
	figure.PrintArea();
	figure.~Triangle();
}

void TestSquareFunctional()
{
	srand(time(NULL));
	Sguare figure;
	figure.setSguareSide(rand());
	figure.setSguaresArea(figure.getSguareSide());
	figure.PrintSguares();
	figure.~Sguare();
}

int main()
{
	TestPointesFunctional();
	TestStudentFunctional();
	TestTriangleFunctional();
	TestSquareFunctional();
	return 0;
}
