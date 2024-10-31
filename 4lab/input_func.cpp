#include "input_func.h"
bool input_integer(int& value, std::istream& is) {
    while (true) {
        is >> value;

        // Проверка на корректный ввод
        if (is.fail())
        {                                                                               // Если ввод не удался
            std::cout << "Invalid input. Please enter an integer: ";
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');               // Пропуск некорректного ввода
        }
        else {
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');               // Пропуск оставшегося ввода
            return true;                                                                // Успешный ввод
        }
    }
}
std::vector<std::string> input_arr(std::vector<std::string> array, std::istream& is) {
    do {
        system("cls");
        string item;
        rewind(stdin);
        std::getline(is, item);
        array.push_back(item);
        std::cout << std::endl << "If u want to continue, press 'y'" << std::endl;
        rewind(stdin);
    } while (getchar() == 'y');
    return array;

}
//template <typename T>
//std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
//    for (const T& elem : vec) {
//        os << elem << " ";
//    }
//    return os;
//}
