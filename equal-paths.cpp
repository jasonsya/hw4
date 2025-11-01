#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)
#include <iostream>
#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
int checkHeight (Node* node) {
    if (node == nullptr) {
        return 0;
    }

    int leftHeight = checkHeight(node->left);
    if (leftHeight == -1) {
        return -1;
    }

    int rightHeight = checkHeight(node->right);
    if (rightHeight == -1) {
        return -1;
    }

    if (node->left == nullptr && node->right == nullptr) {
        return 1;
    }

    if (node->left == nullptr) {
        return rightHeight + 1;
    }
    if (node->right == nullptr) {
        return leftHeight + 1;
    }

    if (leftHeight != rightHeight) {
        return -1;
    }

    return leftHeight + 1;
}

bool equalPaths(Node * root)
{
    // Add your code below
    return checkHeight(root) != -1;
}

