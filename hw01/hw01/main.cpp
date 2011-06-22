// PAUL RENY - COMP 15 - 06/21/2011
// HW1
// main.cpp
//

/* Compute and print Fibonacci numbers */
#include "Jumbo.h"
#include <iostream>

using namespace std;

int main() {
  Jumbo a(1); // 1st                                                                                                                                         
  Jumbo b(1); // 2nd                                                                                                                                        
  int count = 0; // keep track of N for Nth Fib Sequence
  while (true) {
    
    // a holds the value of the Nth Fib. number, if we start counting from                                                                                  
    // Fib. numbers 0 and 1 are 0 and 1.                                                                                                                    
    if (count %100 == 0)  cout << "N=" << count << " Fib=" << a.str() << endl;
    // Only output if N is a multiple of 100 ^
    Jumbo c = a.add(b); // c = a + b                                                                                                                        
    count++;
    a = b; // copy                                                                                                                                          
    b = c; // copy                                                                                                                                          
  }
  return 0;
  
}
