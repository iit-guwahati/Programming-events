#!/usr/bin/python
from random import shuffle
import random
import sys

def visitedNeighbours(x,y, w, h, vis):
  
  if x + 1 < w and not vis[x + 1][y]:
    return False
  if x - 1 >= 0 and not vis[x - 1][y]:
    return False
  if y + 1 < h and not vis[x][y + 1]:
    return False
  if y - 1 >= 0 and not vis[x][y - 1]:
    return False

  return True

def fitVals (maze, vis, x, y, w, h, depth):
  maze[x][y] = 0
  vis[x][y] = True

  neighbours = []
  if x + 2 < w:
    neighbours.append((x + 2, y))
  if x - 2 >= 0:
    neighbours.append((x - 2, y))
  if y + 2 < w:
    neighbours.append((x, y + 2))
  if y - 2 >= 0:
    neighbours.append((x, y - 2))
  
  shuffle(neighbours)
  for (xx,yy) in neighbours:
    if vis[xx][yy]:
      randNum = random.randint(1,10)
      if randNum <= 9 or depth >= 100:
        continue
      else:
        if visitedNeighbours(xx, yy, w, h, vis):
          continue
    if yy == y - 2:
      maze[xx][y - 1] = 0
    elif yy == y + 2:
      maze[xx][y + 1] = 0
    elif xx == x + 2:
      maze[x + 1][yy] = 0
    else:
      maze[x - 1][yy] = 0
    
    fitVals(maze, vis, xx, yy, w, h, depth + 1)
  
  return maze


def mazeGen(w,h):
  maze = [[1 for i in range(w)] for j in range(h)]
  vis  = [[False for i in range(w)] for j in range(h)]
  
  maze = fitVals(maze, vis, 0, 0, w, h, 1)

  return maze

dim = int(sys.argv[1])
if dim % 2 == 0:
   dim += 1

maze = mazeGen(dim, dim)
for i in range(dim):
  print maze[i]
