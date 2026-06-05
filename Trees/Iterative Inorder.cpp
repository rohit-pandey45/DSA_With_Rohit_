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
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        stack<Node* > st;
        Node* node = root;
        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()){
                    break;
                }
                node = st.top();
                st.pop();
                ans.push_back(node->data);
                node = node->right;
            }
        }
        return ans;
    }
};