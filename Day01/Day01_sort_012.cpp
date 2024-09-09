#include <iostream>
using namespace std;

//Dynamic array 
void arrayInput(int* arr, int size){
    int ele = 1;
    for(int i = 0; i < size; i++){
        std::cout << "Enter element " << ele++ << ":" ;
        std::cin >> arr[i];
        
    }
}
void sort_012(int* arr, int size){
    //counters
    int n0 = 0,n1 = 0,n2 = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] == 0){
            n0 += 1; //number of 0's
        }
        else if(arr[i] == 1){
            n1 += 1; //number of 1's
        }
        else{
            n2 += 1; //number of 2's
        }
    }

    //Edge case handling 
    // 1. Empty array
    if(size == 0){
        cout << "Array is empty\n";
        return;
    }
    // 2. All elements are the same
    if ((n0 == size) || (n1 == size) || (n2 == size)) {
        cout << "All elements are the same\n";
        return;  
    }

    // 3. Already sorted
    bool sort = true;
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            sort = false;
            break;
        }
    }
    
    //Rearranging elements in array in 0 1 2 order
    int placer = 0;
    for (int i = 0; i < n0; i++){
        arr[placer++] = 0;
    }
    for (int i = 0; i < n1; i++){
        arr[placer++] = 1;
    }
    for (int i = 0; i < n2; i++){
        arr[placer++] = 2;
    } 

};
int main(){
    int size;
    std::cout << "Enter the number of elements\n";
    std::cin >> size;
    int* arr = new int[size];
    arrayInput(arr, size);
    sort_012(arr,size);
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    
    return 0;

}