/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void findpaths(Node* root, int k,int currsum, unordered_map<int,int>& mpp, int& count){
        if(root == NULL)    return;
        currsum += root->data;
        if(mpp.find(currsum - k) != mpp.end()){
            count += mpp[currsum - k];
        }
        mpp[currsum]++;
        findpaths(root->left,k,currsum,mpp,count);
        findpaths(root->right,k,currsum,mpp,count);
        //Backtrack
        mpp[currsum]--;
    }
        
    int sumK(Node *root, int k) {
        int count = 0;
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        findpaths(root,k,0,mpp,count);
        return count;
        
    }
};