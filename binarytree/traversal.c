#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode TreeNode;

// left root right
void inorder(TreeNode* root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

// left right root
void postorder(TreeNode* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

// root left right
void preorder(TreeNode* root) {
    if(root == NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}


int main() {
    TreeNode* root = (TreeNode*) malloc(sizeof(TreeNode));
    root->data = 2;

    root->left = (TreeNode*) malloc(sizeof(TreeNode));
    root->left->data = 3;

    root->right = (TreeNode*) malloc(sizeof(TreeNode));
    root->right->data = 4;

    root->left->left = (TreeNode*) malloc(sizeof(TreeNode));
    root->left->left->data = 5;

    postorder(root);

    return 0;
}