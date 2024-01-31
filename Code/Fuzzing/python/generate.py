from functools import cache
from utilities import Utilities
from tokens import Tokens

@cache
class Fuzzer:
    def generate_random_tokens(self, length):
        # Initialize empty string for text 
        random_tokens = ""

        # Line counter
        line_length = 0

        # These rows are for variable names, we want just random tokens
        ignore = Tokens().lists.index(Tokens().punctuation)

        # Random text still has more room
        while len(random_tokens) < length:
            # Picks randomly when to have a space, tab, or \n
            if line_length >= Utilities.Random.rand_num(1, 20):
                # Add a space, tab, or line break when the line length exceeds the random limit
                random_tokens += Utilities.Random.rand_choice([" ", "\t", "\n"])

                # Resets line counter
                line_length = 0

            # Starts making a new line of random tokens
            else:
                # Randomly picks tokens, ignores the variable names 
                selected_list = Utilities.Random.rand_choice(Tokens().lists[:ignore])

                # Randomly picks item from list, Convert to string
                selected_item = str(Utilities.Random.rand_choice(selected_list))   

                # Puts it in the random text
                random_tokens += selected_item

                # Adds how many characters were added to line length coutner
                line_length += len(selected_item)
                
        # Returns random tokens
        return random_tokens
#Fai#---------------------------------------------------------------------------------------------------------------------------------------------#

