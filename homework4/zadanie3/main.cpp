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
        actual_size = new_actual_size;
        arr[logical_size++] = newVal;
        return;
    }
}

void remove_dynamic_array_head(int*& arr, int& logical_size, int& actual_size) {
    if(logical_size == 0) {
        std::cout << "Ваш массив уже равен 0!";
        return;
    }
    logical_size--;
    if(logical_size > actual_size / 3) {
        for(int i = 0; i < logical_size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        return;
    }
    int new_actual_size = actual_size / 3;
    if(new_actual_size < 1) new_actual_size = 1;
    int* newArr = new int[new_actual_size];
    for(int i = 0; i < logical_size - 1; ++i) {
        newArr[i] = arr[i + 1];
    }
    delete[] arr;
    arr = newArr;
    newArr = nullptr;
    actual_size = new_actual_size;
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
            print_dynamic_array(dynarr, logical_size, actual_size);
            break;
        }
        append_to_dynamic_array(dynarr, logical_size, actual_size, new_element);
        print_dynamic_array(dynarr, logical_size, actual_size);
    } while(new_element != 0);

    do {
        std::cout << "Удалить первый элемент?\n";
        std::cout << "1 - да, 2 - нет: ";
        int choise{};
        std::cin >> choise;
        if(choise == 1){
            remove_dynamic_array_head(dynarr, logical_size, actual_size);
            print_dynamic_array(dynarr, logical_size, actual_size);
        } else {
            std::cout << "До свидания! ";
            print_dynamic_array(dynarr, logical_size, actual_size);
            break;
        }
    } while (true);
    
    delete[] dynarr;
}