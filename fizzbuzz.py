#!/usr/bin/env python


def fizzbuzz(x, fizzdict):
  output = ""
  for key in fizzdict.keys():
    if not x % key: # If x is a multiple of the key
      output += fizzdict[key]
  if output != "":
    return output
  return x


def main():
  print "Welcome to fizzbuzz. Leave the input blank if you don't want to replace a particular number."
  print "I haven't checked the input for any Bobby Tables shenanigans, so have fun with that."
  choice = raw_input("Would you like to run the default version of fizzbuzz? (y/n)")

  fizzdict = {}

  if choice == 'y' or choice == 'Y':        # fizz on multiples of 3 and buzz on multiples of 5
    fizzdict = {3:"fizz",5:"buzz"}
  elif choice == 'n' or choice == 'N':      # freestyle fizzbuzz, why not?
    for x in range(1, 11):
      word = raw_input("What should I say for multiples of {0}? ".format(x))
      if word != "":
        fizzdict.update({x:word})
  else:
    print "Please answer either \'y\' or \'n\'"
    exit(1)

  for x in range(1, 101):
    print fizzbuzz(x, fizzdict)


if __name__ == "__main__":
  main()
