// User function Template for C++
class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        int slow = arr[0];
        int fast = arr[0];
        do{
            slow = arr[slow];
            fast = arr[arr[fast]];
        }while(slow != fast);
        slow = arr[0];
        while(slow != fast){
            slow = arr[slow];
            fast = arr[fast];
        }
        return slow;
        
    }
};