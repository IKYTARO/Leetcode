#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<int> InorderTraversal(TreeNode *root) {
    if (!root) {
        return {};
    }

    std::vector<int> inorderTraversal{};
    std::stack<TreeNode *> stack{};
    TreeNode *currNode = root;

    while (currNode || !stack.empty()) {
        while (currNode) {
            stack.push(currNode);
            currNode = currNode->left;
        }

        currNode = stack.top();
        inorderTraversal.emplace_back(currNode->val);
        stack.pop();

        currNode = currNode->right;
    }

    return inorderTraversal;
}