//BRUTE SOLUTION
// int main()
// {
//   vector<int> arr = {1,2,3,4,5,3,4,5};
//   vector<int> brr = {3,4,5,6,7,4,5,6};
//   set<int> st;
//   for (int i = 0; i<arr.size(); i++){
//       st.insert(arr[i]);
//   }
  
//   for (int i = 0; i<brr.size(); i++){
//       st.insert(arr[i]);
//   }
//   int i = 0;
//   vector<int> temp;
//   for (auto it : st){
//       temp.push_back(it);
//   }
//   for (int i : temp){
//       cout<<i<<" ";
//   }
//(OPTIMAL)
#include <iostream>
#include<vector>
#include<set>
using namespace std;

int main()
{
  vector<int> arr = {1,2,3,4,5,3,4,5};
  vector<int> brr = {3,4,5,6,7,4,5,6};
  int n1 = arr.size();
  int n2 = brr.size();
  vector<int> Unionarr;
  int i =0, j = 0;
  while (i<n1 && j<n2){
      if (arr[i] <= brr[i]){
          if (Unionarr.back() == 0 || Unionarr.back() != arr[i]){
              Unionarr.push_back(arr[i]);
          }
          i++;
      }
      else{
          if (Unionarr.back() == 0 || Unionarr.back() != brr[i]){
              Unionarr.push_back(brr[i]);
          }
          j++;
      }
  }
  while (i<n1){
      if (Unionarr.back() == 0 || Unionarr.back() != arr[i]){
              Unionarr.push_back(arr[i]);
          }
          i++;
  }
  while (j<n2){
       if (Unionarr.back() == 0 || Unionarr.back() != brr[i]){
              Unionarr.push_back(brr[i]);
          }
          j++;
  }
  int n = Unionarr.size();
  for (int i = 0; i<n; i++){
      cout<<Unionarr[i]<<" ";
  }
 
   
    
    
    return 0;
}
