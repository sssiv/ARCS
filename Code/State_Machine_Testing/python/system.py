from generate import *

import sys
import os
import shutil

class System():
    def __clear_folder(folder):
        for filename in os.listdir(folder):
            file_path = os.path.join(folder, filename)
            try:
                if os.path.isfile(file_path) or os.path.islink(file_path):
                    os.unlink(file_path)
                elif os.path.isdir(file_path):
                    shutil.rmtree(file_path)
            except Exception as e:
                print('Failed to delete %s. Reason: %s' % (file_path, e))
    #Sys#------------------------------------------------------------------------#
    @staticmethod
    def sys_args():
        # Check if exactly two additional arguments are provided
        if len(sys.argv) == 3:
            try:
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

            except ValueError:
                print("Both arguments must be valid integers.")
        else:
            print("Please provide exactly two integer inputs.")
    #Sys#------------------------------------------------------------------------#
    # Removes content from pass
    @staticmethod
    def clear_folders():
        System.__clear_folder("../pass/")
        System.__clear_folder("../fail/")
    #Sys#------------------------------------------------------------------------#