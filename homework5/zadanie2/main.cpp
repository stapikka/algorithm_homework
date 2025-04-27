#include <iostream>


void print_pyramid(int* arr, const int size_arr) {
    std::cout << "Исходный массив: ";
    for(int i = 0; i < size_arr; ++ i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\nПирамида:\n";
    for(int i = 0; i < size_arr; ++i) {
        int level = 0;
        int index = i;

        while(index > 0) {
            index = (index - 1) / 2;
            ++level;
        }

        if(i == 0) {
            std::cout << level << " root " << arr[i] << std::endl;
        } else {
            int parent_index = (i - 1) / 2;
            if(i == 2 * parent_index + 1) {
                std::cout << level << " left(" << arr[parent_index] <<") " << arr[i] << std::endl;
            } else {
                std::cout << level << " right(" << arr[parent_index] <<") " << arr[i] << std::endl;
            }
        }
    }
}

void print_current(int* arr, int index) {
    int level = 0;
    int temp = index;
    while(temp > 0) {
        temp = (temp - 1) / 2;
        ++level;
    }

    if(index == 0) {
        std::cout << level << " root " << arr[index] << std::endl;
    } else {
        int parent_index = (index - 1) / 2;
        if(index == 2 * parent_index + 1) {
            std::cout << level << " left(" << arr[parent_index] <<") " << arr[index] << std::endl;
        } else {
            std::cout << level << " right(" << arr[parent_index] <<") " << arr[index] << std::endl;
        }
    }
}

bool get_parent(int index, int& parent_index) {
    if(index == 0) {
        return false;
    }
    parent_index = (index - 1) / 2;
    return true;
}

bool get_left_child(int index, int size, int& child_index) {
    child_index = 2 * index + 1;
    if(child_index >= size) {
        return false;
    }
    return true;
}

bool get_right_child(int index, int size, int& child_index) {
    child_index = 2 * index + 2;
    if(child_index >= size) {
        return false;
    }
    return true;
}

int main() {

    int array[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    int size = sizeof(array) / sizeof(array[0]);
    print_pyramid(array, size);

    int current_index = 0;
    std::string command;
    do {
        std::cout << "Вы находитесь здесь: ";
        print_current(array, current_index);
        std::cout << "Введите комманду: ";
        std::cin >> command;
        if(command == "up") {
            int parent;
            if(get_parent(current_index, parent)) {
                current_index = parent;
                std::cout << "Ok" << std::endl;
            } else {
                std::cout << "Ошибка! Отсутствует родитель" << std::endl;
            }
        } else if(command == "left") {
            int left_child;
            if(get_left_child(current_index, size, left_child)) {
                current_index = left_child;
                std::cout << "Ok" << std::endl;
            } else {
                std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
            }
        } else if(command == "right") {
            int right_child;
            if(get_right_child(current_index, size, right_child)) {
                current_index = right_child;
                std::cout << "Ok" << std::endl;
            } else {
                std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
            }
        } else if(command == "exit") {
            std::cout << "До свидания!" << std::endl;
        } else {
            std::cout << "Ошибка. Неизвестная команда" << std::endl;
        }
    } while (command != "exit");

        return 0;
    }
