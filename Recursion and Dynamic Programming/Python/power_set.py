#
# Generate the power set of a set (all subsets)
# Q 8.4
#

# Basic recursive method
# For each element, either include or exclude, recurse
def subsets(A, n, path):

    if n < 0:
        print(path)
        return

    subsets(A, n-1, path)
    subsets(A, n-1, [A[n]] + path)


a = ["a", "b", "c"]
subsets(a, len(a)-1, [])
