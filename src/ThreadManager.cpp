#include <OutputsHandler.hpp>
#include <ThreadManager.hpp>
#include <unistd.h>

ThreadManager::ThreadManager(int a, Tucson &t) : nThreads(a)
{
	this->threads = (pthread_t *)malloc(sizeof(pthread_t) * (this->nThreads + 1));
	this->tucson = new Tucson[a];
	for (int i = 0; i < a; i++)
		this->tucson[i] = t;
}


ThreadManager::~ThreadManager()
{
	this->joinThreads();
	free(this->threads);
}

void	*ThreadManager::routine(void	*arg)
{
	Tucson	*a;

	a = (Tucson *)arg;

	
	pthread_mutex_lock(a->getMuti());
	std::string essid0 = a->getEssid();
	//std::cout << "EE: " << a->getThreadID() << std::endl;
	std::cout << "hilo " <<  a->getThreadID() << ": " << essid0 << std::endl;
	pthread_mutex_unlock(a->getMuti());
	return NULL;
}

void	ThreadManager::createThreads()
{
	int	i;

	i = 0;
	std::cout << "ALO?" << this->nThreads <<  std::endl;

	while (i < this->nThreads)
	{
		this->tucson[i].setThreadID(i);
		if (0 != pthread_create(&this->threads[i], NULL, &ThreadManager::routine, &this->tucson[i]))
			return ;
		i++;
	}
}

void	ThreadManager::joinThreads()
{
	int	i;

	i = 0;
	while (i < this->nThreads)
	{
		pthread_join(this->threads[i], NULL);
		i++;
	}
}


