#
# Does a string have all unique characters?
# Bonus: Do it without additional data structures
#
# Joel Rorseth
#

# Q: Is the input an ASCII or Unicode string?
# Solution: Use bool list, one index for each ASCII val possible
# Compleixty: O(n) or O(1)

def is_unique_chars(string):

    chars = [False] * 128

    for c in string:
        if chars[ ord(c) ]==True:
            return False

        chars[ ord(c) ] = True

    return True



print("Hello")
print(is_unique_chars("Hello"))
print("\nAlice")
print(is_unique_chars("Alice"))
