#include "bits/stdc++.h"

int main(){
    std::vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    do{
        for(const int x : arr){
            printf("%d ", x);
        }
        printf("\n");
    }while (std::next_permutation(arr.begin(), arr.end()));
    return 0;
}
