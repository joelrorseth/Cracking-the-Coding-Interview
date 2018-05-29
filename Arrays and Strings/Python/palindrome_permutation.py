#
# Discern whether a string is a permutation of a palindrome. This means that
# the string could be arranged to be the same forwards / backwards eg. 'racecar'
#
# Joel Rorseth
#

# Q: Case sensitive? Whitespace sensitive?
# Complexity: O(n)


def is_pal_perm(s):

    lookup = [0]*128
    n_odds = 0

    # Count the chars, either 0 or 1 characters are allowed odd count
    for c in s:

        lookup[ord(c)] += 1

        if lookup[ord(c)] % 2 == 0:
            n_odds -= 1
        else:
            n_odds += 1

    return n_odds == 1 or n_odds == 0



print("raccear")
print(is_pal_perm("raccear"))
print("\nRacecar")
print(is_pal_perm("Racecar"))
