#!/usr/bin/python
# Author : Rajat Khanduja
# Generate test cases for the problem

import random

t = 1000
print t 
while t > 0:
    t -= 1
    print random.randint(1,500), random.randint(1,500)
