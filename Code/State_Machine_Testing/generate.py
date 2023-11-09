from funcs import *

# Generates random proteus tokens
def generate_random_text(list, length):
    # Initialize for text 
    random_text = ""

    # Line counter
    line_length = 0

    # These rows are for variable names, we want just random tokens
    ignore_rows = -4

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

# Makes statemachine
# initial needs fixing, I need it to somehow know which state will be made/used
def generate_statemachine(code):
    # List for used names to avoid redefining
    used_names = []

    # Start of statemachine syntax
    code += "    statemachine {\n"

    # Pick random statename to have as initial
    statename = get_list(tokens.state_names)
    initial_statename = rand_choice(statename)

    # Gets variable names list
    var_names = get_list(tokens.variable_names)
    
    # Randomly decides if we include an initial state 
    if rand_num(0, 1):
        code += f"        initial {initial_statename};\n\n"

    # How many random variables will made
    num_variables = rand_num(0, len(tokens.variable_names))
    for _ in range(num_variables):
        # Makes sure that randomly choses states are not already used
        var_name = rand_choice(var_names)

        # Makes sure the chosen variable name is used once
        while var_name in used_names:
            var_name = rand_choice(var_names)

        # Adds variable name in the used list
        used_names.append(var_name)

        # Random variable type is chosen
        variable_type = rand_choice(tokens.variables)

        # Checks variable type and gives it a value
        value = make_value(variable_type)
        
        # Variable syntax
        code += f"        {variable_type} {var_name} = {value};\n"
    
    # Genrate States
    code += generate_state("")

    # Return State machine syntax
    return code

# Random states generated in statemachine
def generate_state(code):
    # Picks random statename
    statenames = get_list(tokens.state_names)
    statename = rand_choice(statenames)

    # List for used names to avoid redefining
    used_names = []

    # Generates 0 - 50 states
    for _ in range(rand_num(0, 50)):

        # Makes sure the chosen state name is used once
        while statename in used_names:
            statename = rand_choice(statenames)
        
        # Adds used statename to list
        used_names.append(statename)

        # Actual State syntax
        code += f"\n        state {statename} {{\n"
        code += "            // Add state behavior here\n"
        code += "        }\n"
    
    # Returns state code
    return code

# Generate an Actor, which makes a statemachine which makes state(s)
def generate_actor(code):
    # Get actor names list
    actor_names = get_list(tokens.actor_names)

    # Picks random name from list
    actor_name = rand_choice(actor_names)

    # Generate actor definition
    code = f"actor {actor_name} {{\n"

    # Makes statmachine which calls generate_state
    code += generate_statemachine("")

    # Returns actor code
    return code

# Generates random Event(s)
def generate_event(code):
    # Checks for used event names to avoid redefinitions
    used = []

    # Picks random Variables
    variables = get_list(tokens.variables)
    variable = rand_choice(variables)

    # Picks random event name
    event_names = get_list(tokens.event_names)
    event_name = rand_choice(event_names)
    
    # Make a loop for this
    code += f"event {event_name}{{{variable}}}; \n"
    code += '\n'
    return code

# Generate random code
def generate_random_code():

    code = ""

    # Generate events
    code = generate_event(code)

    code += generate_actor("")

    # Close state machine definitions
    code += "    }\n"

    # Close actordefinitions
    code += "}\n"

    # Returns random code
    return code

# Show all tokens
tokens.display_tokens()

# Makes text file and writes random tokens in it
with open('random_tokens.txt', 'w') as file:
        file.write(generate_random_text(tokens.lists, rand_num(1000, 2000)))

# Makes text file and writes random formatted code in it
with open('random_code.txt', 'w') as file:
        file.write(generate_random_code())