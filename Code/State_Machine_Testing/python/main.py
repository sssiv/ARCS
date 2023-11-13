from generate import *

# Show all tokens, make sure we got them correctly
Tokens().display_tokens()

# Write tokens to a textfile (Seperated by a comma)
Tokens().tokens_txt()

# How many chars will be in the random tokens textfile fail case
num_of_chars = Functions.Lambdas.rand_num(500, 2000)

# Get all token lists
token_lists = Tokens().lists

# NOTE: Not using an object for Generate() cause 
# I want the generated data to be purposfully lost for new tests

# Makes text file and writes random tokens to purposfully fail
with open('../random_tokens.txt', 'w') as file:
        file.write(Generate.Fail().generate_random_text(token_lists, num_of_chars))

# Makes text file and writes random formatted code in it
with open('../passing_code.txt', 'w') as file:
    file.write(Generate.Pass().generate_random_code())
