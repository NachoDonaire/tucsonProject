#include <OutputsHandler.hpp>
#include <Tucson.hpp>
#include <ThreadManager.hpp>

int	main()
{
	std::cout << "BB" << std::endl;
	Tucson		za = Tucson("tucker");
	write(1, "bb", 2);
	ThreadManager	t = ThreadManager(33, za);
	write(1, "bb", 2);
	t.createThreads();
	write(1, "aa", 2);
	return (0);
}
