class Solution {
public:
    void markParents(Node* root, unordered_map<Node*, Node*>& parent_track) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }

            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }

    Node* findTarget(Node* root, int target) {
        if (!root) return nullptr;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr->data == target)
                return curr;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        return nullptr;
    }

    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent_track;
        markParents(root, parent_track);

        Node* targetNode = findTarget(root, target);

        unordered_map<Node*, bool> visited;
        queue<Node*> q;

        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool burned = false;

            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                if (curr->left && !visited[curr->left]) {
                    burned = true;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }

                if (curr->right && !visited[curr->right]) {
                    burned = true;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }

                if (parent_track.count(curr) &&
                    !visited[parent_track[curr]]) {
                    burned = true;
                    visited[parent_track[curr]] = true;
                    q.push(parent_track[curr]);
                }
            }

            if (burned) time++;
        }

        return time;
    }
};