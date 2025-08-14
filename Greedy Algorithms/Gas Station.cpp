/*You are required to complete this method*/
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int totalgas = 0, totalcost = 0, start = 0, fuel = 0;
        for(int i= 0; i<n; i++){
            totalgas += gas[i];
            totalcost += cost[i];
            fuel += gas[i] - cost[i];
            //Computing starting index
            if(fuel<0){
                start = i+1;
                fuel = 0;
            }
        }
        //if total gas is less than totalcost then it is not possible tot travel all the stations so return -1 else return starting index
        return ((totalgas >= totalcost) ? start : -1);
        
    }
};