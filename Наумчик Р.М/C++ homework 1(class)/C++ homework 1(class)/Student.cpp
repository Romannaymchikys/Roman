#include "Student.h"
#include <iostream>

std::string Student::getSurname() const { return surname; }
std::string Student::getName() const { return name; }
std::string Student::getPatronymic() const { return patronymic; }
std::string Student::getCityaccomod() const { return cityaccomod; }
std::string Student::getSchool() const { return school; }
std::string Student::getGroupnumber() const { return groupnumber; }
std::string Student::getYearbirth() const { return yearbirth; }
std::string Student::getContnumber() const { return contnumber; }
void Student::setSurname(std::string news) { surname = news; }
void Student::setName(std::string news) { name = news; }
void Student::setPatronymic(std::string news) { patronymic = news; }
void Student::setCityaccomod(std::string news) { cityaccomod = news; }
void Student::setSchool(std::string news) { school = news; }
void Student::setGroupnumber(std::string news) { groupnumber = news; }
void Student::setYearbirth(std::string news) { yearbirth = news; }
void Student::setContnumber(std::string news) { contnumber = news; }
void Student::strPrint()
{ 
	std::cout << "Student name: " << name << std::endl;
	std::cout << "Student surname: " << surname << std::endl;
	std::cout << "Student patronymic: " << patronymic << std::endl;
	std::cout << "Student cityaccomod: " << cityaccomod << std::endl;
	std::cout << "Student school: " << school << std::endl;
	std::cout << "Student groupnumber: " << groupnumber << std::endl;
	std::cout << "Student yearbirth: " << yearbirth << std::endl;
	std::cout << "Student contnumber: " << contnumber << std::endl;
}

