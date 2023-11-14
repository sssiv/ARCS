from generate import Generate
from functions import Functions

import sys
import os
import shutil

class System():
    # Delete all content from inputted folder
    @staticmethod
    def __clear_folder(folder):
        # Iterate through each file in the directory listed in 'folder'
        for filename in os.listdir(folder):
            # Create the full path of the file by joining the folder path and the filename
            file_path = os.path.join(folder, filename)

            # Attempt block for the inputted filepath
            try:
                # If the file_path is a file or a symbolic link, then delete it
                if os.path.isfile(file_path) or os.path.islink(file_path):
                    # os.unlink() deletes a file or symbolic link
                    os.unlink(file_path)  

                # If the file_path is a directory, then delete the directory and all its contents
                elif os.path.isdir(file_path):
                    # deletes a directory and all its contents
                    shutil.rmtree(file_path)  

            # If an exception occurs during the deletion process, catch it
            except Exception as e:
                # Print an error message showing the file path and the exception reason
                print('Failed to delete %s. Reason: %s' % (file_path, e))
    #Sys#------------------------------------------------------------------------#
    # Input after the command to compile
    @staticmethod
    def sys_args():
        # Check if exactly two additional arguments are provided
        if len(sys.argv) == 3:
            # Attempt block for arguments
            try:
                # ensure arg's are int using int()
                num_of_pass_cases = int(sys.argv[1])
                num_of_fail_cases = int(sys.argv[2])

                # Makes text file and writes random formatted code in it
                for i in range(num_of_pass_cases):
                    with open(f'../pass/code_{i + 1}.txt', 'w') as file:
                        file.write(Generate.Pass().generate_random_code())
                
                # Once I can make code that fails, I need it to randomly pick full code or just random tokens
                for i in range(num_of_fail_cases):
                    # How many characters will be in the random tokens textfile fail case
                    num_of_chars = Functions.Random.rand_num(500, 2000)

                    # Makes text file and writes random tokens to purposfully fail
                    with open(f'../fail/code_{i + 1}.txt', 'w') as file:
                        file.write(Generate.Fail().generate_random_tokens(num_of_chars))
            
            # If arguments arent of type int
            except ValueError:
                print("Both arguments must be valid integers.")

        # Not enough arguments entered
        else:
            print("Please provide exactly two integer inputs.")
    #Sys#------------------------------------------------------------------------#
    # Removes content from all folders
    @staticmethod
    def clear_folders():
        System.__clear_folder("../pass/")
        System.__clear_folder("../fail/")
    #Sys#------------------------------------------------------------------------#