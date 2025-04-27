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

int main() {

    int array[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    int size = sizeof(array) / sizeof(array[0]);
    print_pyramid(array, size);



    return 0;
}