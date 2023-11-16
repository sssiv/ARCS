from utilities import Utilities
from tokens import Tokens

class Events():
    def __init__(self):
        # Event names mapped with types
        self.num_of_events = Utilities.Random.rand_num(0, len(Tokens().event_names))
        self.events = {}
        self.__generate_events()
    #Eve#---------------------------------------------------------------------------------------------------------------------------------------------#       
    def __generate_events(self):
        # Get event names list
        event_names = Utilities.Lists.get_list(Tokens().event_names)

        # Pick a random event name
        event_name = Utilities.Random.rand_choice(event_names)

        # Picks random Variables from list
        variables = Utilities.Lists.get_list(Tokens().variables)
        variable = Utilities.Random.rand_choice(variables)

        # Generate and save event names
        for _ in range(self.num_of_events):
            # Makes each event have a random type (if it has one)
            variable = Utilities.Random.rand_choice(variables) if Utilities.Random.rand_num(0, 1) else  ""

            # Make sure the chosen event name is not already used
            event_name = Utilities.Variable_Handler.avoid_redecloration(event_name, self.events, event_names)

            #Adds used event name to list
            self.events[event_name] = variable    
    #Eve#---------------------------------------------------------------------------------------------------------------------------------------------#
    # Generates random Event(s)
    def generate_events(self):
        # String to write events in
        code = ""

        # Randomly decides if we have events at all
        if Utilities.Random.rand_num(0, 1):
            # Generates event initialization syntax
            for key, value in self.events.items():
                code += f"event {key} {{{value}}}; \n"
        code += '\n'

        # Return events syntax
        return code
    #Eve#---------------------------------------------------------------------------------------------------------------------------------------------#
    # Get events
    def get_events(self):
        return self.events
    #Eve#---------------------------------------------------------------------------------------------------------------------------------------------#