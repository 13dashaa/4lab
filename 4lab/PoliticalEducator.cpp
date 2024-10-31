#include "PoliticalEducator.h"

PoliticalEducator::PoliticalEducator(string p_name, string p_surname, int p_year,
	string t_speciality, string t_position, std::vector<std::string> scientific_works,
	string m_party_name, std::vector<std::string> m_autobiography,
	std::vector<std::string> political_works) :Person(p_name, p_surname, p_year),
	Teacher(p_name, p_surname, p_year, t_speciality, t_position, scientific_works),
	Party_member(p_name, p_surname, p_year, m_party_name, m_autobiography)
{
	works = political_works;
}

PoliticalEducator::PoliticalEducator(const PoliticalEducator& other) :PoliticalEducator(other.name, other.surname, other.year_of_birth,
	other.speciality, other.position, other.scientific_works,
	other.party_name, other.autobiography,
	other.works) {}

PoliticalEducator::PoliticalEducator() {}


std::vector<std::string> PoliticalEducator::GetPoliticalWorks() {
	return works;
}
std::string PoliticalEducator::GetPoliticalWorks(int index) {
	return works[index];
}
std::vector<std::string>PoliticalEducator::GetPoliticalWorks(int begin, int end) {
	return std::vector<std::string>(works.begin() + begin, works.begin() + end);
}
void PoliticalEducator::SetPoliticalWorks(std::vector<std::string> new_works) {
	works = new_works;
}
void PoliticalEducator::SetPoliticalWorks(int index, std::string work) {
	works.insert(works.begin() + index, work);
}

PoliticalEducator& PoliticalEducator::operator=(const PoliticalEducator& other) {
	Teacher::operator=(other);
	party_name = other.party_name;
	autobiography = other.autobiography;
	works = other.works;
	return *this;
}
void  PoliticalEducator::input(std::istream& is) {
	cout << "List of political works" << endl;
	_getch();
	works = input_arr(works, is);

}
std::istream& operator >>(std::istream& is, PoliticalEducator& person) {

	person.Person::input(is);
	person.Teacher::input(is);
	person.Party_member::input(is);
	person.input(is);
	return is;
}


void PoliticalEducator::print(std::ostream& os) const {
	os << "\033[35mPolitical Works:\033[0m" << endl;
	for (int i = 0; i < works.size(); i++) {
		os << works[i] << endl;
	}
}
std::ostream& operator <<(std::ostream& os, const PoliticalEducator& person) {
	//os << person.name << " " << person.surname << " (" << person.year_of_birth << ')' << endl;
	os << static_cast<const Party_member&>(person) << static_cast<const Teacher&>(person) << " "; // << "position" << setw(12) << "speciality" << setw(20) << "scientific_works";
	///os << setw(47) << person.position << setw(12) << person.speciality << " ";
	for (const auto& work : person.works) {
		os << work << " ";
	}
	return os;
}