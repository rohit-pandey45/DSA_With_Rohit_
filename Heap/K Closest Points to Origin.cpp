class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //We will store the Points and the distance b/w the points and the origin in a priority queue
        priority_queue<pair<int,vector<int>>> maxHeap;
        //Iterating through and calculating the dist for each set of points
        for(auto& point: points){
            int x = point[0];
            int y = point[1];
            int dist = (x*x) + (y*y);
            //Pushing the points and distance calculated to the maxheap
            maxHeap.push({dist,point});
            //if the size of maxheap exceeds the limit k we start popping from the front 
            //that means that we pop the farthest point from the maxheap
            //since it is a maxheap it will store the fathest distance at the top
            if(maxHeap.size() > k){
                maxHeap.pop();      //Removing the farthest Point
            }
        }
        //We will store the result in ans;
        vector<vector<int>> ans;
        //Till the heap is not empty we keep pushing the closest points  to our ans vector
        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};