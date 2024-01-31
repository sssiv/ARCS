import random

class Utilities():
    # Generates a random number between x and y
    rand_num = staticmethod(lambda x, y: random.randint(x, y))

    # Makes a random choice from a list
    rand_choice = staticmethod(lambda options: random.choice(options))

    # Picks a random selection of variables
    rand_samples = staticmethod(lambda list, sample_size: random.sample(list, sample_size))