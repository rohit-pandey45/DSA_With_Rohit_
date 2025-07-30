// User Fuction template for C++
/*
// Tree Node
class Node {
public:
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
    int maxPathDown(Node* root, int& maxi){
        if(root == NULL)    return 0;
        int leftsum = max(0, maxPathDown(root->left,maxi));
        int rightsum = max(0, maxPathDown(root->right,maxi));
        maxi = max(maxi,root->data + leftsum + rightsum);
        return max(leftsum,rightsum) + root->data;
    }
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        int maxi  = INT_MIN;
        maxPathDown(root,maxi);
        return maxi;
        
    }
};