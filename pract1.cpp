#include <iostream>

void D(int** arr, size_t x){
    for (unsigned int i=0;i<x;i++){
        delete[] arr[i];
    }
    delete[] arr;
}
void V(int** arr, size_t a, size_t b){
    for (unsigned int i = 0;i<b;i++){
        for (unsigned int j = 0;j<a;j++){
            std::cout<<arr[i][j]<<" ";
        }
    std::cout<<std::endl;
    }
    D(arr,b);
}
int main()
{
    int a1 = 0; int b1 = 0;
    std::cin>>a1;
    std::cin>>b1;
    if (std::cin.fail() or a1<=0 or b1<=0){
        return 1;
    }
    size_t a = a1;
    size_t b = b1;
    int** arr = nullptr;
    size_t fill = 0;
    try{
        arr = new int*[b];
        for (;fill<b;fill++){
            arr[fill] = new int[a];
        }
    }
    catch(std::bad_alloc){
        D(arr,fill);
        return 2;
    }
    for (unsigned int i = 0;i<a;i++){
        for (unsigned int j = 0;j<b;j++){
            std::cin>>arr[j][i];
            if (std::cin.fail()){
                D(arr,b);
                return 1;
            };
        }
    }
    V(arr,a,b);
    return 0;
}