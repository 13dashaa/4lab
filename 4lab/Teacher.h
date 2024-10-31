#pragma once
#include "person.h"
//класс преподавателя
class Teacher : virtual public Person
{
protected:
	string speciality;												//специальность
	std::vector<std::string> scientific_works;						//научные работы
	string position;												//должность
public:
	Teacher();
	Teacher(string p_name, string p_surname, int p_year, string t_speciality, string t_position, std::vector<std::string> t_works);
	Teacher(const Teacher& other);

	void SetSpeciality(string new_speciality);
	string GetSpeciality();
	void SetPosition(string new_position);
	string GetPosition();
	std::vector<std::string> GetScientificWorks();
	std::string GetScientificWorks(int index);
	std::vector<std::string> GetScientificWorks(int begin, int end);
	void SetScientificWorks(std::vector<std::string> new_works);
	void SetScientificWorks(int index, std::string work);
	void print(std::ostream& os) const override;
	void input(std::istream& is)  override;

	Teacher& operator=(const Teacher& other);
	friend std::istream& operator >>(std::istream& is, Teacher& person);
	friend std::ostream& operator <<(std::ostream& os, const Teacher& person);

	~Teacher() {};

};