import random
from tokens import Tokens

class Utilities():
    class Random():
        # Generates a random number between x and y
        rand_num = staticmethod(lambda x, y: random.randint(x, y))
    #Ran#---------------------------------------------------------------------------------------------------------------------------------------------#
        # Makes a random choice from a list
        rand_choice = staticmethod(lambda options: random.choice(options))
        #---------------------------------------------------------------------------------------------------------------------------------------------#
        # Picks a random selection of variables
        rand_samples = staticmethod(lambda list, sample_size: random.sample(list, sample_size))
    #Ran#---------------------------------------------------------------------------------------------------------------------------------------------#
#---#---#---------------------------------------------------------------------------------------------------------------------------------------------#
#---#---#---------------------------------------------------------------------------------------------------------------------------------------------#
    class Lists():
        # Gets sublist index
        get_list = staticmethod(lambda sublist: Tokens().lists[Tokens().lists.index(sublist)])
    #Lis#---------------------------------------------------------------------------------------------------------------------------------------------#
#---#---#---------------------------------------------------------------------------------------------------------------------------------------------#
#---#---#---------------------------------------------------------------------------------------------------------------------------------------------#
    class Variable_Handler():
        # Checks variable type and gives it a value
        @staticmethod
        def make_value(type):
            # Bool handler
            if type == 'bool':
                return True if Utilities.Random.rand_num(0, 1) else False
                    
            # Int handler
            if type == 'int':
                return Utilities.Random.rand_num(0, 100)

            # String handler
            if type == 'string':
                rand_index = Utilities.Random.rand_num(0, len(Tokens().string_input) - 1)
                return f'"{Tokens().string_input[rand_index]}"'

            # Returns variable value
            return None
    #Var#---------------------------------------------------------------------------------------------------------------------------------------------#
        # Makes sure theres no redeclorations
        @staticmethod
        def avoid_redecloration(name, used_names, name_list):
            # Uses current name to check the variables, events, and states list
            while name in used_names:
                # Makes a new choice from the tokens list
                name = Utilities.Random.rand_choice(name_list)
            
            # Returns a unique name
            return name
    #Var#---------------------------------------------------------------------------------------------------------------------------------------------#