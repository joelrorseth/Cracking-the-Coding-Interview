#
# Given a sorted array of unique numbers (increasing), create a
# BST with minimal height.
#
# Joel Rorseth
#

class Node:
    def __init__(self,val):
        self.left = None
        self.right = None
        self.val = val


class BST:
    def __init__(self):
        self.root = None


    def create_minimal(self,vals):
        self.root = self.__create_minimal(vals,0,len(vals)-1)

    # Use indicies into array to progressively insert the middle element
    # Left / right branches will recurse using left and right slices
    def __create_minimal(self,vals,i,j):
        if j < i:
            return None

        mid_idx = int((i + j)/2)
        mid = Node(vals[mid_idx])
        mid.left = self.__create_minimal(vals,i,mid_idx-1)
        mid.right = self.__create_minimal(vals,mid_idx+1,j)

        return mid


    def preorder(self):
        self.__preorder(self.root)

    def __preorder(self,root):
        if root:
            print(root.val)
            self.__preorder(root.left)
            self.__preorder(root.right)


# Demo
bst = BST()
bst.create_minimal([1,3,4,6,8,9,10,13,15,16])
bst.preorder()
