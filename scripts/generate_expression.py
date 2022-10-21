import random

def expressionGenerator(n):
  vars = [x for x in 'abcdefghijklmnopqrstuvwxyz']

  choice = random.random()
  if (choice < (0.05 + n)):
    return random.choice(vars)
  elif (choice < 0.25):
    return "(~" + expressionGenerator(n+0.05) + ")"
  elif (choice < 0.55):
    return "(" + expressionGenerator(n+0.05) + "+" + expressionGenerator(n+0.05) + ")"
  elif (choice < 0.75):
    return "(" + expressionGenerator(n+0.05) + "*" + expressionGenerator(n+0.05) + ")"
  else:
    return "(" + expressionGenerator(n+0.05) + ">" + expressionGenerator(n+0.05) + ")"

print(expressionGenerator(0))

