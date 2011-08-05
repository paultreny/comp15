// Paul Reny - Lab 11
//
//
//

#include "sort.h"  
#include <limits.h>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <list>
#include <deque>
#include <vector>



namespace comp15 { 
  
  using namespace std;
  
  void sort(integer_t *A, size_t n)
  {
    long count[256];
    long index[256];
    memset (count, 0, sizeof(count));
    
    for (int i=0; i<n; i++)
    {
      count [((A[i])>>(
      
    }
    
    int temp[n];
    int r = 4;
    int b = 64;
    
    int count[1<<r];
    int countsize = (1<<r);
    int pref[1<<r];
    
    int groups = b/r;
    if (b%4 > 0) groups++;
    //(int)Math.Ceiling((double)b/(double)r);
    
    int mask = (1<<r)-1;
    
    for (int c=0, shift=0; c<groups; c++, shift+=r)
    {
      for (int j=0; j<countsize; j++)
      {
        count[j]=0;
      }
      
      
      for (int i=0; i<n; i++)
      {
        count[(A[i]>>shift)&mask]++;
      }
      
      pref[0]=0;
      for (int i=1; i<countsize; i++)
      {
        pref[i]= pref[i-1] + count[i-1];
      }
      
      for (int i=0; i<n; i++)
      {
        temp[pref[(A[i]>>shift)&mask]++]=A[i];
      }
      
      A = temp;
    
      //temp.CopyTo(A,0);
    }
    //A is sorted
    
  }
  
}
// namespace  