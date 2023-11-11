import random
import tokens

# Generates a random number between x and y
rand_num = lambda x, y: random.randint(x, y)
#------------------------------------------------------------------------#
# Makes a random choice from a list
rand_choice = lambda options: random.choice(options)
#------------------------------------------------------------------------#
# Picks a random selection of variables
rand_samples = lambda list, how_many: random.sample(list, how_many)
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
    # Bool handler
    if type == 'bool':
        if rand_num(0, 1):
            value = True
        else:
            value = False
            
    # Int handler
    if type == 'int':
        value = rand_num(0, 100)

    # String handler
    if type == 'string':
        rand_index = rand_num(0, len(tokens.string_input) - 1)
        rand_string = tokens.string_input[rand_index]
        value = f'"{rand_string}"'

    # Returns variable value
    return value
#------------------------------------------------------------------------#