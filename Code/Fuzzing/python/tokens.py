import pandas as pd

# Collection of all proteus tokens and demo input names for testing
class Tokens():
    def __init__(self):
        # Read the CSV file
        self.df = pd.read_csv('../tokens.csv')

        # Handle stripping single quote. Some text required an input of ' at the start
        self.strip_single_quotes = lambda entry: str(entry).strip("'") if isinstance(entry, str) else str(entry)

        # Takes df column, drops null values, converts to list
        self.df_column = lambda column: self.df[column].dropna().tolist()

        # combine all functions and get column data
        self.column = lambda func_1, func_2, column: [func_1(entry) for entry in func_2(column)]

        # Create a list for each column
        self.types = self.column(self.strip_single_quotes, self.df_column, 'Types')                      # Standard types
        self.numbers = self.column(int, self.df_column, 'Numbers')                                       # Integers, NOTE: was int(float(entry)). Shouldn't make a different, but just in case
        self.brackets = self.column(self.strip_single_quotes, self.df_column, 'Brackets')                # Proteus braces
        self.keywords = self.column(self.strip_single_quotes, self.df_column, 'Keywords')                # All Keywords
        self.variables = self.column(self.strip_single_quotes, self.df_column, 'Variables')              # Variable Keywords (except variable_name at the end)
        self.operators = self.column(self.strip_single_quotes, self.df_column, 'Operators')              # All operators
        self.punctuation =self. column(self.strip_single_quotes, self.df_column, 'Punctuation')          # Any type of punctuation Proteus will allow

        # List of column lists
        self.lists = [
            self.types, 
            self.numbers, 
            self.brackets, 
            self.keywords, 
            self.variables, 
            self.operators, 
            self.punctuation, 
            ]
        
        # List of column names
        # column_name in df.columns is basically the same thing I think
        self.column_names = [
            'Types', 
            'Numbers', 
            'Brackets', 
            'Keywords', 
            'Variables', 
            'Operators', 
            'Punctuation'
            ]

    # Outputs all tokens to terminal
    def display_tokens(self):
        print("-" * 150)
        # For every column name in lists
        for column_name, list in zip(self.df.columns, self.lists):
            # Join the elements of each list into a string with comma as separators
            tokens = ', '.join(map(str, list))
            # print the tokens with token name
            print(f"{column_name}: {tokens}\n")  
        print("-" * 150, "\n")

    # Makes and writes tokens to a txt file
    def write_tokens_txt(self):
        with open('../c++/tokens.txt', 'w') as file:
            # For every column name in lists
            for list in self.lists:
                # Join the elements of each list into a string with comma as separators
                tokens = ', '.join(map(str, list))
                # Write the tokens to the c++ folder (without column names)
                file.write(f"{tokens}\n")

# Make textfile of tokens to c++ folder and Display tokens
if __name__ == "__main__":
    Tokens().display_tokens()
    Tokens().write_tokens_txt()