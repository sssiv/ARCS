from functools import cache

from utilities import Utilities
from tokens import Tokens

from variables import Variables
from events import Events

# Used to make passing and failing proteus code
class Generate:
    class Pass:
        def __init__(self):
            self.code = ""
            # States list
            self.num_of_states = Utilities.Random.rand_num(0, len(Tokens().state_names))
            self.states = []
            self.__generate_state_names()

            # Variables
            self.variables = Variables() 

            # Event names mapped with types
            self.events = Events()
    #Pas#---------------------------------------------------------------------------------------------------------------------------------------------#
        # Generate State names
        def __generate_state_names(self):
            # Get statenames list
            state_names = Utilities.Lists.get_list(Tokens().state_names)

            # First item on list. If it's empty, the loop below wont work
            state_name = Utilities.Random.rand_choice(state_names)

            # Puts random states into states list
            for _ in range(self.num_of_states):
                # Makes sure the chosen state name is not already used
                state_name = Utilities.Variable_Handler.avoid_redecloration(state_name, self.states, state_names)
                
                # Adds used statename to list
                self.states.append(state_name)
    #Pas#---------------------------------------------------------------------------------------------------------------------------------------------#
        # Generate an Actor, which makes a statemachine which makes state(s)
        def __generate_actor(self):
            # Get actor names list
            actor_names = Utilities.Lists.get_list(Tokens().actor_names)

            # Picks random name from list
            actor_name = Utilities.Random.rand_choice(actor_names)

            # Generate actor definition
            self.code = f"actor {actor_name} {{\n"

            # Makes statmachine which calls generate_state
            self.code += self.__generate_statemachine()

            # Close actor definitions
            self.code += "}\n"

            # Returns actor code
            return self.code
    #Pas#---------------------------------------------------------------------------------------------------------------------------------------------#
        # Makes statemachine
        def __generate_statemachine(self):

            # Start of statemachine syntax
            code = "\tstatemachine {\n"

            # Picks a state that has been initialized (if states exist)
            # Makes sure the list is not empty
            initial_statename = Utilities.Random.rand_choice(self.states) if self.states else None

            # Randomly decides if we include an initial state 
            if Utilities.Random.rand_choice([True, False]) and initial_statename is not None:
                code += f"\t\tinitial {initial_statename};\n\n"

            # Genrate States
            code += self.__generate_states()

            # Close state machine definitions
            code += "\t}\n"

            # Return State machine syntax
            return code
    #Pas#---------------------------------------------------------------------------------------------------------------------------------------------#
        # Make Random States
        def __generate_states(self):
            # Make and save variables
            self.code = self.variables.generate_variables()

            # Iterating through how many state names we generated
            for i in range(self.num_of_states):
                # state syntax
                self.code += f"\n\t\tstate {self.states[i]} {{\n"

                # Randomly deciding if we want to change variable values in each state
                if Utilities.Random.rand_choice([True, False]):
                    # Randomly select variables to modify
                    num_of_vars = Utilities.Random.rand_num(0, len(self.variables.get_variables()))
                    var_keys = list(self.variables.get_variables().keys())
                    selected_vars = Utilities.Random.rand_samples(var_keys, num_of_vars)
                    
                    # Give new values to the variables
                    for name in selected_vars:
                        value = Utilities.Variable_Handler.make_value(self.variables.get_variables()[name])
                        self.code += f"\t\t\t{name} = {value};\n"
                    self.code += "\t\t}\n"

                # Print blank state
                else:
                    self.code += f"\t\t\t// Add state behavior here;\n"
                    self.code += "\t\t}\n"

            # Returns state code
            return self.code
    #Pas#---------------------------------------------------------------------------------------------------------------------------------------------#
        # Generate random code
        def generate_random_code(self):
            # Events Generated
            self.code += self.events.generate_events()

            # Actor Generated
            self.code += self.__generate_actor()

            # Returns random code
            return self.code
    #Pas#---------------------------------------------------------------------------------------------------------------------------------------------#
#---#---#---------------------------------------------------------------------------------------------------------------------------------------------#
#---#---#---------------------------------------------------------------------------------------------------------------------------------------------#   
    @cache
    class Fail:
        def generate_random_tokens(self, length):
            # Initialize empty string for text 
            random_tokens = ""

            # Line counter
            line_length = 0

            # These rows are for variable names, we want just random tokens
            ignore = Tokens().lists.index(Tokens().punctuation)

            # Random text still has more room
            while len(random_tokens) < length:
                # Picks randomly when to have a space, tab, or \n
                if line_length >= Utilities.Random.rand_num(1, 20):
                    # Add a space, tab, or line break when the line length exceeds the random limit
                    random_tokens += Utilities.Random.rand_choice([" ", "\t", "\n"])

                    # Resets line counter
                    line_length = 0

                # Starts making a new line of random tokens
                else:
                    # Randomly picks tokens, ignores the variable names 
                    selected_list = Utilities.Random.rand_choice(Tokens().lists[:ignore])

                    # Randomly picks item from list, Convert to string
                    selected_item = str(Utilities.Random.rand_choice(selected_list))   

                    # Puts it in the random text
                    random_tokens += selected_item

                    # Adds how many characters were added to line length coutner
                    line_length += len(selected_item)
                    
            # Returns random tokens
            return random_tokens
    #Fai#---------------------------------------------------------------------------------------------------------------------------------------------#

