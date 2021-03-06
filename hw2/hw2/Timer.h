//  Paul Reny - COMP 15 - 07/07/11
//  HW2
//  Timer.h
//
//  Copyright 2011 Keith Noto. All rights reserved.
//

#ifndef TIMER_H
#define TIMER_H

#include <iostream> // for operator<< Timer

namespace comp15 { 
  
  class Timer { 
    
	public:
    
		/** Create a timer */
		Timer();
    
		/** Compute and return (estimated user+system) process time in seconds since timer was created (or most resent reset) */
		double elapsed() const; 
		
		/** reset timer so it measures time from this call instead of time from creation */
		void reset();
    
    
	private:  
		
		double creation_time; // time when this was created
		static double now(); // get the current time now
    
  };
  
  std::ostream& operator<<(std::ostream&,const Timer&); 
  
  
}//namespace
#endif

