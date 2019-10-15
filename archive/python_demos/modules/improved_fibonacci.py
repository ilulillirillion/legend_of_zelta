#!/usr/bin/env python3
# Fibonacci numbers module

def fib(n):    # write Fibonacci series up to n
    a, b = 0, 1
    while a < n:
        print(a, end=' ')
        a, b = b, a+b
    print()

def fib2(n):   # return Fibonacci series up to n
    result = []
    a, b = 0, 1
    while a < n:
        result.append(a)
        a, b = b, a+b
    return result


# If executed directly, take an argument from CLI and pass it to fib
if __name__ == '__main__':
  import sys
  fib(int(sys.argv[1]))
