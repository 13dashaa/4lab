#include "PoliticalEducator.h"
#include "List2.cpp"
int main() {
	do {

		rewind(stdin);
		system("cls");
		Person simple_person;
		Teacher teacher;
		Party_member party_memb;
		PoliticalEducator p3;
		//List<PoliticalEducator> political_educator;
		List<Person*> common_list;
		/*List<Teacher> teach;
		List<Person> pers;
		List<Party_member> memb;*/


		std::cout << "Creating a simple person" << endl;
		std::cin >> p3;
		//Person p2(simple_person);
		std::cout << p3;
		/*system("cls");*/

		std::cout <<endl<< "Creating a teacher" << endl;
		std::cin >> teacher;
		cout << teacher;/*
		string new_name = "Darya";
		teacher.SetName(new_name);
		string first_work = teacher.GetScientificWorks(0);
		system("cls");

		std::cout << "Creating a member of some party" << endl;
		std::cin >> party_memb;
		party_memb.SetAutobiography({ "Born in Springfield in 1980.", "I grew up in a working-class family.",
			"After studying Political Science, I became a community organizer."});
		system("cls");
		int year = party_memb.Get_year_of_birth();

		std::cout << "Creating a political educator" << endl;
		//std::cin >> political_educator;
		*/
		int mark;
		std::cout << endl << "1 - Person\n 2 - Teacher\n 3 - Party_member\n 4 - Polit ";
		cin >> mark;
		if (mark == 1) {
			List<Person> pers;
			for (int i = 0; i < 3; i++)
			{
				Person  a;
				cin >> a;
				pers.push_back(a);
			}
			if (pers.GetSize()) { pers.show(); }
		}
		else if (mark == 2) {
			List<Teacher> teach;
			for (int i = 0; i < 3; i++)
			{

				Teacher a;
				cin >> a;
				//pers.push_back(a);
				teach.push_back(a);

			}
			teach.show();
		}
		else if (mark == 3) {
			List<Party_member> memb;
			for (int i = 0; i < 3; i++)
			{
				Party_member a;
				cin >> a;
				memb.push_back(a);

			}
		}
		else {
			List<PoliticalEducator> political_educator;
			for (int i = 0; i < 3; i++)
			{
				PoliticalEducator a;
				cin >> a;
				political_educator.push_back(a);
			}
			political_educator.show();
		}

		/*common_list.push_back(&simple_person);
		common_list.push_back(&teacher);
		common_list.push_back(&party_memb);
		for (int i = 0; i < common_list.GetSize(); i++) {
			std::cout << *common_list[i];
		}*/
		//List<PoliticalEducator> find = political_educator.search("Dasha");
		//system("cls");
		std::cout << "\033[32mYour person\033[0m" << endl << simple_person;
		std::cout << "\033[32mYour teacher\033[0m" << endl << teacher;
		std::cout << "\033[32mYour member of party\033[0m" << endl << party_memb;
		std::cout << "\033[32mYour political educator\033[0m" << endl;// << political_educator;
		//political_educator.show();
		std::cout << std::endl << "If u want to continue, press 'y'" << std::endl;
	} while (getchar() == 'y');
	return 0;
}