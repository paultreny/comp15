#ifndef TIMER_H
#define TIMER_H

class Timer { 

	public:

		/** Create a timer */
		Timer();

		/** Compute and return (estimated user+system) process time in seconds since timer was created  */
		double elapsed() const; 

	
	private:  
		
		double creation_time; // time when this was created
		static double now(); // get the current time now

};

#endif
