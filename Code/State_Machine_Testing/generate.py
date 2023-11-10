from funcs import *

class Generate:
    def __init__(self):
        self.code = ""

        # State variable names and amount
        self.num_of_states = rand_num(0, 50)
        self.states = []
        self.generate_state_names()

        # Maps current variables with their types
        self.num_of_variables = rand_num(0, len(tokens.variable_names))
        self.variables = {}

        # Events are saved with their Variable Type
        self.num_of_events = rand_num(0, 5)
        self.events = {}
        self.generate_event_names()
    #------------------------------------------------------------------------#
    # Variable Handler
    def generate_variables(self, code):
        # Gets variable names list
        var_names = tokens.variable_names

        # Gets variable types list
        var_types = tokens.variables

        # Picks a random name
        var_name = rand_choice(var_names)

        # Makes sure the chosen variable name is not a repeat
        while var_name in self.variables.keys():
            var_name = rand_choice(var_names)

        # Make variables
        for _ in range(self.num_of_variables):
            # Makes sure that randomly choses states are not already used
            var_name = rand_choice(var_names)

            # Makes sure the chosen variable name is not already used
            while var_name in self.variables:
                var_name = rand_choice(var_names)
            
            # Random variable type is chosen
            variable_type = rand_choice(var_types)
            
            # Adds variable name in the used list
            self.variables[var_name] = variable_type

            # Checks variable type and gives it a value
            value = make_value(self.variables[var_name])

            # Variable syntax
            code += f"\t\t{variable_type} {var_name} = {value};\n"
        
        # Return variables
        return code
    #------------------------------------------------------------------------#
    # Generate State names
    def generate_state_names(self):
        # Get statenames list
        statenames = get_list(tokens.state_names)

        # Pick a random statename
        statename = rand_choice(statenames)

        # Makes num_of_states amount of states
        for _ in range(self.num_of_states):
            # Makes sure the chosen state name is not already used
            while statename in self.states:
                statename = rand_choice(statenames)
            
            # Adds used statename to list
            self.states.append(statename)
    #------------------------------------------------------------------------#
    def generate_event_names(self):
        # Get event names list
        event_names = get_list(tokens.event_names)

        # Pick a random event name
        eventname = rand_choice(event_names)

        # Picks random Variables from list
        variables = get_list(tokens.variables)
        variable = rand_choice(variables)

        for _ in range(self.num_of_events):
            # Makes each event have a random type
            variable = rand_choice(variables)

            # Make sure the chosen event name is not already used
            while eventname in self.events:
                # If the name is already used, pick another random name
                eventname = rand_choice(event_names)

            #Adds used event name to list
            self.events[eventname] = variable
    #------------------------------------------------------------------------#
    # Generates random Event(s)
    # Needs a loop to make more than one event if wanted
    def generate_event(self, code):

        # Make a loop for this
        if rand_num(0, 1):
            for key, value in self.events.items():
                code += f"event {key} {{{value}}}; \n"
        # Make sure this is at the end outside the loop
        code += '\n'

        # Return events syntax
        return code
    #------------------------------------------------------------------------#
    # Generate an Actor, which makes a statemachine which makes state(s)
    def generate_actor(self, code):
        # Get actor names list
        actor_names = get_list(tokens.actor_names)

        # Picks random name from list
        actor_name = rand_choice(actor_names)

        # Generate actor definition
        code = f"actor {actor_name} {{\n"

        # Makes statmachine which calls generate_state
        code += self.generate_statemachine("")

        # Close actor definitions
        code += "}\n"

        # Returns actor code
        return code
    #------------------------------------------------------------------------#
    # Makes statemachine
    def generate_statemachine(self, code):
        # Start of statemachine syntax
        code += "\tstatemachine {\n"

        # Picks a state that has been initialized (if states exist)
        # Make sure the list is not empty
        if self.states:
            initial_statename = rand_choice(self.states)
        else:
            initial_statename = None

        # Randomly decides if we include an initial state 
        if rand_num(0, 1) and initial_statename is not None:
            code += f"\t\tinitial {initial_statename};\n\n"

        # Genrate States
        code += self.generate_state("")

        # Close state machine definitions
        code += "\t}\n"

        # Return State machine syntax
        return code
    #------------------------------------------------------------------------#
    # Make Random States
    def generate_state(self, code):
        # Random Names have already been provided
        # This was done so that statemachine can choose a state that exists

        # Make and save variables
        code = self.generate_variables(code)

        # Iterating through how many state names we generated
        for i in range(self.num_of_states):
            # Actual State syntax
            # Randomly deciding if we want to change variable values in each state
            if rand_num(0, 1):
                code += f"\n\t\tstate {self.states[i]} {{\n"

                # Give new values to the variables
                for name in self.variables:
                    value = make_value(self.variables[name])
                    code += f"\t\t\t{name} = {value};\n"
                code += "\t\t}\n"

            # Print blank state
            else:
                code += f"\n\t\tstate {self.states[i]} {{\n"
                code += f"\t\t\t// Add state behavior here;\n"
                code += "\t\t}\n"

        # Returns state code
        return code
    #------------------------------------------------------------------------#
    # Generates random proteus tokens
    def generate_random_text(self, list, length):
        # Initialize for text 
        random_text = ""

        # Line counter
        line_length = 0

        # These rows are for variable names, we want just random tokens
        ignore_rows = -5

        # Random text still has more room
        while len(random_text) < length:
            # Picks randomly when to have a space, tab, or \n
            if line_length >= rand_num(1, 20):
                # Add a space, tab, or line break when the line length exceeds the random limit
                random_text += rand_choice([" ", "\t", "\n"])

                # Resets line counter
                line_length = 0

            # Starts making a new random line of code
            else:
                # Randomly picks tokens, ignores the variable names 
                selected_list = rand_choice(list[:ignore_rows])

                # Randomly picks item from list
                selected_item = str(rand_choice(selected_list))  # Convert to string

                # Puts it in the random text
                random_text += selected_item

                # Updates the line length counter
                line_length += len(selected_item)
                
        # Random code is now generated
        return random_text
    #------------------------------------------------------------------------#
    # Generate random code
    def generate_random_code(self):

        # Events Generated
        self.code = self.generate_event(self.code)

        # Actor Generated
        self.code += self.generate_actor("")

        # Returns random code
        return self.code