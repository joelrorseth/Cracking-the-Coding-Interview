#
# Determine if a binary tree is balanced. A binary tree is balanced iff
# the heights of its left and right subtrees at any given node never differ
# by more than 1.
#
# Joel Rorseth
#

ERR = -999999

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


    def is_balanced(self):
        return self._is_balanced(self.root) != ERR

    def _is_balanced(self,cur):

        # Base case: negate the +1 being added to this return val
        if not cur:
            return -1

        l=self._is_balanced(cur.left)
        if l == ERR:
            return ERR

        r=self._is_balanced(cur.right)

        # Start returning ERR if no longer balanced at this node
        # Otherwise return height of this node (longest path to leaf)
        if abs(l-r) > 1:
            return ERR
        else:
            return max(l,r) + 1


# Demo
bst = BST()
bst.insert(5)
bst.insert(1)
bst.insert(2)
bst.insert(9)
bst.insert(7)
print(bst.is_balanced()) # True

bst.insert(4)
bst.insert(8)
print(bst.is_balanced()) # False
