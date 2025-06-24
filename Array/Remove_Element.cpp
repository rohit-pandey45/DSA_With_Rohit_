#include <iostream>
#include<vector>
#include<set>
using namespace std;
int numberAppearsOnes(vector<int>& arr,int val){
    int n = arr.size();
    int k = 0;
    for (int i = 0; i<n; i++){
        if (arr[i] != val){
            arr[k] = arr[i];
            k++;	
        }
    }
    return k;
}
int main()
{
    vector<int> arr = {1,2,3,4};
    int val = 4;
    int result = numberAppearsOnes(arr,val);
    cout<<result<<" ";
    

    return 0;
}
