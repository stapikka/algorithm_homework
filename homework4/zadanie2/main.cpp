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

void append_to_dynamic_array(int*& arr, int& logical_size, int& actual_size, int newVal) {
    if(logical_size < actual_size) {
        arr[logical_size++] = newVal;
        return;
    }
    if(logical_size == actual_size) {
        int new_actual_size = (actual_size == 0) ? 1 : actual_size *= 2;
        int* newArr = new int[(new_actual_size)];
        for(int i = 0; i < logical_size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        newArr = nullptr;
        arr[logical_size++] = newVal;
        return;
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

    int new_element{};
    do {
        std::cout << "Введите элемент для добавления: ";
        std::cin >> new_element;
        if(new_element == 0){
            std::cout << "До свидания!\n";
            break;
        }
        append_to_dynamic_array(dynarr, logical_size, actual_size, new_element);
        print_dynamic_array(dynarr, logical_size, actual_size);
    } while(new_element != 0);
    
    delete[] dynarr;
}