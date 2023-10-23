#include <OutputsHandler.hpp>

OutputHandler::OutputHandler(std::string file_name) : fileName(file_name)
{
	this->openFile();
}


OutputHandler::~OutputHandler()
{
	if (file.is_open())
		this->closeFile();
}

void	OutputHandler::openFile()
{
	file = std::ifstream(fileName);
	if (file.is_open())
		std::cout << "File " << fileName << " opened properly" << std::endl;
	else
		std::cout << "File " << fileName << " could not open properly" << std::endl;
}

void	OutputHandler::closeFile()
{
	file.close();
	if (file.is_open())
		std::cout << "Beware of opened files: " << fileName << std::endl;
	else
		std::cout << "File " << fileName << " closed properly" << std::endl;
}

int	OutputHandler::fileFinder(std::string coincidence)
{
	std::string 	line;
	size_t		pos;

	while (std::getline(file, line))
	{
		pos = line.find(coincidence);
		if (pos != std::string::npos)
			return pos;
	}
	return (-1);
}
