#include <iostream>
#include <string>

int simple_string_hash(std::string s) {
    int hash{0};
    for(int i = 0; i < s.length(); ++i) {
        hash += static_cast<int>(s[i]);
    }
    return hash;
}

int find_substring_light_rabin_karp(const std::string& s, const std::string& p) {
    int n = s.length();
    int m = p.length();

    if(m > n) return -1;

    int target_hash = simple_string_hash(p);
    int curret_hash = simple_string_hash(s.substr(0, m));

    for(int i = 0; i < n - m; ++i) {
        if(i > 0) {
            curret_hash -= static_cast<int>(s[i - 1]);
            curret_hash += static_cast<int>(s[i + m - 1]);
        }
        if(curret_hash == target_hash && s.substr(i, m) == p) {
            return i;
        }
    }

    return -1;
}

int main() {
    setlocale(LC_ALL, "rus");

    std::string source;
    std::string search;
    
    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::getline(std::cin, source);

    do {
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::cin >> search;
        if(search == "exit") {
            if(find_substring_light_rabin_karp(source, search) == -1) {
                std::cout << "Подстрока " << search << " не найдена" << std::endl;
                break;
            }
            std::cout << "Подстрока " << search << " найдена по индексу " 
                << find_substring_light_rabin_karp(source, search) << std::endl;
            break;
        }
        if(find_substring_light_rabin_karp(source, search) == -1) {
            std::cout << "Подстрока " << search << " не найдена" << std::endl;
            continue;
        }
        std::cout << "Подстрока " << search << " найдена по индексу " 
            << find_substring_light_rabin_karp(source, search) << std::endl;
    } while(search != "exit");

    return 0;
}