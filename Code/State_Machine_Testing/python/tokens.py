import pandas as pd

# Read the CSV file
df = pd.read_csv('../tokens.csv')

# Define functions to handle stripping single quotes
def strip_single_quotes(entry):
    return str(entry).strip("'") if isinstance(entry, str) else str(entry)

# Create arrays from columns, remove single quotes, and drop null values
types = [strip_single_quotes(entry) for entry in df['Types'].dropna().tolist()]                            # Standard types
numbers = [int(entry) for entry in df['Numbers'].dropna().tolist()]                                 # Integers, NOTE: was int(float(entry)). Shouldn't make a different, but just in case
brackets = [strip_single_quotes(entry) for entry in df['Brackets'].dropna().tolist()]               # Proteus braces
keywords = [strip_single_quotes(entry) for entry in df['Keywords'].dropna().tolist()]               # All Keywords
variables = [strip_single_quotes(entry) for entry in df['Variables'].dropna().tolist()]             # Variable Keywords (except variable_name at the end)
operators = [strip_single_quotes(entry) for entry in df['Operators'].dropna().tolist()]             # All operators
punctuation = [strip_single_quotes(entry) for entry in df['Punctuation'].dropna().tolist()]         # Any type of punctuation Proteus will allow
actor_names = [strip_single_quotes(entry) for entry in df['Actor_Names'].dropna().tolist()]         # Demo names for actors 
state_names = [strip_single_quotes(entry) for entry in df['State_Names'].dropna().tolist()]         # Demo names for states
variable_names = [strip_single_quotes(entry) for entry in df['Variable_Names'].dropna().tolist()]   # Demo names for variables
event_names = [strip_single_quotes(entry) for entry in df['Event_Names'].dropna().tolist()]         # Demo names for events
string_input = [strip_single_quotes(entry) for entry in df['String_Input'].dropna().tolist()]       # Random inputs for strings

# List of all proteus lists
lists = [
    types, numbers, brackets, keywords, 
    variables, operators, punctuation, actor_names, 
    state_names, variable_names, event_names, string_input
    ]

# String list of all the columns
names = [
    'Types', 'Numbers', 'Brackets', 'Keywords', 
    'Variables', 'Operators', 'Punctuation', 'Actor_Names', 
    'State_Names', 'Variable_Names', 'Event_Names', 'String_Input'
    ]

# Confirm everything has been collected
def display_tokens():
    print("-" * 100)
    # For every name in list
    for name, list in zip(names, lists):
        # Convert numbers to strings for printing
        print(f"{name}: {' '.join(map(str, list))}\n")  
    print("-" * 100, "\n")

# Writes all tokens to a txt file
def tokens_txt():
    with open('../tokens.txt', 'w') as file:
        for token_list in lists:
            # Join the elements of each list into a string with spaces as separators
            formatted_tokens = ' '.join(map(str, token_list))
            # Write the name of the list followed by a colon and the formatted string, then a newline
            file.write(f"{formatted_tokens}\n")