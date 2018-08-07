#
# Q 8.7 Permutations Without Duplicates
# Generate all unique permutations of a sequence
#
# Joel Rorseth
#


def perms(seq, path):

    if not seq:
        print(path)
        return

    for i in range(len(seq)):
        before = seq[:i]
        after = seq[(i+1):]
        perms(before + after, seq[i] + "," + path)


# Driver
s = ["a", "b", "c"]
print(s)
perms(s, "")
