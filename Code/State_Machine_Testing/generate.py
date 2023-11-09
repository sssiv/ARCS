import random
import tokens

# Generates a random number from x to y
def rand_num(x, y):
    return random.randint(x, y)

# Makes a random choice from a list
def rand_choice(i):
    return random.choice(i)

# Gets sublist index
def get_list(sublist):

    # Find index of list
    index = tokens.lists.index(sublist)

    # Gets list from index
    list = tokens.lists[index]

    # Returns found list
    return list

# Generates random proteus tokens
def generate_random_text(list, length):
    random_text = ""
    line_length = 0

    # These rows are for variable names, we want just random tokens
    ignore_rows = -3

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
def generate_statemachine(code):
    # List for used names to avoid redefining
    used_names = []
    code += "    statemachine {\n"

    # Pick random statename to have as initial
    statename = get_list(tokens.state_names)
    initial_statename = rand_choice(statename)

    # Gets variable names list
    var_names = get_list(tokens.variable_names)
    
    # Randomly decides if we include an initial state 
    if rand_num(0, 1):
        code += f"        initial {initial_statename};\n\n"

    # Generate random variables
    num_variables = rand_num(0, len(tokens.variable_names))
    for _ in range(num_variables):
        # Makes sure that randomly choses states are not already used
        var_name = rand_choice(var_names)
        while var_name in used_names:
            var_name = rand_choice(var_names)

        # Adds variable name in the used list
        used_names.append(var_name)

        # Random variable type is chosen
        variable_type = rand_choice(tokens.variables)

        # Variable syntax
        code += f"        {variable_type} {var_name} = some value;\n"
    
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

        # Makes sure that randomly choses states are not already used
        while statename in used_names:
            statename = rand_choice(statenames)
        
        # Adds used statename to list
        used_names.append(statename)

        # Actual State syntax
        code += f"\n        state {statename} {{\n"
        code += "            // Add state behavior here\n"
        code += "        }\n"
    return code

def generate_actor(code):
    # Get actor names list
    actor_names = get_list(tokens.actor_names)

    # Picks random name from list
    actor_name = rand_choice(actor_names)

    # Generate actor definition
    code = f"actor {actor_name} {{\n"

    # Makes statmachine which calls generate_state
    code += generate_statemachine("")
    return code

# Generate random code
def generate_random_code():

    # Make actor, which calls statemachine which calls state
    code = generate_actor("")

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