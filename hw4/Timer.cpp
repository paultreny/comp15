#include <sys/time.h>		// for getrusage
#include <sys/resource.h>	// for getrusage
#include <iostream>

#include "Timer.h"
namespace comp15 {

// constructor just initializes creation time
Timer::Timer() { 
	this->reset(); 
}

// [re]initialize creation time
void Timer::reset() { 
	creation_time = now(); 
}

// return time since Timer was created (time now minus time then)
double Timer::elapsed() const { 

	return now() - this->creation_time; 

}


/** Compute and return the approximate (user+system) time used by the process */
double Timer::now() { 

	// see man page for getrusage (it populates the rusage and returns 0 on success)
	struct rusage usage; 
	return getrusage(RUSAGE_SELF, &usage) 
		? 0 // getrusage returns 0 on success, I'll return 0 (seconds) on error
		:   usage.ru_utime.tv_sec + usage.ru_utime.tv_usec / 1000000.0
		  + usage.ru_stime.tv_sec + usage.ru_stime.tv_usec / 1000000.0;

}

// print timer (print elapsed time) to output stream
std::ostream& operator<<(std::ostream &out, const Timer &timer) { return out << timer.elapsed(); }

}//namespace
