from funcs import Functions, Tokens

class Generate:
    class Pass:
        def __init__(self):
            self.code = ""
            # State variable names and amount
            self.num_of_states = Functions.Lambdas.rand_num(0, 50)
            self.states = []
            self.__generate_state_names()

            # Maps current variables with their types
            self.num_of_variables = Functions.Lambdas.rand_num(0, len(Tokens().variable_names))
            self.variables = {}

            # Events are saved with their Variable Type
            self.num_of_events = Functions.Lambdas.rand_num(0, 5)
            self.events = {}
            self.__generate_event_names()
    #Pas#------------------------------------------------------------------------#
        # Variable Handler
        # NOTE: Need to split this into 2 functions. One for names, one for vars
        def __generate_variables(self, code):
            # Gets variable names list
            var_names = Tokens().variable_names

            # Gets variable types list
            var_types = Tokens().variables

            # Picks a random name
            var_name = Functions.Lambdas.rand_choice(var_names)

            # Make variables
            for _ in range(self.num_of_variables):
                # Makes sure that randomly choses states are not already used
                var_name = Functions.Lambdas.rand_choice(var_names)

                # Makes sure the chosen variable name is not already used
                var_name = Functions.Variable_Handler.avoid_redecloration(var_name, self.variables, var_names)
                
                # Random variable type is chosen
                variable_type = Functions.Lambdas.rand_choice(var_types)
                
                # Adds variable name in the used list
                self.variables[var_name] = variable_type

                # Checks variable type and gives it a value
                value = Functions.Variable_Handler.make_value(self.variables[var_name])

                # Variable syntax
                code += f"\t\t{variable_type} {var_name} = {value};\n"
            
            # Return variables
            return code
    #Pas#------------------------------------------------------------------------#
        # Generate State names
        def __generate_state_names(self):
            # Get statenames list
            state_names = Functions.Lambdas.get_list(Tokens().state_names)

            # Pick a random statename
            state_name = Functions.Lambdas.rand_choice(state_names)

            # Makes num_of_states amount of states
            for _ in range(self.num_of_states):
                # Makes sure the chosen state name is not already used

                state_name = Functions.Variable_Handler.avoid_redecloration(state_name, self.states, state_names)
                
                # Adds used statename to list
                self.states.append(state_name)
    #Pas#------------------------------------------------------------------------#
        def __generate_event_names(self):
            # Get event names list
            event_names = Functions.Lambdas.get_list(Tokens().event_names)

            # Pick a random event name
            event_name = Functions.Lambdas.rand_choice(event_names)

            # Picks random Variables from list
            variables = Functions.Lambdas.get_list(Tokens().variables)
            variable = Functions.Lambdas.rand_choice(variables)

            # Generate and save event names
            for _ in range(self.num_of_events):
                # Makes each event have a random type
                variable = Functions.Lambdas.rand_choice(variables)

                # Make sure the chosen event name is not already used
                event_name = Functions.Variable_Handler.avoid_redecloration(event_name, self.events, event_names)

                #Adds used event name to list
                self.events[event_name] = variable
    #Pas#------------------------------------------------------------------------#
        # Generates random Event(s)
        def __generate_events(self, code):
            # Randomly decides if we have events at all
            if Functions.Lambdas.rand_num(0, 1):
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
            actor_names = Functions.Lambdas.get_list(Tokens().actor_names)

            # Picks random name from list
            actor_name = Functions.Lambdas.rand_choice(actor_names)

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
            # Make sure the list is not empty
            if self.states:
                initial_statename = Functions.Lambdas.rand_choice(self.states)
            else:
                initial_statename = None

            # Randomly decides if we include an initial state 
            if Functions.Lambdas.rand_num(0, 1) and initial_statename is not None:
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
            # Random Names have already been provided
            # This was done so that statemachine can choose a state that exists

            # Make and save variables
            self.code = self.__generate_variables("")

            # Iterating through how many state names we generated
            for i in range(self.num_of_states):
                # Actual State syntax
                # Randomly deciding if we want to change variable values in each state
                if Functions.Lambdas.rand_num(0, 1):
                    self.code += f"\n\t\tstate {self.states[i]} {{\n"

                    # Randomly select variables to modify
                    random_vars = Functions.Lambdas.rand_num(0, len(self.variables))
                    selected_vars = Functions.Lambdas.rand_samples(list(self.variables.keys()), random_vars)
                    
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
    
    class Fail:
        def generate_random_text(self, list, length):
            # Initialize empty string for text 
            random_text = ""

            # Line counter
            line_length = 0

            # These rows are for variable names, we want just random tokens
            # NOTE: would like to find a way to not hardcode this
            ignore_rows = -5

            # Random text still has more room
            while len(random_text) < length:
                # Picks randomly when to have a space, tab, or \n
                if line_length >= Functions.Lambdas.rand_num(1, 20):
                    # Add a space, tab, or line break when the line length exceeds the random limit
                    random_text += Functions.Lambdas.rand_choice([" ", "\t", "\n"])

                    # Resets line counter
                    line_length = 0

                # Starts making a new random line of code
                else:
                    # Randomly picks tokens, ignores the variable names 
                    selected_list = Functions.Lambdas.rand_choice(list[:ignore_rows])

                    # Randomly picks item from list
                    selected_item = str(Functions.Lambdas.rand_choice(selected_list))  # Convert to string

                    # Puts it in the random text
                    random_text += selected_item

                    # Updates the line length counter
                    line_length += len(selected_item)
                    
            # Random code is now generated
            return random_text
    #Fai#------------------------------------------------------------------------#
        