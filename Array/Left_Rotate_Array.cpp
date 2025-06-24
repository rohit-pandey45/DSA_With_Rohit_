//OPTIMAL APPROACH
#include <iostream>
#include<vector>
using namespace std;
void leftRotate(vector<int> arr, int k){
    int n = arr.size();
    k = k%n;
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());
    reverse(arr.begin(),arr.end());
    for (int i : arr){
       cout<<i<<" ";
   }
}
int main()
{
   vector<int> arr = {1,2,3,4,5,6};
   int k = 3;
   leftRotate(arr,k);
   
    return 0;
}

