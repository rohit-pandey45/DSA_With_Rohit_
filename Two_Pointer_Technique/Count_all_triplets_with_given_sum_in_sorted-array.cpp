class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int n = arr.size();
        if(n<3){
            return 0;
        }
        // sort(arr.begin(),arr.end());
        
        int count = 0;
        for(int i = 0; i<n; i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = arr[i]+arr[j]+arr[k];
                if(sum<target){
                    j++;
                }
                else if (sum>target){
                    k--;
                }
                else{
                    int ele1 = arr[j], ele2 = arr[k], c1 = 0, c2 = 0;
                    while(j<=k && arr[j]==ele1){
                        c1++;
                        j++;
                    }
                    while(j<=k && arr[k]==ele2){
                        c2++;
                        k--;
                    }
                    if(ele1 == ele2){
                        count += (c1*(c1-1))/2;
                    }
                    else{
                        count += c1*c2;
                    }
                }
            }
        }
        return count;
    }
};