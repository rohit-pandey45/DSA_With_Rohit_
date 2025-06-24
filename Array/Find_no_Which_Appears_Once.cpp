#include <iostream>
#include<vector>
#include<set>
using namespace std;
int numberAppearsOnes(vector<int>& arr){
    int n = arr.size();
    
    for (int i = 0; i<n; i++){
        int count = 0;
        int num = arr[i];
        for (int j = 0; j<n; j++){
            if (arr[j] == num){
                count++;
            }
        }
        if (count == 1) return num;
    }
    return 0;
}
int main()
{
    vector<int> arr = {1,1,2,3,3,3};
    int result = numberAppearsOnes(arr);
    cout<<result<<" ";
    

    return 0;
}
