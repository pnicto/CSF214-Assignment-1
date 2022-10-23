import string
import os
import random

operators = ["+", "*", ">"]

size = 25000

dir = os.path.dirname(os.path.realpath(_file_))

with open(dir + "samples/infixTestCase.txt", "w") as fh:
    infix = ""
    for i in range(size):
        infix += "("
        infix += random.choice(string.ascii_lowercase)
        infix += random.choice(operators)
    infix += random.choice(string.ascii_lowercase)
    for i in range(size):
        infix += ")"
    fh.write(infix[1:-1])