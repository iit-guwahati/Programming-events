/* Problem is equivalent to finding the online median of the numbers. 
 * Since the problem even requires removal of numbers from the list, the program here
 * makes use of maps, i.e., rb-Trees. Two Trees are maintained. The Left Tree holds the 
 * elements that are lesser than the effective mean, while the right Tree holds the 
 * elements that are greater than the effective mean. While inserting, care is taken that the 
 * the size of the two Trees doesn't vary by more than one, in which case an element is shifted
 * from the Tree that is larger among the two (when moving from the left Tree, move the greatest
 * element; when moving from the right Tree move the least element). Similar care has to be taken
 * while deleting the elements
 */

#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

typedef multiset<long long int> Tree;

double insertElement (Tree& leftTree, Tree& rightTree, const long long int& insertedElement); // Returns the median after removing
double removeElement (Tree& leftTree, Tree& rightTree, const long long int& removedElement ); // Returns the median after removing (-1 in case the element doesn't exist)

int main (void)
{
  Tree leftTree, rightTree;

  char c;
  long long int x;
  double median;
  
  median = -1;
  while (1)
  {
    scanf ("%lld", &x);
//    fprintf (stderr, "x = %lld\n", x);
    if (x == 0)
    {
      if (leftTree.size() == rightTree.size())
        printf ("-1\n");
      else
        printf ("%.0lf\n", median);
    }
    else if (x == -2)
    {
      break;
    }
    else
      median = insertElement (leftTree, rightTree, x);
  }
  return 0;
}

void balance (Tree& leftTree, Tree& rightTree)
{
  int sizeLeft  = leftTree.size();
  int sizeRight = rightTree.size();
  if ( sizeLeft - sizeRight > 1)
  {
//    cerr << "In here\n"; 
    rightTree.insert (*--leftTree.end());
    leftTree.erase (--leftTree.end());
  }
  else if ( sizeRight > sizeLeft)
  {
//    cerr << "No, In here\n"; 
    leftTree.insert (*rightTree.begin());
    rightTree.erase (rightTree.begin());
  } 
  
//  cerr << "Finally size of the left tree : " << leftTree.size() << " , size of right tree : " << rightTree.size() << endl;
}

double getMedian (Tree& leftTree, Tree& rightTree)
{
  // Return the median
  if (leftTree.size() == rightTree.size())
  {
    if (leftTree.size() == 0)
      return -1;
    else
      return (*--leftTree.end() + *rightTree.begin()) / 2.0;
  }
  else
  {
    return leftTree.size() > rightTree.size() ? *--leftTree.end() : *rightTree.begin();
  }
}
double insertElement (Tree& leftTree, Tree& rightTree, const long long int& insertedElement)
{
  if (leftTree.size() == 0 || insertedElement <= *(--leftTree.end()))
  {
    leftTree.insert (insertedElement);
  }
  else
  {
    rightTree.insert (insertedElement);
  }
  
//  fprintf (stderr, "Inserted element\n");

  // Balance
  balance (leftTree, rightTree); 
//  fprintf (stderr, "Balanced\n");
  return getMedian (leftTree, rightTree); 
}

double removeElement (Tree& leftTree, Tree& rightTree, const long long int& removedElement)
{
  // First find the iterator to the element.
  Tree::iterator itr;

  if ((itr = leftTree.find(removedElement)) != leftTree.end())
  {
    // Element found in left tree
    leftTree.erase (itr);
  }
  else if ( (itr = rightTree.find (removedElement)) != rightTree.end())
  {
    rightTree.erase (itr);
  }
  else
  {
    return -1;
  }

  // Balance
  balance (leftTree, rightTree);
  
  return getMedian (leftTree, rightTree);
}
