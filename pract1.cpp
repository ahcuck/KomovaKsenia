#include <iostream>

void D(int** arr, int x){
    for (int i=0;i<x;i++){
        delete[] arr[i];
    }
    delete[] arr;
}
void V(int** arr, int a, int b){
    for (int i = 0;i<b;i++){
        for (int j = 0;j<a;j++){
            std::cout<<arr[i][j]<<" ";
        }
    std::cout<<std::endl;
    }
    D(arr,b);
}
int main()
{
    int a = 0; int b = 0;
    std::cin>>a;
    std::cin>>b;
    if (a<=0 or b<=0){
        return 1;
    }
    int** arr = nullptr;
    int fill = 0;
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
    for (int i = 0;i<a;i++){
        for (int j = 0;j<b;j++){
            if (!(std::cin>>arr[j][i])){
                D(arr,b);
                return 1;
            };
        }
    }
    V(arr,a,b);
    return 0;
}