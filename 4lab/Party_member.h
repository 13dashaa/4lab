#pragma once
#include "person.h"
//класс политического деятеля
class Party_member :virtual public Person {
protected:
	string party_name;								//название партии
	std::vector<std::string> autobiography;			//автобиография

public:
	Party_member();
	Party_member(string p_name, string p_surname, int p_year, string m_party_name, std::vector<std::string> m_autobiography);
	Party_member(const Party_member& other);

	void SetParty_name(string new_party_name);
	string GetParty_name();
	std::vector<std::string> GetAutobiography();
	std::string GetAutobiography(int index);
	std::vector<std::string> GetAutobiography(int begin, int end);
	void SetAutobiography(std::vector<std::string> new_works);
	void SetAutobiography(int index, std::string work);
	void print(std::ostream& os) const override;
	void input(std::istream& is)  override;

	Party_member& operator=(const Party_member& other);
	friend std::istream& operator >>(std::istream& is, Party_member& person);
	friend std::ostream& operator <<(std::ostream& os, const Party_member& person);

	~Party_member() {};

};