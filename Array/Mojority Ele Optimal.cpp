class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        // n/3 + n/3 = 2n/3 i.e. at max there can only be two majoruty elements in the array
        int ele1 = -1;
        int ele2 = -1;
        int cnt1 = 0;
        int cnt2 = 0;
        //Applying Boyer's Moore's Algorithm
        for(int ele : arr){
            if(ele == ele1){
                cnt1++;
            }
            else if (ele == ele2){
                cnt2++;
            }
            else if(cnt1 == 0){
                ele1 = ele;
                cnt1 = 1;
            }
            else if (cnt2 == 0){
                ele2 = ele;
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        //Till now we have found our two elements
        cnt1 = 0;   //ele1 = 2
        cnt2 = 0;   //ele2 = 1
        vector<int> ans;
        for(int i = 0; i<n; i++){
            if(arr[i] == ele1)  cnt1++;
            if(arr[i] == ele2)  cnt2++;
        }
        if(cnt1>n/3)   ans.push_back(ele1);
        if(cnt2>n/3 && ele1 != ele2)    ans.push_back(ele2);
        if(ans.size() == 2 && ans[0]>ans[1]){
            swap(ans[0],ans[1]);
        }
        return ans;
        
    }
};