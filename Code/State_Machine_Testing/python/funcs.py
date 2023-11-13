import random
from tokens import Tokens

class Functions():
    class Lambdas():
        # Generates a random number between x and y
        rand_num = staticmethod(lambda x, y: random.randint(x, y))
    #Lam#------------------------------------------------------------------------#
        # Makes a random choice from a list
        rand_choice = staticmethod(lambda options: random.choice(options))
        #------------------------------------------------------------------------#
        # Picks a random selection of variables
        rand_samples = staticmethod(lambda list, how_many: random.sample(list, how_many))
    #Lam#------------------------------------------------------------------------#
        # Gets sublist index
        get_list = staticmethod(lambda sublist: Tokens().lists[Tokens().lists.index(sublist)])
    #Lam#------------------------------------------------------------------------#

    class Variable_Handler():
        # Checks variable type and gives it a value
        @staticmethod
        def make_value(type):
            # Bool handler
            if type == 'bool':
                if Functions.Lambdas.rand_num(0, 1):
                    value = True
                else:
                    value = False
                    
            # Int handler
            if type == 'int':
                value = Functions.Lambdas.rand_num(0, 100)

            # String handler
            if type == 'string':
                rand_index = Functions.Lambdas.rand_num(0, len(Tokens().string_input) - 1)
                rand_string = Tokens().string_input[rand_index]
                value = f'"{rand_string}"'

            # Returns variable value
            return value
    #Var#------------------------------------------------------------------------#
        # Makes sure theres no redeclorations
        @staticmethod
        def avoid_redecloration(name, used_names, name_list):
            # Uses current name to check the variables, events, and states list
            while name in used_names:
                # Makes a new choice from the tokens list
                name = Functions.Lambdas().rand_choice(name_list)
            
            # Returns a unique name
            return name
    #Var#------------------------------------------------------------------------#
