#include <iostream>

int simple_string_hash(std::string s) {
    int hash{0};
    for(int i = 0; i < s.length(); ++i) {
        hash += static_cast<int>(s[i]);
    }
    return hash;
}

int main() {
    setlocale(LC_ALL, "rus");

    std::string str;

    do {
        std::cout << "Введите строку: ";
        std::cin >> str;
        if(str == "exit") {
            std::cout << "Наивный хеш строки " << str << " = "
                << simple_string_hash(str) << std::endl;
            break;
        }
        std::cout << "Наивный хеш строки " << str << " = "
                << simple_string_hash(str) << std::endl;
    } while(str != "exit");


    return 0;
}