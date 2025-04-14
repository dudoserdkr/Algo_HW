#include <iostream>
#include <string>
#include <vector>
#include <cctype>

class TreeNode {
public:
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char c): val(c), left(nullptr), right(nullptr) {}
};

class Tree {
public:
    TreeNode* root;
    Tree(): root(nullptr) {}
    TreeNode* InsertHelper(TreeNode* node, char c) {
        if (node == nullptr)
            return new TreeNode(c);
        if (c < node->val)
            node->left = InsertHelper(node->left, c);
        else
            node->right = InsertHelper(node->right, c);
        return node;
    }
    void Insert(char c) {
        root = InsertHelper(root, c);
    }
    void Preorder(TreeNode* node) {
        if (node == nullptr)
            return;
        std::cout << node->val;
        Preorder(node->left);
        Preorder(node->right);
    }
    void PrintPreorder() {
        Preorder(root);
    }
};

std::string trim(const std::string &s) {
    std::string result;
    for (char c : s) {
        if (!std::isspace(c))
            result.push_back(c);
    }
    return result;
}

int main(){
    std::vector<std::string> rounds;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::string trimmed = trim(line);
        if (trimmed == "*")
            break;
        if (!trimmed.empty())
            rounds.push_back(trimmed);
    }
    Tree tree;
    for (int i = rounds.size() - 1; i >= 0; i--) {
        for (char c : rounds[i])
            tree.Insert(c);
    }
    tree.PrintPreorder();
}