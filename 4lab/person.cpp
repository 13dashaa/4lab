#include "person.h"

Person::Person(string p_name, string p_surname, int p_year) {

	name = p_name;
	surname = p_surname;
	if (validate_year(p_year)) {
		year_of_birth = p_year;
	}
	else {
		year_of_birth = 0;
	}
}
Person::Person(const Person& other) :Person(other.name, other.surname, other.year_of_birth) {}
Person::Person() {
	name = "";
	surname = "";
	year_of_birth = 0;
}

bool Person::validate_year(int p_year) {
	if (p_year < 1900 || p_year > 2025)
		return false;
	return true;
}
void Person::SetName(string new_name) {
	name = new_name;
}
string Person::GetName() {
	return name;
}
void Person::SetSurame(string new_surname) {
	surname = new_surname;
}
string Person::GetSurname() {
	return surname;
}
void Person::Set_year_of_birth(int new_year) {
	year_of_birth = new_year;
}
int Person::Get_year_of_birth() {
	return year_of_birth;
}

Person& Person::operator=(const Person& other) {
	name = other.name;
	surname = other.surname;
	year_of_birth = other.year_of_birth;
	return *this;
}

void Person::input(std::istream& is) {
	string p_name;
	string p_surname;
	int p_year;
	cout << "Enter name, surname and year of birth" << endl;
	rewind(stdin);
	std::getline(is, p_name);
	rewind(stdin);
	std::getline(is, p_surname);
	rewind(stdin);
	input_integer(p_year, is);
	name = p_name;
	surname = p_surname;
	if (validate_year(p_year)) {
		year_of_birth = p_year;
	}
	else {
		year_of_birth = 0;
	}
}
std::istream& operator >>(std::istream& is, Person& person) {
	person.input(is);
	return is;
}
void Person::print(std::ostream& os) const {
	//	os << setw(10) << "\033[34mName\033[0m" << setw(10) << "Surname"<< setw(5) 
	//		<< "year" << setw(15) << "autobiography" << setw(12) << "party_name" << setw(17) << "scientific_works" 
	//		<< setw(12) << "speciality" << setw(10) << "works" << endl;
	//	os << setw(10) << name << setw(10) << surname << setw(5) << year_of_birth;
}
std::ostream& operator <<(std::ostream& os, const Person& person) {
	os << setw(10) << "Name" << setw(10) << "Surname" << setw(7) << "year"
		<< setw(12) << "party_name" << setw(20) << "autobiography"
		<< setw(15) << "position" << setw(12) << "speciality" << setw(20) << "scientific_works"
		<< setw(10) << "works" << endl;
	os << setw(10) << person.name << setw(10) << person.surname << setw(7) << person.year_of_birth;
	return os;
}
