//Brute
    //Inorder Traversal -> Sort the Inorder Traversal -> Make one pointer to iterate through the bst and also the array where you have stored the inorder traversal and make the changes as necessary
    //TC : o(nlogn)+o(2n)       ;       SC :o(n)[array]
//Optimal
//Generate inorder Traversal : TC:O(n)
    //Swap can have two cases
    //1. Swapped Nodes are not adjacent  (3 25 7 8 10 15 20 5)
    //2. Swapped Nodes are Adjacent     (3 5 8 7 10 15 20 25)
    //TC : O(n)     ; SC : O(1)
//CODE
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
private:
    void inorder(TreeNode* root){
        if(root == NULL)    return;
        inorder(root->left);
        if(prev != NULL && (root->val<prev->val)){
            //If this is first Violation mark these two nodes as 'first' and 'middle'
            if(first == NULL){
                first = prev;
                middle = root;
            }
            //If second violation mark this node a slast
            else{
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last)   swap(first->val,last->val);
        else if(first && middle)    swap(first->val,middle->val);
    }
};
