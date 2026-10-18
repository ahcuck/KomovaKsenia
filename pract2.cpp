#include<iostream>
#include<algorithm>

int** concat_rows(const int* const* lhs, size_t n1, size_t m1, const int* const* rhs, size_t n2, size_t m2 )
{
    int n = std::max(n1,n2);
    int** arr = new int*[n];
    if (n==n1 and n==n2){
        for (size_t i = 0; i<n; i++){
            arr[i] = new int[m1+m2];
            for (size_t j = 0; j<m1;j++){
                arr[i][j] = lhs[i][j];
                std::cout<<arr[i][j]<<" ";
            }
            for (size_t j = 0; j<m2;j++){
                arr[i][j+m1] = rhs[i][j];
                std::cout<<arr[i][j+m1]<<" ";
            }
            std::cout<<std::endl;
        }
    }else if (n==n1){
        for (size_t i = 0; i<n2; i++){
            arr[i] = new int[m1+m2];
            for (size_t j = 0; j<m1;j++){
                arr[i][j] = lhs[i][j];
                std::cout<<arr[i][j]<<" ";
            }
            for (size_t j = 0; j<m2;j++){
                arr[i][j+m1] = rhs[i][j];
                std::cout<<arr[i][j+m1]<<" ";
            }
            std::cout<<std::endl;
        }
        for (size_t i = n2; i<n;i++){
            arr[i] = new int[m1];
            for (size_t j = 0; j<m1;j++){
                arr[i][j] = lhs[i][j];
                std::cout<<arr[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
    }else{
        for (size_t i = 0; i<n1; i++){
            arr[i] = new int[m1+m2];
            for (size_t j = 0; j<m1;j++){
                arr[i][j] = lhs[i][j];
                std::cout<<arr[i][j]<<" ";
            }
            for (size_t j = 0; j<m2;j++){
                arr[i][j+m1] = rhs[i][j];
                std::cout<<arr[i][j+m1]<<" ";
            }
            std::cout<<std::endl;
        }
        for (size_t i = n1; i<n;i++){
            arr[i] = new int[m2];
            for (size_t j = 0; j<m2;j++){
                arr[i][j] = rhs[i][j];
                std::cout<<arr[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
    }
    return arr;
}

void D(int** arr, size_t x){
    for (size_t i=0;i<x;i++){
        delete[] arr[i];
    }
    delete[] arr;
}

 int main()
 {
    long long n01 = 0; long long m01 = 0; long long n02 = 0; long long m02 = 0;
    std::cin>>n01;
    std::cin>>m01;
    std::cin>>n02;
    std::cin>>m02;
    if (std::cin.fail() or n01<=0 or m01<=0 or n02<=0 or m02<=0){
        return 1;
    }
    size_t n1 = n01;
    size_t m1 = m01;
    size_t n2 = n02;
    size_t m2 = m02;
    std::cout<<"Матрица 1: ";
    size_t fill1 = 0; size_t fill2 = 0;
    int** lhs = nullptr;
    int** rhs = nullptr;
    int** result = nullptr;
    try{
        lhs = new int*[n1];
        for (;fill1<n1;fill1++){
            lhs[fill1]=new int[m1];
            for (size_t j = 0;j<m1;j++){
                std::cin>>lhs[fill1][j];
            }
        }
        std::cout<<"Матрица 2: ";
        rhs = new int*[n2];
        for (;fill2<n2;fill2++){
            rhs[fill2]=new int[m2];
            for (size_t j = 0;j<m2;j++){
                std::cin>>rhs[fill2][j];
            }
        }
        if (std::cin.fail()){
                D(lhs,n1);
                D(rhs,n2);
            return 1;
        }
        result =concat_rows(lhs,n1,m1,rhs,n2,m2);
    }catch(std::bad_alloc){
        D(lhs,fill1);
        D(rhs,fill2);
        return 2;
    }catch(std::overflow_error){
        D(lhs,fill1);
        D(rhs,fill2);
        return 2;
    }
    D(lhs,n1);
    D(rhs,n2);
    D(result,std::max(n1,n2));
 }