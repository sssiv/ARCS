from utilities import Utilities
from tokens import Tokens

class Variables():
    def __init__(self):
        # Variable named mapped with types
        self.num_of_variables = Utilities.Random.rand_num(0, len(Tokens().variable_names))
        self.variables = {}

        # Variable names and types generated when instence 
        self.__generate_variables()
    #Var#---------------------------------------------------------------------------------------------------------------------------------------------#
    # Makes variable names mapped with a random type
    def __generate_variables(self):
        # Make variables
        for _ in range(self.num_of_variables):
            # Get a random name
            var_name = Utilities.Random.rand_choice(Tokens().variable_names)

            # Makes sure the chosen variable name is not already used
            var_name = Utilities.Variable_Handler.avoid_redecloration(var_name, self.variables, Tokens().variable_names)
            
            # Random variable type is chosen and adds variable name in the used list
            self.variables[var_name] = Utilities.Random.rand_choice(Tokens().variables)
        # Create Variables with values and names
    #Var#---------------------------------------------------------------------------------------------------------------------------------------------#
    def generate_variables(self):
        # Empty string to write variables
        code = ""

        # itr's with key = name, value = type
        for key, value in self.variables.items():
            # Checks variable type and gives it a value
            var_value = Utilities.Variable_Handler.make_value(value)

            # Variable syntax
            code += f"\t\t{value} {key} = {var_value};\n"
        
        # Return variables
        return code
    #Var#---------------------------------------------------------------------------------------------------------------------------------------------#
    def get_variables(self):
        return self.variables
    #Var#---------------------------------------------------------------------------------------------------------------------------------------------#