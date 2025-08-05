/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        vector<int> a;
        if(root == NULL)    return a;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr == NULL){
                a.push_back(-1);
                continue;
            }
            a.push_back(curr->data);
            q.push(curr->left);
            q.push(curr->right);
        }
        return a;
        
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        if(arr.size() == 0 || arr[0] == -1) return NULL;
        queue<Node*> q;
        int index = 0;
        Node* root = new Node(arr[index++]);
        q.push(root);
        while(!q.empty() && index < arr.size()){
            Node* curr = q.front();
            q.pop();
            if(arr[index] != -1){
                curr->left = new Node(arr[index]);
                q.push(curr->left);
            }
            index++;
            if(index >= arr.size()){
                break;
            }
            if(arr[index] != -1){
                curr->right = new Node(arr[index]);
                q.push(curr->right);
            }
            index++;
        }
        return root;
    }
};