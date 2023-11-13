from system import System
from generate import *

# Clears folders to make new tests each time you run the code
System.clear_folders()

# Show all tokens, make sure we got them correctly
Tokens().display_tokens()

# Write tokens to a textfile (Seperated by a comma)
Tokens().write_tokens_txt()

# Looks for arguments when compiling with the command python(3) main.py (arg1) (arg2)
System.sys_args()