/*
Definition for Node
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
    int minValue(Node* root) {
        if(root == nullptr)    return 0;
        int mini = root->data;
        while(root->left){
            root = root->left;
            mini = root->data;
        }
        return mini;
        
        
    }
};