
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        //Elements are already sorted
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int count = 0;
        while(low<high){
            int sum = arr[low]+arr[high];       //calculating sum of pair
            if (sum<target){
                low++;
            }
            else if (sum>target){
                high--;
            }
            else{
                int ele1 = arr[low], ele2 = arr[high];
                int cnt1 = 0, cnt2 = 0;
                //Calulation Frequency of arr[low]
                while(low<=high && arr[low] == ele1){
                    low++;
                    cnt1++;
                }
                //Calculating Frequency of arr[high]
                while(low<=high && arr[high] == ele2){
                    high--;
                    cnt2++;
                }
                if(ele1 == ele2){           //arr = [1,1,1,1] total possible pairs = 6(cnt1*(cnt1-1)/2),cnt1 = 4, (target = 2)
                    count += (cnt1*(cnt1-1)/2);
                }
                else{           //arr=[-1,1,5,5,7] ele1 = 1, ele2 = 5, cnt1 = 1, cnt2 = 2, no. of pairs = 2(cnt1*cnt2)
                    count += cnt1*cnt2;
                }
            }
        }
        return count;
    }
};