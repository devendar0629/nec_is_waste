#include<stdio.h>
#include<stdlib.h>

struct BSTNode {
    int data;
    struct BSTNode *left,*right;
};

typedef struct BSTNode BSTNode;

void printInorder(BSTNode* root) {
    if(root == NULL) {
        return;
    }

    printInorder(root->left);
    printf("%d ",root->data);
    printInorder(root->right);
    return;
}

BSTNode* createBSTNode(int val) {
    BSTNode* node = (BSTNode*) malloc(sizeof(BSTNode));
    node->left = NULL;
    node->right = NULL;
    node->data = val;
    return node;
}

BSTNode* searchValue(BSTNode* root,int target) {
    if(root == NULL || root->data == target) {
        return root;
    }

    if (root->data > target) {
        return searchValue(root->left,target);
    } else return searchValue(root->right,target);
}

BSTNode* insertNode(BSTNode* root,int val) {
    if(root == NULL) {
        return createBSTNode(val);
    }

    if(root->data > val) {
        root->left = insertNode(root->left,val);
    } else if (root->data < val) {
        root->right = insertNode(root->right,val);
    }

    return root;
}

BSTNode* findMin(BSTNode* root) {
    if(root == NULL) return NULL;

    BSTNode* temp = root;
    while(root->left) {
        temp = temp->left;
    }

    return temp;
}

BSTNode* removeNode(BSTNode* root,int target) {
    if(root == NULL) {
        return NULL;
    }

    if(root->data > target) {
        root->left = removeNode(root->left,target);
    }
    else if (root->data < target) {
        root->right = removeNode(root->right,target);
    }
    else {
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL || root->right == NULL) {
            BSTNode* child = NULL;
            if(root->left) child = root->left;
            else child = root->right;
            free(root);
            return child;
        }
        else {
            BSTNode* inorderSuccessor = findMin(root->right);
            // This will surely exist, as we have already checked right subtree is NULL or not
            root->data = inorderSuccessor->data;
            removeNode(root->right,inorderSuccessor->data);
        }
    }

    return root;
}

int main() {
    // Initialize it Or PROGRAM WON'T RUN
    BSTNode* bst = NULL;

    bst = insertNode(bst,5);
    bst = insertNode(bst,2);
    bst = insertNode(bst,4);
    bst = insertNode(bst,3);
    bst = insertNode(bst,8);
    bst = insertNode(bst,1);

    printf("BEFORE: ");
    printInorder(bst);
    printf("\n");

    printf("AFTER: ");
    removeNode(bst,4);
    printInorder(bst);

    return 0;
}