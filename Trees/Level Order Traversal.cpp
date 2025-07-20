/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> ans;
        if(root == NULL)    return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for(int i = 0; i<size; i++){
                Node* curnode = q.front();
                q.pop();
                
                if(curnode->left != NULL){
                    q.push(curnode->left);
                }
                if(curnode->right != NULL){
                    q.push(curnode->right);
                }
                level.push_back(curnode->data);
            }
            ans.push_back(level);
            
        }
        return ans;
    }
};