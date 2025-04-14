#include <iostream>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Tree {
public:
    TreeNode* root;
    Tree(): root(nullptr) {}
    TreeNode* InsertHelper(TreeNode* node, int x){
        if(node == nullptr) return new TreeNode(x);
        if(x < node->val)
            node->left = InsertHelper(node->left, x);
        else
            node->right = InsertHelper(node->right, x);
        return node;
    }
    void Insert(int x){
        root = InsertHelper(root, x);
    }
    bool isSameTree(TreeNode* a, TreeNode* b){
        if(a == nullptr && b == nullptr) return true;
        if(a == nullptr || b == nullptr) return false;
        if(a->val != b->val) return false;
        return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
    }
    int IsSameTree(Tree *p){
        return isSameTree(root, p->root) ? 1 : 0;
    }
};

int main(){
    int n, m, x;
    std::cin >> n;
    Tree tree1;
    for(int i = 0; i < n; i++){
        std::cin >> x;
        tree1.Insert(x);
    }
    std::cin >> m;
    Tree tree2;
    for(int i = 0; i < m; i++){
        std::cin >> x;
        tree2.Insert(x);
    }
    std::cout << tree1.IsSameTree(&tree2);
}