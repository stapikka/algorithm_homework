#include <iostream>
#include <vector>

unsigned long long fibo(int x){
    if(x <= 0) return 0;
    if(x == 1) return 1;

    std::vector<unsigned long long> arr(x + 1);
    arr[0] = 0;
    arr[1] = 1;

    for(int i = 2; i <= x; ++i){
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[x];
}

int main(){

    int n;
    std::cout << "Enter Fibonacci num: ";
    std::cin >> n;
    if(n < 0){
        std::cout << "Error. Enter pozitive num!\n";
        return 1;
    }

    std::cout << "fibo(" << n << ") = " << fibo(n) << std::endl;


    return 0;
}