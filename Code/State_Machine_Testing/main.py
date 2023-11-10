from generate import *

# Show all tokens
tokens.display_tokens()

# Write tokens to a textfile
tokens.tokens_txt()

# Object for making syntax
Generate = Generate()

# Makes text file and writes random tokens in it
num_of_chars = rand_num(500, 2000)
list_of_tokens = tokens.lists

with open('random_tokens.txt', 'w') as file:
        file.write(Generate.generate_random_text(list_of_tokens, num_of_chars))

# Makes text file and writes random formatted code in it
with open('random_code.txt', 'w') as file:
    file.write(Generate.generate_random_code())