// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
  int preind = 0;
    Node *buildTreeHelper(vector<int> &inorder, vector<int> &preorder,int instart, int inend,unordered_map<int,int>& mpp){
        if(instart>inend)   return NULL;
        int rootval = preorder[preind++];
        Node* root = new Node(rootval);
        int inind = mpp[rootval];
        root->left = buildTreeHelper(inorder,preorder,instart,inind - 1,mpp);
        root->right = buildTreeHelper(inorder,preorder,inind + 1,inend, mpp);
        return root;
    }
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        unordered_map<int,int> mpp;
        int n = inorder.size();
        for(int i = 0; i<n; i++){
              mpp[inorder[i]] = i;
        }
        return buildTreeHelper(inorder,preorder,0, n-1,mpp);
        
    }
};