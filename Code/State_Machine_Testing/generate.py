import random
import tokens

# Generates a random number from x to y
def rand_num(x, y):
    return random.randint(x, y)

# Makes a random choice from a list
def rand_choise(i):
    return random.choice(i)

# Generates random proteus tokens
def generate_random_text(list, length):
    random_text = ""
    line_length = 0

    # Random text still has more room
    while len(random_text) < length:
        # Picks randomly when to have a space, tab, or \n
        if line_length >= rand_num(1, 20):
            # Add a space, tab, or line break when the line length exceeds the random limit
            random_text += rand_choise([" ", "\t", "\n"])

            # Resets line counter
            line_length = 0

        # Starts making a new random line of code
        else:
            # Randomly picks list, ignores the variable names 
            selected_list = rand_choise(list[:-2])

            # Randomly picks item from list
            selected_item = str(rand_choise(selected_list))  # Convert to string

            # Puts it in the random text
            random_text += selected_item

            # Updates the line length counter
            line_length += len(selected_item)
    # Random code is now generated
    return random_text

def generate_statemachine(code):
    # Generate state machine
    code += "    statemachine {\n"

    # Pick random statename
    state_name_index = tokens.lists.index(tokens.state_names)
    statenames = tokens.lists[state_name_index]
    statename = rand_choise(statenames)

    # Randomly decides if we include an initial state 
    if rand_num(0, 1):
        code += f"        initial {statename};\n\n"

    # Generate random variables
    num_variables = random.randint(0, len(tokens.types))
    for i in range(num_variables):
        variable_type = random.choice(tokens.types)
        variable_name = f"var_{i}"
        code += f"        {variable_type} {variable_name};\n"
    code += generate_state("")
    return code

def generate_state(code):
    for i in range(rand_num(1, 10)):
        code += f"\n        state State_{i} {{\n"
        code += "            // Add state behavior here\n"
        code += "        }\n"
    return code

def generate_actor(code):
    actor_name = rand_choise(tokens.lists[tokens.lists.index(tokens.actor_names)])
    # Generate actor definition
    code = f"actor {actor_name} {{\n"
    code += generate_statemachine("")
    return code
# Generate random code
def generate_random_code():
    # Select a random actor name
    code = generate_actor("")
    # Close state machine and actor definitions
    code += "    }\n"
    code += "}\n"

    return code

# Show all tokens
tokens.token_list()
# Random token combo
print(generate_random_text(tokens.lists, rand_num(1000, 2000)), '\n')

# Generate and print random code
random_code = generate_random_code()
print(random_code, '\n')