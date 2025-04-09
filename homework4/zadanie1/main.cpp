#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    std::cout << "Динамический массив: ";

    for(int i = 0; i < actual_size; ++i) {
        if(i >= logical_size) {
            std::cout << "_ ";
        } else {
            std::cout << arr[i] << " ";
        }
    }
}

int main(){
    setlocale(LC_ALL, "rus");

    int logical_size{};
    int actual_size{};

    std::cout << "Введите фактический размер массива: ";
    std::cin >> actual_size;
    int* dynarr = new int[actual_size];
    do{
        std::cout << "Введите логический размер массива: ";
        std::cin >> logical_size;
        if(logical_size > actual_size){
            std::cout << 
                "Ошибка. Логический размер не может быть больше фактического\n";
        }
    } while(logical_size > actual_size);
    for(int i = 0; i < logical_size; ++i) {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> dynarr[i];
    }

    print_dynamic_array(dynarr, logical_size, actual_size);

    delete[] dynarr;
}