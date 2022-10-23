import random

size = 100

lowercase_letters = [
    "a",
    "b",
    "c",
    "d",
    "e",
    "f",
    "g",
    "h",
    "i",
    "j",
    "k",
    "l",
    "m",
    "n",
    "o",
    "p",
    "q",
    "r",
    "s",
    "t",
    "u",
    "v",
    "w",
    "x",
    "y",
    "z",
]

infix_expression = ""
for i in range(size):
    infix_expression += "("
    infix_expression += random.choice(lowercase_letters)
    infix_expression += random.choice(["+", "*", ">"])
infix_expression += random.choice(lowercase_letters)
for i in range(size):
    infix_expression += ")"

print(infix)
