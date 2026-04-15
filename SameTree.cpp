#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode *p, TreeNode *q) {
    std::stack<TreeNode *> stack_p{}, stack_q{};
    stack_p.push(p);
    stack_q.push(q);

    while (!stack_p.empty() && !stack_q.empty()) {
        TreeNode *curr_p = stack_p.top();
        TreeNode *curr_q = stack_q.top();
        stack_p.pop();
        stack_q.pop();

        if (!curr_p && !curr_q) continue;

        if ((curr_p == nullptr) != (curr_q == nullptr)) return false;

        if (curr_p->val != curr_q->val) return false;

        stack_p.push(curr_p->right);
        stack_p.push(curr_p->left);

        stack_q.push(curr_q->right);
        stack_q.push(curr_q->left);
    }

    return (stack_p.empty() && stack_q.empty());
}