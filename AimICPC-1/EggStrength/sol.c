#include <stdio.h>
#include <limits.h>

int max (int a, int b)
{
  return a > b ? a : b;
}

#define MAX_FLOORS 10000
#define MAX_EGGS 10000

/* A 2D table where entry eggFloor[i][j] will represent minimum
   number of trials needed for i eggs and j floors. */
int eggFloor[MAX_EGGS][MAX_FLOORS];

/* Function to get minimum number of trails needed in worst
  case with n eggs and k floors */
int eggDrop(int n, int k)
{
    int res;
    int x;

    if (eggFloor[n][k] != -1)
        return eggFloor[n][k];
    
    else
    {
        eggFloor[n][k] = INT_MAX;
        for (x = 1; x <= k; x++)
        {
            res = 1 + max(eggDrop(n -1,x - 1), eggDrop(n, k - x));
            if (res < eggFloor[n][k])
                eggFloor[n][k] = res;
        }
        return eggFloor[n][k];
    }
}
 
/* Driver program to test to pront printDups*/
int main()
{
    int n, t, m;
    scanf ("%d", &t);

    int i, j;
    for (i = 0; i < MAX_EGGS; i++)
        for (j = 0; j < MAX_FLOORS; j++)
            eggFloor[i][j] =  -1;

     // We need one trial for one floor and 0 trials for 0 floors
    for (i = 1; i <= MAX_EGGS; i++)
    {
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
    }

    // We always need j trials for one egg and j floors.
    for (j = 1; j <= MAX_FLOORS; j++)
        eggFloor[1][j] = j;

    while (t--)
    {
        scanf ("%d %d", &n, &m);
        printf ("%d\n", eggDrop(m, n));
    }
    return 0;
}
