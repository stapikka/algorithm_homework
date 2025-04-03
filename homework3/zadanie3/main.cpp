#include <iostream>


void count_sort(int* arr, int size){

    int min = arr[0];
    int max = arr[0];
    for(int i = 1; i < size; ++i){
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max) max = arr[i];
    }
    int k = max - min + 1;
    int* counts = new int[k]();
    for(int i = 0; i < size; ++i){
        counts[arr[i] - min]++;
    }

    int c = 0;
    for(int i = 0; i < k; ++i){
        while(counts[i] > 0){
            arr[c++] = i + min;
            counts[i]--;
        }
    }
    delete[] counts;
}

int main() {

    int arr[] = {19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 
        10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17};
    int size_arr = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Before: ";

    for(int i = 0; i < size_arr; ++i){
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    count_sort(arr, size_arr);

    std::cout << "After: ";

    for(int i = 0; i < size_arr; ++i){
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;


    return 0;
}