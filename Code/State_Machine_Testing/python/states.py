from tokens import Tokens
from utilities import Utilities

class States():
    def __init__(self):
        self.num_of_states = Utilities.Random.rand_num(0, len(Tokens().state_names))
        self.states = []
        self.variables = {}
        self.__generate_states() 
    #Sta#---------------------------------------------------------------------------------------------------------------------------------------------#
    # Generate State names
    def __generate_states(self):
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
    def get_variables(self, variable_list):
        self.variables = variable_list

# Heres where I start to get worried.
# If I have a new class instence of variables for states,
# It might make new variables all together, so I must make sure to pass them
# however, must think of all and any types it can take in