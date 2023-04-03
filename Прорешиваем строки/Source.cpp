#include <iostream>
#include <string>

// кодировка UTF-8

std::string spaces_str(std::string str); // прототип функции
bool is_spam(std::string msg);

int main() {
	setlocale(LC_ALL(NULL), "Russian");
	int n;

	// Задача 1. Пробелы в строке.
	/*
	std::cout << "Задача 1.\nВведите строку -> \n";
	std::string str1;
	std::getline(std::cin, str1);
	std::cout << spaces_str(str1) << std::endl;
	*/

	// Задача 2. Антиспам.
	/*
	std::cout << "Задача 2.\nВведите строку -> ";
	std::string str2;
	std::getline(std::cin, str2);
	if (is_spam(str2))
		std::cout << "Обнаружен спам.\n\n";
	else
		std::cout << "Спама не обнаружено.\n\n";
		*/


	// Задача 3. Разбивка URL

	std::string URL = "http://vk.com/super_user/photos";
	std::cout << "Задача 3.\nАдрес сайта:\n" << URL << std::endl;
	int domen_index = URL.find("://") + 3;
	int path_index = URL.find("/", domen_index) + 1;
	std::string path = URL.substr(path_index);
	std::string domen = URL.substr(domen_index, path_index - 1 - domen_index);
	std::string protocol;
	std::cout << "Домен:\t" << domen << "\n";
	std::cout << "Путь:\t" << path << "\n\n";


	return 0;
}

std::string spaces_str(std::string str) {
	std::string result;
	for (int i{}; i < str.length(); i++){
		result += str[i];
		if(i != str.length() - 1)
			result += " ";
	}
	return result;
}
bool is_spam(std::string msg) {
	for (int i = 0; i < msg.length(); i++)
		msg[i] = std::tolower(msg[i]);
	const int spams_number = 4;
	std::string spams[spams_number]{
		"100% free",
		"sales increase",
		"only today",
		"black friday"
	};

	for (int i{}; i < spams_number; i++)
		if (msg.find(spams[i]) < msg.length())
			return true;
	return false;
}
