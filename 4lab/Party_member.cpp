#include "Party_member.h"
Party_member::Party_member() {
	party_name = "";

}
Party_member::Party_member(string p_name, string p_surname, int p_year, string m_party_name,
	std::vector<std::string> m_autobiography) :Person(p_name, p_surname, p_year) {
	party_name = m_party_name;
	autobiography = m_autobiography;

}
Party_member::Party_member(const Party_member& other) :Party_member(other.name, other.surname, other.year_of_birth,
	other.party_name, other.autobiography) {}


void Party_member::SetParty_name(string new_party_name) {
	party_name = new_party_name;
}
string Party_member::GetParty_name() {
	return party_name;
}
std::vector<std::string> Party_member::GetAutobiography() {
	return autobiography;
}
std::string Party_member::GetAutobiography(int index) {
	return autobiography[index];
}
std::vector<std::string>Party_member::GetAutobiography(int begin, int end) {
	return std::vector<std::string>(autobiography.begin() + begin, autobiography.begin() + end);
}
void Party_member::SetAutobiography(std::vector<std::string> new_works) {
	autobiography = new_works;
}
void Party_member::SetAutobiography(int index, std::string work) {
	autobiography.insert(autobiography.begin() + index, work);
}

Party_member& Party_member::operator=(const Party_member& other) {
	Person::operator=(other);
	party_name = other.party_name;
	autobiography = other.autobiography;
	return *this;
}

void Party_member::input(std::istream& is) {
	string m_party_name;
	cout << "Enter name of party and autobiography" << endl;
	rewind(stdin);
	std::getline(is, m_party_name);
	party_name = m_party_name;
	autobiography = input_arr(autobiography, is);
}

std::istream& operator >>(std::istream& is, Party_member& person) {

	person.Person::input(is);
	person.input(is);
	return is;
}
void Party_member::print(std::ostream& os) const {
	os << "\033[31mParty: \033[0m" << party_name << endl;
	os << "\033[31mAutobiography:\033[0m" << endl;
	for (int i = 0; i < autobiography.size(); i++) {
		os << autobiography[i] << endl;
	}
}
std::ostream& operator <<(std::ostream& os, const Party_member& person) {
	//os << person.name << " " << person.surname << " (" << person.year_of_birth << ')' << endl;
	os << static_cast<const Person&>(person) << setw(12) << person.party_name << " "; // << "position" << setw(12) << "speciality" << setw(20) << "scientific_works";
	///os << setw(47) << person.position << setw(12) << person.speciality << " ";
	for (const auto& work : person.autobiography) {
		os << work << " ";
	}
	//	ERROR
	return os;
	return os;
}