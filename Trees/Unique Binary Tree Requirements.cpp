class Solution {
  public:
    bool isPossible(int a, int b) {
        return (a == 2 || b == 2) && (a != b);
    }
};
/*
Preorder + Inorder → Unique ✅
Postorder + Inorder → Unique ✅
Inorder + Preorder → Unique ✅
Inorder + Postorder → Unique ✅
Preorder + Postorder → Not unique ❌
Preorder + Preorder, Inorder + Inorder, etc. → Not enough information ❌
*/