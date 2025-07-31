/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool isLeaf(Node *root){
        return (root->left == NULL && root->right == NULL);
    }
    void addLeftBoundary(Node *root, vector<int>& ans){
        Node *cur = root->left;
        while(cur){
            //If current node is not a leaf node then put it in the array
            if(!isLeaf(cur))    ans.push_back(cur->data);
            //Go as left as possible
            if(cur->left != NULL)   cur = cur->left;
            else        cur = cur->right;
        }
    }
    void addLeaves(Node *root, vector<int>& ans){
        //For leaves we will do inorder traversal
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        if(root->left != NULL)  addLeaves(root->left,ans);
        if(root->right != NULL)  addLeaves(root->right,ans);
    }
    void addRightBoundary(Node *root, vector<int>& ans){
        Node *cur = root->right;
        vector<int> temp;
        while(cur){
            //If current node is not a leaf node then put it in the array
            if(!isLeaf(cur))    temp.push_back(cur->data);
            //Go as right as possible
            if(cur->right != NULL)   cur = cur->right;
            else        cur = cur->left;
        }
        //Add all the elements in the temp arr to ans array (backwards)
        for(int i = temp.size()-1; i>=0; i--){
            ans.push_back(temp[i]);
        }
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        //If root is Null then return empty vector array
        if(root == NULL) return ans;
        //if root is not leaf then push it to the vector array
        if(!isLeaf(root)) ans.push_back(root->data);
        addLeftBoundary(root,ans);
        addLeaves(root,ans);
        addRightBoundary(root,ans);
        return ans;
    }
};
