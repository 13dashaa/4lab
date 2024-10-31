#include "Teacher.h"
Teacher::Teacher() {
	speciality = "";
	position = "";

}
Teacher::Teacher(string p_name, string p_surname, int p_year, string t_speciality, string t_position,
	std::vector<std::string> t_works) :Person(p_name, p_surname, p_year) {
	speciality = t_speciality;
	position = t_position;
	scientific_works = t_works;
}
Teacher::Teacher(const Teacher& other) :Teacher(other.name, other.surname, other.year_of_birth,
	other.speciality, other.position, other.scientific_works) {}


void Teacher::SetSpeciality(string new_speciality) {
	speciality = new_speciality;
}
string Teacher::GetSpeciality() {
	return speciality;
}
void Teacher::SetPosition(string new_position) {
	position = new_position;
}
string Teacher::GetPosition() {
	return position;
}
std::vector<std::string> Teacher::GetScientificWorks() {
	return scientific_works;
}
std::string Teacher::GetScientificWorks(int index) {

	return scientific_works[index];
}
std::vector<std::string> Teacher::GetScientificWorks(int begin, int end) {
	return std::vector<std::string>(scientific_works.begin() + begin, scientific_works.begin() + end);
}
void Teacher::SetScientificWorks(std::vector<std::string> new_works) {
	scientific_works = new_works;
}
void Teacher::SetScientificWorks(int index, std::string work) {
	scientific_works.insert(scientific_works.begin() + index, work);
}
Teacher& Teacher::operator=(const Teacher& other) {
	//name = other.name;
	//surname = other.surname;
	//year_of_birth = other.year_of_birth;
	Person::operator=(other);
	speciality = other.speciality;
	position = other.position;
	scientific_works = other.scientific_works;
	return *this;
}
void Teacher::input(std::istream& is) {
	string t_speciality;
	string t_position;
	cout << "Enter speciality, position and list of scientific works" << endl;
	rewind(stdin);
	std::getline(is, t_speciality);
	rewind(stdin);
	std::getline(is, t_position);
	speciality = t_speciality;
	position = t_position;
	scientific_works = input_arr(scientific_works, is);
}
std::istream& operator >>(std::istream& is, Teacher& person) {

	person.Person::input(is);
	person.input(is);
	return is;
}

void Teacher::print(std::ostream& os) const {
	cout << setw(11) << "\033[33mSpeciality\033[0m" << setw(10) << "Position" << setw(20) << "Scientific works";
	cout << setw(11) << speciality << setw(10) << position;
	//cout << "\033[33mScientific works:\033[0m" << endl;

	//cout << left << setw(5) << "No." << setw(50) << "Title" << endl;
	//cout << setfill('-') << setw(55) << "-" << setfill(' ') << endl;

	/*for (int i = 0; i < scientific_works.size(); i++) {
		cout << left << setw(5) << i + 1 << setw(50) << scientific_works[i] << endl;
	}*/
	//os << "\033[33mSpeciality: \033[0m" << speciality << " (" << position << ")" << endl;
	//os << "\033[33mScientific works:\033[0m" << endl;
	for (int i = 0; i < scientific_works.size(); i++) {
		os << setw(20) << scientific_works[i];
	}
}
std::ostream& operator <<(std::ostream& os, const Teacher& person) {

	os << static_cast<const Person&>(person) << setw(47) << person.position << setw(12) << person.speciality << " "; // << "position" << setw(12) << "speciality" << setw(20) << "scientific_works";
	///os << setw(47) << person.position << setw(12) << person.speciality << " ";
	for (const auto& work : person.scientific_works) {
		os << work << " ";
	}
	 //	ERROR
	return os;
}
//os << static_cast<const Chelovek&>(tourist) << ", Визы: ";
//for (const auto& visa : tourist.visas) {
//	os << visa << " ";
//}