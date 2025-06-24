#include <iostream>
#include<vector>
#include<set>
using namespace std;
vector<int> pushZerostoEnd(vector<int>& arr){
    int j = -1;
    int n = arr.size();
    for (int i = 0; i<n; i++){
        if (arr[i] == 0){
            j = i;
            break;
        }
    }
    if (j == -1) return arr;
    for (int i = j+1; i<n; i++){
        if (arr[i] != 0){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
    return arr;
}

int main()
{
    vector<int> arr = {1,2,0,5,7,0,9,0,4,0,4,7,5};
    vector<int> result = pushZerostoEnd(arr);
    for (int i : result){
        cout<<i<<" ";
    }
    
    
    return 0;
}
