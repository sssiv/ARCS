from generate import *

# Show all tokens
tokens.display_tokens()

# Write tokens to a textfile
tokens.tokens_txt()

# Makes text file and writes random tokens in it
num_of_chars = rand_num(500, 2000)
list_of_tokens = tokens.lists

# Not using an object for Generate() cause 
# I want the generated data to be purposfully lost for new tests
with open('random_tokens.txt', 'w') as file:
        file.write(Generate().generate_random_text(list_of_tokens, num_of_chars))

# Makes text file and writes random formatted code in it
with open('random_code.txt', 'w') as file:
    file.write(Generate().generate_random_code())