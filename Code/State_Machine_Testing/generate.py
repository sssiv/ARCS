import random
import tokens

# Make random "code"
def generate_random_text(list, length=random.randint(100, 1000)):
    random_text = ""
    line_length = 0

    # Random text still has more room
    while len(random_text) < length:
        # Picks randomly when to have a space, tab, or \n
        if line_length >= random.randint(1, 20):
            # Add a space, tab, or line break when the line length exceeds the random limit
            random_text += random.choice([" ", "\t", "\n"])

            # Resets line counter
            line_length = 0

        # Starts making a new random line of code
        else:
            # Randomly picks list
            selected_list = random.choice(list)

            # Randomly picks item from list
            selected_item = str(random.choice(selected_list))  # Convert to string

            # Puts it in the random text
            random_text += selected_item

            # Updates the line length counter
            line_length += len(selected_item)
    # Random code is now generated
    return random_text

def generate_actor():
    i = i

def generate_statemachine():
    i = i

def generate_state():
    i = i


tokens.token_list()
print(generate_random_text(tokens.lists))