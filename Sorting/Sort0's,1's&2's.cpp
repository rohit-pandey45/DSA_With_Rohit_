class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int mid = 0;
        int high = n-1;
    while(mid<=high){
        if (arr[mid] == 0){
            swap (arr[low], arr[mid]);
            mid++;
            low++;
        }
        else if (arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high --;
        }
    }
        
    }
};