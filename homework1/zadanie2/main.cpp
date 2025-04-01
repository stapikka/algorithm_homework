#include <iostream>

int calc(int* arr,int size, int point){
    int left = 0;
    int right = size;
    while(left < right){
        int mid = left + (right - left) / 2;
        if(arr[mid] > point)
            right = mid;
        else 
            left = mid + 1;
    }
    return size - left;
}

int main() {
    int arr[] = {14, 16, 19, 32, 32, 32, 56, 69, 72};
    int size = sizeof(arr) / sizeof(arr[0]);
    int point{};

    std::cout << "Enter start point!\n";
    std::cin >> point;

    std::cout << "Count of elemetns greater than your point: " 
        << calc(arr,size, point) << std::endl;

    return 0;
}