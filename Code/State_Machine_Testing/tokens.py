import pandas as pd

# Read the CSV file
df = pd.read_csv('tokens.csv')

# Define functions to handle stripping single quotes
def strip_single_quotes(entry):
    return str(entry).strip("'") if isinstance(entry, str) else str(entry)

# Create arrays from columns, remove single quotes, and drop null values
types = [strip_single_quotes(entry) for entry in df['Types'].dropna().tolist()]                   # Standard types
numbers = [int(float(entry)) for entry in df['Numbers'].dropna().tolist()]                        # Integers
brackets = [strip_single_quotes(entry) for entry in df['Brackets'].dropna().tolist()]             # Proteus braces
keywords = [strip_single_quotes(entry) for entry in df['Keywords'].dropna().tolist()]             # All Keywords
variables = [strip_single_quotes(entry) for entry in df['Variables'].dropna().tolist()]           # Variable Keywords (except variable_name at the end)
operators = [strip_single_quotes(entry) for entry in df['Operators'].dropna().tolist()]           # All operators
punctuation = [strip_single_quotes(entry) for entry in df['Punctuation'].dropna().tolist()]       # Any type of punctuation Proteus will allow
actor_names = [strip_single_quotes(entry) for entry in df['Actor_Names'].dropna().tolist()] 
state_names = [strip_single_quotes(entry) for entry in df['State_Names'].dropna().tolist()] 

# List of all proteus lists
lists = [types, numbers, brackets, keywords, variables, operators, punctuation, actor_names, state_names]
names = ['Types', 'Numbers', 'Brackets', 'Keywords', 'Variables', 'Operators', 'Punctuation', 'Actor_Names', 'State_Names']

# Confirm everything has been collected
def token_list():
    print("-" * 100)
    for name, lst in zip(names, lists):
        print(f"{name}: {' '.join(map(str, lst))}")  # Convert numbers to strings for printing
    print("-" * 100, "\n")