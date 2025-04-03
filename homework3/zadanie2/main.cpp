#include <iostream>

int pivoting(int* A, int size_A){
    int left = 0;
    int right = size_A - 1;

    int pivot = A[size_A / 2];

    while(true) {
        while(A[left] < pivot){
            left++;
        }
        while(A[right] > pivot){
            right--;
        }
        if(left >= right){
            return left;
        }
        std::swap(A[left], A[right]);
        left++;
        right--;
    }
}

void quick_sort(int* arr, int size) {
    if(size <= 1){
        return;
    }
    int border = pivoting(arr, size);
    quick_sort(arr, border);
    quick_sort(arr + border, size - border);
}



int main() {

    int arr[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    int size_arr = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Before: ";

    for(int i = 0; i < size_arr; ++i){
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    quick_sort(arr, size_arr);

    std::cout << "After: ";

    for(int i = 0; i < size_arr; ++i){
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;


    return 0;
}