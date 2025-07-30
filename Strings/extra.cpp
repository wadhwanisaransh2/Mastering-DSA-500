class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both nodes are null → trees are same up to this point
        if (!p && !q) return true;

        // One is null and other is not → trees differ
        if (!p || !q) return false;

        // Values don't match → trees differ
        if (p->val != q->val) return false;

        // Recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
