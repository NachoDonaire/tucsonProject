#include <Tucson.hpp>

Tucson::Tucson(std::string wifi) : essid(wifi), threadID(0)
{
	this->muti = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(this->muti, NULL);
}

Tucson::Tucson()
{
	this->essid = "";
	threadID = 0;
	this->muti = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(this->muti, NULL);
}
Tucson::~Tucson()
{
	pthread_mutex_destroy(this->muti);
}

void	Tucson::setThreadID(int n)
{
	this->threadID = n;
}

Tucson::Tucson(const Tucson &t) : essid(t.essid)
{
	this->threadID = t.threadID;
	std::cout << "const copy : " << this->essid << "---" << this->threadID << std::endl;
}

int	Tucson::getThreadID()
{
	return this->threadID;
}

std::string Tucson::getEssid()
{
	return this->essid;
}

void	Tucson::setMuti(pthread_mutex_t *mutas)
{
	this->muti = mutas;
}

pthread_mutex_t	*Tucson::getMuti()
{
	return this->muti;

}

Tucson& Tucson::operator=(const Tucson &other) {
    if (this != &other) {  
        this->essid = other.essid;
        this->threadID = other.threadID;
    }
    return *this;
}

