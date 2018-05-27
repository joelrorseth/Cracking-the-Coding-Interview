#
# Are two strings permutations of eachother?
# Joel Rorseth
#

# Q: Case sensitive? YES
# Q: Is whitespace significant? YES
# Solution: Compare length, then make set of chars in a, compare with b
# Complexity: O(n)


def is_permutation(a, b):

    # Nice, but does extra work (checks whole string) if non-permutation
    #return False if (len(a) != len(b)) else set(a)==set(b)

    if (len(a) != len(b)):
        return False

    # Make counter for all ASCII characters, count chars in 'a'
    a_chars = [0] * 128
    for c in a:
        a_chars[ord(c)] += 1

    # Negative counts will immediately be false
    for c in b:
        a_chars[ord(c)] -= 1

        if a_chars[ord(c)] < 0:
            return False

    return True


print("dog, cat")
print(is_permutation("dog", "cat"))

print("\nabcd, bdca")
print(is_permutation("abcd", "bdca"))
