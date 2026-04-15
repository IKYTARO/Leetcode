#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode *root) {
    if (!root) {
        return 0;
    }

    int depth{};
    std::stack<std::pair<TreeNode *, int>> stack{};
    stack.push({root, 1});

    while (!stack.empty()) {
        auto [curr_node, curr_depth] = stack.top();
        stack.pop();

        depth = std::max(depth, curr_depth);

        if (curr_node->right) {
            stack.push({curr_node->right, curr_depth + 1});
        }

        if (curr_node->left) {
            stack.push({curr_node->left, curr_depth + 1});
        }
    }

    return depth;
}