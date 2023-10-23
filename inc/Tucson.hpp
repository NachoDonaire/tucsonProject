#ifndef TUCSON_HPP
#define TUCSON_HPP

#include <tucsonProject.hpp>

class Tucson
{
 	public:
    		Tucson(std::string wifi);
    		Tucson();
    		~Tucson();
		Tucson(const Tucson &t);
		void		setThreadID(int n);
		int		getThreadID();
		std::string	getEssid();
		void		setMuti(pthread_mutex_t *mutas);
		pthread_mutex_t		*getMuti();
		Tucson& operator=(const Tucson &other);

		//void	generatePsswd();
	private:
		std::string	essid;
		int	    	threadID;
		pthread_mutex_t	*muti;
};

#endif
