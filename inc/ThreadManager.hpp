#ifndef THREADMANAGER_HPP 
#define THREADMANAGER_HPP 

#include <tucsonProject.hpp>
#include <pthread.h>
#include <Tucson.hpp>

/* Handles threads, heritance of Tucson (godLike class) */

class	ThreadManager
{
	public :
		ThreadManager(int n, Tucson &t);
		~ThreadManager();
		static void*	routine(void *arg);
		void	createThreads();
		void	joinThreads();
	private :
		pthread_t	 *threads;
		int	nThreads;
		Tucson	*tucson;
};

#endif
