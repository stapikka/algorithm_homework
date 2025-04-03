#include <iostream>
#include <vector>

void merge(int* arr, int left, int mid, int right){
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int* temp = new int[right - left + 1];
    int i = left, j = mid + 1, k = 0;

    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];

    for(int i = 0; i < k; ++i){
        arr[left + i] = temp[i];
    }

    delete[] temp;
}

void merge_sort(int* arr, int size){
    if(size == 1){
        return;
    }

    int mid = size / 2;
    merge_sort(arr, mid);
    merge_sort(arr + mid, size - mid);
    merge(arr, 0, mid - 1, size - 1);
}


int main() {

    int arr[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    int size_arr = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Before: ";

    for(int i = 0; i < size_arr; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    merge_sort(arr, size_arr);

    std::cout << "After: ";

    for(int i = 0; i < size_arr; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

}