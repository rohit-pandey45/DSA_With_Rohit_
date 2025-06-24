#include <iostream>
#include<vector>
using namespace std;

//  Two Pointer Approach
vector<int> removeDuplicates(vector<int>& arr){
    int n = arr.size();
    int j = 0;
    for (int i = 1; i<n; i++){
        if (arr[j] != arr[i]){
            j++;
            arr[j] = arr[i];
        }
    }
    return arr;
}

int main()
{
    vector<int> arr = {1,1,2,2,2,3};
    vector<int> result = removeDuplicates(arr);
    for (int i : result){
        cout<<i<<" ";
    }
    
    
    return 0;
}
//(brute app.)
// #include <iostream>
// #include<vector>
// #include<set>
// using namespace std;

// //  Brute Approach


// int main()
// {
//    vector<int> arr = {1,1,2,2,2,3};
//    int n = arr.size();
//    set<int> st;
//    for (int i = 0; i<n; i++){
//        st.insert(arr[i]);       // uniqye elements gets stored in the set
//    }
//    int index = 0;
//    for (auto it : st){      //auto if you dont know the data type
//        arr[index] = it;     // it = iterator
//        index ++;            //all the unique elements gets stored in the array at the first . we have nothing to do with the elements at the last
//    }
//    for (int i = 0; i<n; i++){
//        cout<<arr[i]<<" ";
//    }
    
    
//     return 0;

