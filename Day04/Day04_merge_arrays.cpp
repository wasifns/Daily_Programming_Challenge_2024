#include <iostream>
#include <cmath>
using namespace std;

int getGap(int gap){
    if(gap <= 1){
    return 0;
    }
    return (gap / 2 + (gap % 2));
}
void mergeArrays(int a1[], int a2[], int a1_size, int a2_size){
    int gap = a1_size + a2_size;

    for(gap = getGap(gap); gap > 0; gap = getGap(gap)){
        //for a1 elements
        for(int i = 0; i + gap < a1_size; i++){
            if(a1[i] > a2[i + gap]){
                swap(a1[i], a2[i + gap]);
            }
        }

        //for a1 and a2 elements
           for(int i = max(0, a1_size - gap), j = gap - a1_size > 0 ? gap - a1_size : 0; i < a1_size && j < a2_size; i++, j++) {
            if (a1[i] > a2[j]) {
                swap(a1[i], a2[j]);
            }
        }

        //for a2 elements
        for (int j = 0; j + gap < a2_size; j++) {
            if (a2[j] > a2[j + gap]) {
                swap(a2[j], a2[j + gap]);
            }
        }
    }
}

int main(){
    int a1[] = {1,3,5,7};
    int a2[] = {2,4,6,8};
    int a1_size = sizeof(a1) / sizeof(a1[0]);
    int a2_size = sizeof(a2) / sizeof(a2[0]);
    
    mergeArrays(a1, a2, a1_size, a2_size);

    //output of a1 sorted array
    for(int i = 0; i < a1_size; i++){
        std::cout <<  a1[i] << " ";

    }

    //output for a2 sorted array
    for(int i = 0; i < a2_size; i++){
        std::cout << a2[i] << " ";
    }

    return 0;

}