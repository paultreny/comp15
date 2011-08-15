//
//  Paul Reny - COMP15 - August 12th, 2011
//  HW4 - Random Airlines
//  
//  Timer.h
//  
//  Created by Keith Noto
//  
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

