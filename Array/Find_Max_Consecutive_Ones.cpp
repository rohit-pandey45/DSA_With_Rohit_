#include <iostream>
#include<vector>
#include<set>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& arr){
    int n = arr.size();
    int maxi = 0;
    int count = 0;
    for (int i = 0; i<n; i++){
        if (arr[i] == 1){
            count++;
            maxi = max(count,maxi);
        }
        else{
            count = 0;
        }
    }
    return maxi;
}
int main()
{
    vector<int> arr = {1,1,2,1,1,1,3,1,1,1,1};
    int result = findMaxConsecutiveOnes(arr);
    cout<<result<<" ";
    

    return 0;
}
