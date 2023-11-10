import random
import tokens

# Generates a random number between x and y
def rand_num(x, y):
    return random.randint(x, y)
#------------------------------------------------------------------------#
# Makes a random choice from a list
def rand_choice(options):
    return random.choice(options)
#------------------------------------------------------------------------#
# Gets sublist index
def get_list(sublist):

    # Find index of list
    index = tokens.lists.index(sublist)

    # Gets list from index
    list = tokens.lists[index]

    # Returns found list
    return list
#------------------------------------------------------------------------#
# Checks variable type and gives it a value
def make_value(type):
    # Bool check
    if type == 'bool':
        if rand_num(0, 1):
            value = True
        else:
            value = False
#------------------------------------------------------------------------#
    # Int check
    if type == 'int':
        value = rand_num(0, 100)

    # String check
    if type == 'string':
        value = '"enter a string"'

    # Returns value
    return value
#------------------------------------------------------------------------#