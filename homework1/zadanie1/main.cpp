#include <iostream>

int calc(int* arr, int size)
{
  int ans = 0;
  for (int i = 1; i < size; i++)
  {
    ans += arr[i] - arr[i-1];
  }
  return ans;
}


int main(){

    int arr[] = {1, 3, 5, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << calc(arr, size) << std::endl;

    return 0;
}