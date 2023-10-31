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

//Lowest Common Ancestor (LCA):
//Think of the LCA as the first intersection point when you travel up from both nodes towards the root.
//The template uses a post-order traversal, trying to find either of the nodes p or q.

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}


//Balanced Binary Tree:
//A balanced tree roughly means that the depth of the left and right subtrees of every node differ by at most 1.
//If either subtree is not balanced, we propagate -1 upwards to signal imbalance.

bool isBalanced(TreeNode* root) {
    return getHeight(root) != -1;
}

int getHeight(TreeNode* root) {
    if (!root) return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
        return -1;
    }
    return max(leftHeight, rightHeight) + 1;
}


//Sorted Array to BST:
//The middle element becomes the root, and the two halves become left and right subtrees.
//This ensures balance because we pick the middle element each time.

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
}

TreeNode* helper(vector<int>& nums, int left, int right) {
    if (left > right) return NULL;
    int mid = (left + right) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = helper(nums, left, mid - 1);
    root->right = helper(nums, mid + 1, right);
    return root;
}

//Preorder and Inorder to Tree:
//In preorder, the first element is the root.
 //In inorder, elements to the left of the root are in the left subtree
 //, and elements to the right are in the right subtree.


unordered_map<int, int> indexMap;
int preIndex = 0;

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for (int i = 0; i < inorder.size(); i++) {
        indexMap[inorder[i]] = i;
    }
    return buildTreeHelper(preorder, 0, inorder.size() - 1);
}

TreeNode* buildTreeHelper(vector<int>& preorder, int left, int right) {
    if (left > right) return NULL;
    int rootVal = preorder[preIndex++];
    TreeNode* root = new TreeNode(rootVal);
    root->left = buildTreeHelper(preorder, left, indexMap[rootVal] - 1);
    root->right = buildTreeHelper(preorder, indexMap[rootVal] + 1, right);
    return root;
}
void findPathSum(TreeNode* root, int sum, vector<int>& path) {
    if (!root) return;  // Base case
    
    // Update the sum and add the current node to the path
    sum -= root->val;
    path.push_back(root->val);
    
    // Check for leaf node and if sum becomes zero, print the path
    if (!root->left && !root->right && sum == 0) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    // Recursive step: Explore the left and right subtrees
    findPathSum(root->left, sum, path);
    findPathSum(root->right, sum, path);
    
    // Backtrack to explore other paths
    path.pop_back();
}
