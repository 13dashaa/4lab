#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
bool input_integer(int& value, std::istream& is);
std::vector<std::string> input_arr(std::vector<std::string> array, std::istream& is);
//template <typename T>
//std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec);