#include <iostream>

unsigned long long int fibo(int x){
    if(x == 1 || x == 2){
        return 1;
    }
    if(x == 0){
        return 0;
    }
    return fibo(x - 1) + fibo(x - 2); 
}

int main(){

    std::cout << fibo(6) << std::endl;
    return 0;
}