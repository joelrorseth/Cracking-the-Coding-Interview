#
# Given a binary tree, design an algorithm which creates a linked list
# of all nodes at each depth.
#
# Joel Rorseth
#

# NOTE: For simplicity, I will make a Python list for each depth level
# instead of making my own linked list. I will also implement a BST,
# which is still a binary tree.

from collections import defaultdict


class Node:
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

    def insert(self,val):
        if self.root:
            self._insert(self.root,val)
        else:
            self.root = Node(val)

    def _insert(self,cur,val):
        if val < cur.val:
            if cur.left:
                self._insert(cur.left,val)
            else:
                cur.left = Node(val)
        else:
            if cur.right:
                self._insert(cur.right,val)
            else:
                cur.right = Node(val)


    # Keep a dict for each level, mapping nodes at depths
    def lists_for_depths(self):
        lists = defaultdict(list)
        self._dfs(self.root,lists,0)
        return lists

    # Recursively traverse tree in DFS, passing correct depth and
    # updated dict mapping depths to list of nodes
    def _dfs(self,cur,lists,depth):

        if cur:
            lists[depth].append(cur.val)
            self._dfs(cur.left,lists,depth+1)
            self._dfs(cur.right,lists,depth+1)


# Demo
bst = BST()
bst.insert(5)
bst.insert(1)
bst.insert(2)
bst.insert(9)
bst.insert(4)
bst.insert(7)
bst.insert(8)
print(bst.lists_for_depths())

