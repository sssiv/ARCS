from funcs import *

class Generate:
    def __init__(self):
        self.code = ""

        # State names
        self.used_state_names = []
        self.num_of_states = rand_num(0, 50)
        self.generate_state_names()

        # Maps current variables with their types
        self.used_variable_names = {}

        # Event names
        self.num_of_events = rand_num(0, 5)

        # Events are saved with their Variable Type
        self.used_event_names = {}
        self.generate_event_names()
    #------------------------------------------------------------------------#
    # Variables
    def generate_variables(self, code):
        var_names = tokens.variable_names
        var_types = tokens.variables
        # Makes sure that randomly choses states are not already used
        var_name = rand_choice(var_names)

        # Makes sure the chosen variable name is used once
        while var_name in self.used_state_names:
            var_name = rand_choice(var_names)

        # Adds variable name in the used list
        self.used_state_names.append(var_name)

        # How many random variables will made
        num_variables = rand_num(0, len(var_names))

        # Make variables
        for _ in range(num_variables):
            # Makes sure that randomly choses states are not already used
            var_name = rand_choice(var_names)

            # Makes sure the chosen variable name is used once
            while var_name in self.used_variable_names:
                var_name = rand_choice(var_names)
            
            # Random variable type is chosen
            variable_type = rand_choice(var_types)
            
            # Adds variable name in the used list
            self.used_variable_names[var_name] = variable_type

            # Checks variable type and gives it a value
            value = make_value(self.used_variable_names[var_name])
            
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
            # Makes sure the chosen state name is used once
            while statename in self.used_state_names:
                statename = rand_choice(statenames)
            
            # Adds used statename to list
            self.used_state_names.append(statename)
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

            # Make sure the chosen event name is used once
            while eventname in self.used_event_names:
                eventname = rand_choice(event_names)
            #Adds used event name to list
            self.used_event_names[eventname] = variable

    #------------------------------------------------------------------------#
    # Generates random Event(s)
    # Needs a loop to make more than one event if wanted
    def generate_event(self, code):

        # Make a loop for this
        if rand_num(0, 1):
            for key, value in self.used_event_names.items():
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
        if self.used_state_names:
            initial_statename = rand_choice(self.used_state_names)
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
                code += f"\n\t\tstate {self.used_state_names[i]} {{\n"
                for name in self.used_variable_names:
                    value = make_value(self.used_variable_names[name])
                    code += f"\t\t\t{name} = {value};\n"
                code += "\t\t}\n"

            # Print blank state
            else:
                code += f"\n\t\tstate {self.used_state_names[i]} {{\n"
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

        # Events
        self.code = self.generate_event(self.code)

        # Actor
        self.code += self.generate_actor("")

        # Returns random code
        return self.code