#
# Replace all spaces in a string with %20. Do it in place.
# Joel Rorseth
#

# Assume: Sufficient spaces are allocated after 'length'
def replace_spaces(s, length):

    spaces = 0

    # Count legit spaces
    for i in range(length):
        if s[i] == ' ':
            spaces += 1

    # Use 'new_length' to track current write pointer
    new_length = length + (2* spaces)
    s[new_length] = '\0'

    # Read backwards from the end of string content
    # Any legit space write %20 backwards using write pointer
    for i in range(length - 1, -1, -1):

        if s[i] == ' ':
            s[new_length - 1] = '0'
            s[new_length - 2] = '2'
            s[new_length - 3] = '%'
            new_length -= 3

        else:
            s[new_length - 1] = s[i]
            new_length -= 1

    return s



print("Mr John Smith")
print(''.join(replace_spaces(list("Mr John Smith     "), 13)))

