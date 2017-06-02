#pragma once
#include <iostream>
#include <string>
class Student
{
	std::string surname;
	std::string name;
	std::string patronymic;// מעקוסעגמ
	std::string cityaccomod;
	std::string school;
	std::string groupnumber;
	std::string yearbirth;
	std::string contnumber;
public:
	Student() {};
	std::string getSurname() const;
	std::string getName() const;
	std::string getPatronymic() const;
	std::string getCityaccomod() const;
	std::string getSchool() const;
	std::string getGroupnumber() const;
	std::string getYearbirth() const;
	std::string getContnumber() const;
	void setSurname(std::string);
	void setName(std::string);
	void setPatronymic(std::string);
	void setCityaccomod(std::string);
	void setSchool(std::string);
	void setGroupnumber(std::string);
	void setYearbirth(std::string);
	void setContnumber(std::string);

	void strPrint();

	~Student() {};
};

