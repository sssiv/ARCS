from funcs import Functions
from tokens import Tokens

class Generate:
    class Pass:
        def __init__(self):
            self.code = ""
            # States
            self.num_of_states = Functions.Random.rand_num(0, len(Tokens().state_names))
            self.states = []
            self.__generate_state_names()

            # Variables
            self.num_of_variables = Functions.Random.rand_num(0, len(Tokens().variable_names))
            self.variables = {}
            self.__generate_variable_names()

            # Events
            self.num_of_events = Functions.Random.rand_num(0, len(Tokens().event_names))
            self.events = {}
            self.__generate_event_names()
    #Pas#------------------------------------------------------------------------#
        # Generate State names
        def __generate_state_names(self):
            # Get statenames list
            state_names = Functions.Lists.get_list(Tokens().state_names)

            # First item on list. If it's empty, the loop below wont work
            state_name = Functions.Random.rand_choice(state_names)

            # Puts random states into states list
            for _ in range(self.num_of_states):
                # Makes sure the chosen state name is not already used
                state_name = Functions.Variable_Handler.avoid_redecloration(state_name, self.states, state_names)
                
                # Adds used statename to list
                self.states.append(state_name)
    #Pas#------------------------------------------------------------------------#
        # Makes variable names mapped with a random type
        def __generate_variable_names(self):
            # Gets variable names list
            var_names = Tokens().variable_names

            # Gets variable types list
            var_types = Tokens().variables

            # Make variables
            for _ in range(self.num_of_variables):
                # Get a random name
                var_name = Functions.Random.rand_choice(var_names)

                # Makes sure the chosen variable name is not already used
                var_name = Functions.Variable_Handler.avoid_redecloration(var_name, self.variables, var_names)
                
                # Random variable type is chosen and adds variable name in the used list
                self.variables[var_name] = Functions.Random.rand_choice(var_types)
    #Pas#------------------------------------------------------------------------#
        def __generate_event_names(self):
            # Get event names list
            event_names = Functions.Lists.get_list(Tokens().event_names)

            # Pick a random event name
            event_name = Functions.Random.rand_choice(event_names)

            # Picks random Variables from list
            variables = Functions.Lists.get_list(Tokens().variables)
            variable = Functions.Random.rand_choice(variables)

            # Generate and save event names
            for _ in range(self.num_of_events):
                # Makes each event have a random type
                variable = Functions.Random.rand_choice(variables)

                # Make sure the chosen event name is not already used
                event_name = Functions.Variable_Handler.avoid_redecloration(event_name, self.events, event_names)

                #Adds used event name to list
                self.events[event_name] = variable
        # Create Variables with values and names
        def __generate_variables(self, code):
            # itr's with key = name, value = type
            for key, value in self.variables.items():
                # Checks variable type and gives it a value
                var_value = Functions.Variable_Handler.make_value(value)

                # Variable syntax
                code += f"\t\t{value} {key} = {var_value};\n"
            
            # Return variables
            return code
    #Pas#------------------------------------------------------------------------#
        # Generates random Event(s)
        def __generate_events(self, code):
            # Randomly decides if we have events at all
            if Functions.Random.rand_num(0, 1):
                # Generates event initialization syntax
                for key, value in self.events.items():
                    code += f"event {key} {{{value}}}; \n"
            code += '\n'

            # Return events syntax
            return code
    #Pas#------------------------------------------------------------------------#
        # Generate an Actor, which makes a statemachine which makes state(s)
        def __generate_actor(self):
            # Get actor names list
            actor_names = Functions.Lists.get_list(Tokens().actor_names)

            # Picks random name from list
            actor_name = Functions.Random.rand_choice(actor_names)

            # Generate actor definition
            self.code = f"actor {actor_name} {{\n"

            # Makes statmachine which calls generate_state
            self.code += self.__generate_statemachine("")

            # Close actor definitions
            self.code += "}\n"

            # Returns actor code
            return self.code
    #Pas#------------------------------------------------------------------------#
        # Makes statemachine
        def __generate_statemachine(self, code):
            # Start of statemachine syntax
            code += "\tstatemachine {\n"

            # Picks a state that has been initialized (if states exist)
            # Makes sure the list is not empty
            initial_statename = Functions.Random.rand_choice(self.states) if self.states else None

            # Randomly decides if we include an initial state 
            if Functions.Random.rand_num(0, 1) and initial_statename is not None:
                code += f"\t\tinitial {initial_statename};\n\n"

            # Genrate States
            code += self.__generate_states()

            # Close state machine definitions
            code += "\t}\n"

            # Return State machine syntax
            return code
    #Pas#------------------------------------------------------------------------#
        # Make Random States
        def __generate_states(self):
            # Make and save variables
            self.code = self.__generate_variables("")

            # Iterating through how many state names we generated
            for i in range(self.num_of_states):
                # Randomly deciding if we want to change variable values in each state
                if Functions.Random.rand_num(0, 1):
                    self.code += f"\n\t\tstate {self.states[i]} {{\n"

                    # Randomly select variables to modify
                    random_vars = Functions.Random.rand_num(0, len(self.variables))
                    selected_vars = Functions.Random.rand_samples(list(self.variables.keys()), random_vars)
                    
                    # Give new values to the variables
                    for name in selected_vars:
                        value = Functions.Variable_Handler.make_value(self.variables[name])
                        self.code += f"\t\t\t{name} = {value};\n"
                    self.code += "\t\t}\n"

                # Print blank state
                else:
                    self.code += f"\n\t\tstate {self.states[i]} {{\n"
                    self.code += f"\t\t\t// Add state behavior here;\n"
                    self.code += "\t\t}\n"

            # Returns state code
            return self.code
    #Pas#------------------------------------------------------------------------#
        # Generate random code
        def generate_random_code(self):

            # Events Generated
            self.code = self.__generate_events(self.code)

            # Actor Generated
            self.code += self.__generate_actor()

            # Returns random code
            return self.code
    #Pas#------------------------------------------------------------------------#
#---#---#------------------------------------------------------------------------#
#---#---#------------------------------------------------------------------------#    
    class Fail:
        def generate_random_tokens(self, length):
            # Initialize empty string for text 
            random_tokens = ""

            # Line counter
            line_length = 0

            # These rows are for variable names, we want just random tokens
            ignore = 0
            for column in reversed(Tokens().lists):
                if column == Tokens().punctuation:
                    break
                ignore -= 1

            # Random text still has more room
            while len(random_tokens) < length:
                # Picks randomly when to have a space, tab, or \n
                if line_length >= Functions.Random.rand_num(1, 20):
                    # Add a space, tab, or line break when the line length exceeds the random limit
                    random_tokens += Functions.Random.rand_choice([" ", "\t", "\n"])

                    # Resets line counter
                    line_length = 0

                # Starts making a new random line of code
                else:
                    # Randomly picks tokens, ignores the variable names 
                    selected_list = Functions.Random.rand_choice(Tokens().lists[:ignore])

                    # Randomly picks item from list
                    selected_item = str(Functions.Random.rand_choice(selected_list))  # Convert to string

                    # Puts it in the random text
                    random_tokens += selected_item

                    # Adds how many characters were added to line length coutner
                    line_length += len(selected_item)
                    
            # Returns random tokens
            return random_tokens
    #Fai#------------------------------------------------------------------------#

    #Fai#------------------------------------------------------------------------#