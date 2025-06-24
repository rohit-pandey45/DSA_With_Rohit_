#include <iostream>
#include<vector>
#include<set>
using namespace std;
int getSecondLargest(vector<int>& arr){
    int largest = -1;
    int second_largest = -1;
    int n = arr.size();
    for (int i = 0; i<n; i++){
        if (arr[i]>largest){
            largest = arr[i];
        }
    }
    for (int i = 0; i<n; i++){
        if (arr[i]>second_largest && arr[i] != largest){
            second_largest = arr[i];
        }
    }
    return second_largest;
}
int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    cout<<getSecondLargest(arr);
   

    return 0;
}
