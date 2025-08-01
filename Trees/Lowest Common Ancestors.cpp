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
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if(root == NULL || root == n1 || root == n2){
            return root;
        }
        Node* leftLCA = LCA(root->left,n1,n2);
        Node* rightLCA = LCA(root->right,n1,n2);
        if(leftLCA && rightLCA){
            return root;
        }
        return (leftLCA != NULL)?leftLCA:rightLCA;
    }
};