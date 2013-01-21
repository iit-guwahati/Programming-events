#!/usr/bin/python
# Author : Rajat Khanduja
# Program to generate test cases and their outputs.

import random
import sys

t = int(sys.argv[3])
inputFile = open(sys.argv[1], 'w')
outputFile = open(sys.argv[2], 'w')
sortedList = []
listN = []
while t > 1:
  randomNum = random.randint(1,1000000000)
  if random.randint(1,10) > 8:
    randomNum = 0
  inputFile.write(str(randomNum) + "\n")
  if randomNum == 0:
    if len(sortedList) % 2:
      outputFile.write(str(sortedList[len(sortedList) / 2]) + "\n")
      print sortedList
    else:
      outputFile.write("-1\n")
  else:
    sortedList.append(randomNum)

  sortedList.sort()
  t -= 1

inputFile.write("-2\n")
