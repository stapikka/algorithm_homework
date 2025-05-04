#include <iostream>
#include <cmath>

uint64_t real_string_hash(const std::string& s, int p, int n) {
    uint64_t hash{};
    uint64_t power = 1;
    for(char c : s) {
        hash = (hash + static_cast<uint64_t>(c) * power) % n;
        power = (power * p) % n;
    }
    return hash;
}

int main() {
    setlocale(LC_ALL, "rus");
    int p{};
    int n{};
    std::string str;
    std::cout << "Введите p: ";
    std::cin >> p;
    std::cout << "Введите n: ";
    std::cin >> n;

    do {
        std::cout << "Введите строку: ";
        std::cin >> str;
        if(str == "exit") {
            std::cout << "Хеш строки " << str << " = "
                << real_string_hash(str, p, n) << std::endl;
            break;
        }
        std::cout << "Хеш строки " << str << " = "
                << real_string_hash(str, p, n) << std::endl;
    } while(str != "exit");

    return 0;
}