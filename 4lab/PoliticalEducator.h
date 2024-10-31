#pragma once
#include "Teacher.h"
#include "Party_member.h"
//класс политического учителя
class PoliticalEducator : public Teacher, public Party_member {
	std::vector<std::string> works;							//политические работы
public:
	PoliticalEducator();
	PoliticalEducator(string p_name, string p_surname, int p_year,
		string t_speciality, string t_position, std::vector<std::string> scientific_works,
		string m_party_name, std::vector<std::string> m_autobiography,
		std::vector<std::string> political_works);
	PoliticalEducator(const PoliticalEducator& other);

	std::vector<std::string> GetPoliticalWorks();
	std::string GetPoliticalWorks(int index);
	std::vector<std::string> GetPoliticalWorks(int begin, int end);
	void SetPoliticalWorks(std::vector<std::string> new_works);
	void SetPoliticalWorks(int index, std::string work);
	void print(std::ostream& os) const override;
	void input(std::istream& is)  override;

	PoliticalEducator& operator=(const PoliticalEducator& other);
	friend std::istream& operator >>(std::istream& is, PoliticalEducator& person);
	friend std::ostream& operator <<(std::ostream& os, const PoliticalEducator& person);

};