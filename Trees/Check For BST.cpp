/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool checkBST(Node* root, long long minval, long long maxval){
        if(root == NULL)    return true;
        if(root->data <= minval || root->data >= maxval)    return false;
        
        return checkBST(root->left, minval,root->data) && checkBST(root->right,root->data,maxval);
    }
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        return checkBST(root, LLONG_MIN, LLONG_MAX);
        
    }
};