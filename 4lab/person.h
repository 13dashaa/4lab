#pragma once
#include "input_func.h"
//#include "List2.cpp"
//класс человека
class Person
{
protected:
	string name;
	string surname;
	int year_of_birth;

	bool validate_year(int p_year);

public:
	Person();
	Person(string name, string surname, int year);
	Person(const Person& other);

	void SetName(string new_name);
	string GetName();
	void SetSurame(string new_surname);
	string GetSurname();
	void Set_year_of_birth(int new_year);
	int Get_year_of_birth();
	virtual void print(std::ostream& os) const;
	virtual void input(std::istream& is);


	Person& operator=(const Person& other);
	friend std::istream& operator >>(std::istream& is, Person& person);
	friend std::ostream& operator <<(std::ostream& os, const Person& person);

	~Person() {};


};