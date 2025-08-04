//Brute Approach
            //Since it is a BST .So, its inorder traversal will give us alist of int.
            //in sorted format.
            //Then we can think of that as an array and use the normal two sum approach
/*
Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class BSTIterator{
    stack<Node*> st;
    bool reverse = true;
public :
    BSTIterator(Node *root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    bool hasNext(){
        return !st.empty();
    }
    int next(){
        Node *temp = st.top();
        st.pop();
        if(!reverse) pushAll(temp->right);
        else    pushAll(temp->left);
        return temp->data;
    }
private :
    void pushAll(Node *node){
        for( ; node != NULL; ){
            st.push(node);
            if(reverse == true){
                node = node->right;
            }
            else{
                node = node->left;
            }
        }
    }
};
class Solution {
  public:
    bool findTarget(Node *root, int target) {
        if(!root)   return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i + j == target){
                return true;
            }
            else if(i+j<target){
                i = l.next();
            }
            else{
                j = r.next();
            }
        }
        return false;
            
        
    }
};