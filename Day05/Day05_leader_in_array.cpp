#include <iostream>
#include <vector>
using namespace std;

void leaderInArray(int* a, int n){
    vector<int> vec;

    int max_right = a[n-1];
    vec.push_back(max_right);    

    for(int i = n-2; i >= 0; i--){
        if(a[i] > max_right){
            vec.push_back(a[i]);
            max_right = a[i];

        }
    }
    std::cout << "Leaders are: " ;
    for(int i = vec.size() - 1; i >= 0; i--){
        std::cout << vec[i] << " ";
    } 

}

int main(){

    int a[] = {16, 17, 4, 3, 5, 2};  
    int n = sizeof(a) / sizeof(a[0]);
    leaderInArray(a, n);
    return 0;

}