class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> maxheap;
        priority_queue<int,vector<int>,greater<int>> minheap;
        vector<double> ans;
        for(int i : arr){
            maxheap.push(i);
            minheap.push(maxheap.top());
            maxheap.pop();
            if(minheap.size() > maxheap.size()){
                maxheap.push(minheap.top());
                minheap.pop();
            }
            if(maxheap.size() > minheap.size()){
                ans.push_back(maxheap.top());
            }
            else{
                double median = (maxheap.top() + minheap.top()) / 2.0;
                ans.push_back(median);
            }
        }
        return ans;
    }
};
