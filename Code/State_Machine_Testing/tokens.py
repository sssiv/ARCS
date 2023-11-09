import pandas as pd

# Read the CSV file
df = pd.read_csv('tokens.csv')

# Define functions to handle stripping single quotes
def strip_single_quotes(name):
    return str(name).strip("'") if isinstance(name, str) else str(name)

# Create arrays from columns, remove single quotes, and drop null values
types = [strip_single_quotes(name) for name in df['Types'].dropna().tolist()]                   # Standard types
numbers = [int(float(name)) for name in df['Numbers'].dropna().tolist()]                        # Integers
brackets = [strip_single_quotes(name) for name in df['Brackets'].dropna().tolist()]             # Proteus braces
keywords = [strip_single_quotes(name) for name in df['Keywords'].dropna().tolist()]             # All Keywords
variables = [strip_single_quotes(name) for name in df['Variables'].dropna().tolist()]           # Variable Keywords (except variable_name at the end)
operators = [strip_single_quotes(name) for name in df['Operators'].dropna().tolist()]           # All operators
punctuation = [strip_single_quotes(name) for name in df['Punctuation'].dropna().tolist()]       # Any type of punctuation Proteus will allow

# List of all proteus lists
lists = [types, numbers, brackets, keywords, variables, operators, punctuation]
names = ['Types', 'Numbers', 'Brackets', 'Keywords', 'Variables', 'Operators', 'Punctuation']

# Confirm everything has been collected
def token_list():
    print("-" * 100)
    for name, lst in zip(names, lists):
        print(f"{name}: {' '.join(map(str, lst))}")  # Convert numbers to strings for printing
    print("-" * 100, "\n")
