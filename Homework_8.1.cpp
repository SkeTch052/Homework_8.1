#include <iostream>
#include <string>
#include <Windows.h>

class Wrong_length : public std::exception {
public:
    const char* what() const override { return "Вы ввели слово запретной длины! До свидания"; }
};

int function(std::string str, int forbidden_length) {
    if (str.length() == forbidden_length) {
        throw Wrong_length();
    } else {
        return str.length();
    }
}

int main(int argc, char** argv) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int forbidden_length = 1;
    std::string str = "";

    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;
    try {
        while (1) {
            std::cout << "Введите слово:";
            std::cin >> str;
            std::cout << "Длина слова " << str << " равна " << function(str, forbidden_length) << std::endl;
        }
    }
    catch (const Wrong_length& error) { std::cout << error.what() << std::endl; }
    return 0;
}