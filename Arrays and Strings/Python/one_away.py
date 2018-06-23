#
# Given two strings A and B, determine if A and B are one or zero
# edits away. Edits are defined as a single insertion, removal  or
# replacement of a character.
#
# Joel Rorseth
#

# Complexity: O(n)


def one_away(a, b):

    if abs(len(a) - len(b)) > 1:
        return False

    same_length = len(a) == len(b)
    longer = a if len(a) > len(b) else b
    shorter = a if len(a) <= len(b) else b

    flag = False
    ptr_l = 0
    ptr_s = 0

    while ptr_l < len(longer) and ptr_s < len(shorter):

        if longer[ptr_l] != shorter[ptr_s]:
            if flag:
                return False

            flag = True

            if same_length:
                ptr_s += 1

        else:
            ptr_s += 1

        ptr_l += 1

    return True



print("pale, ple => %s" % one_away("pale", "ple")) # True
print("pale, bale => %s" % one_away("pale", "bale")) # True
print("pales, pale => %s" % one_away("pales", "pale")) # True
print("pale, bae => %s" % one_away("pale", "bae")) # False
