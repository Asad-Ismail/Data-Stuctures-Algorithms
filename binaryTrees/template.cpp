void inOrder(TreeNode* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void preOrder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}


void postOrder(TreeNode* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

int maxDepth(TreeNode* root) {
    if (root == NULL) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

bool isSymmetric(TreeNode* root) {
    return isMirror(root, root);
}

bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL || t2 == NULL) return false;
    return (t1->val == t2->val) && isMirror(t1->right, t2->left) && isMirror(t1->left, t2->right);
}

bool hasPathSum(TreeNode* root, int sum) {
    if (root == NULL) return false;
    sum -= root->val;
    if (root->left == NULL && root->right == NULL) {
        return (sum == 0);
    }
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}
