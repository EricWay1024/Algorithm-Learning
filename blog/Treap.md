# Treap

## Definitions

A binary search tree (BST) is a binary tree where for each node:

- Every node in the left subtree has a key value less than it, and
- Every node in the right subtree has a key value greater than it.

This is called the BST property.

A BST could potentially be quite unbalanced, or even degenerate. Rotation, an operation which maintains the BST property of the tree, can help keep the tree balanced. To put it simply, to rotate is to turn a certain node into its current father's father. How? Suppose we want to rotate node `x`, which is the left child of its current father `fa`. In line with the BST property, the key value of `x` should be less than that of `fa`. As a result, `fa` should end up as `x`'s new right child. Then what about `x`'s current right child `y`? Apparently, `fa`'s left child is now vacant and is exactly where we place `y`.  Notice that because `y` is originally inside `fa`'s left subtree `x`, the BST property is not violated. After rotation the depths of node `x`  and its left subtree is decreased, while sacrificing `fa`, `fa`'s right child and `y`. Such a trade-off would be worthwhile if the size of `x`'s left subtree is relatively large. The case where `x` is a right child of `fa` goes in a similar way.

How do we decided when to rotate the tree, and which node to rotate? In the case of Treap, the answer is by random. Yep, if we rotate the tree randomly, 

