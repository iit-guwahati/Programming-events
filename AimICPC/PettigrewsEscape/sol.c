#include <stdio.h>
#include <stdlib.h>

int traverse (int **maze, int n, int cur_i, int cur_j, int paths_discovered)
{
  int i;
  
  if (cur_i == n - 1 && cur_j == n - 1)
  {
    return paths_discovered + 1;
  }

  maze[cur_i][cur_j] = 1;

  for (i = -1; i < 2; i++)
  {
    if (cur_i + i < n  && cur_i + i >= 0 && 0 == maze[cur_i + i][cur_j])
    {
      paths_discovered = traverse (maze, n, cur_i + i, cur_j, paths_discovered);
    }
    if (cur_j + i < n && cur_j + i >= 0 && 0 == maze[cur_i][cur_j + i])
    {
      paths_discovered = traverse (maze, n, cur_i, cur_j + i, paths_discovered);
    }
  }
  maze[cur_i][cur_j] = 0;
  return paths_discovered;
}

int main (void)
{
  int n, i, j;
  int **maze;
  scanf ("%d", &n);  

  maze = malloc (sizeof (int*) * n);
  for (i = 0; i < n; i++)
  {
    maze[i] = malloc (sizeof (int) * n);
    for (j = 0; j < n; j++)
    {
      scanf ("%d", &maze[i][j]);
    }
  }
  
  printf ("%d\n", traverse(maze, n, 0, 0, 0));
  return 0;
}


