#!/usr/bin/env python3


# Import the Python documentation Fibonacci module
import pydoc_fibonacci as fibonacci


# Import the Python documentation Spam module
import spam


# Test Fibonacci sequence to 100
fibonacci.fib(100)


# Test Fibonacci sequence (list return) to 100
print(fibonacci.fib2(100))


# Hello spam module
print(spam.system('echo hello spam!'))


# Test the Spam module by executing "ls -l"
print(spam.system('ls -l'))
