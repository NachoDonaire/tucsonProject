#ifndef OUTPUTSHANDLER_HPP
#define OUTPUTSHANDLER_HPP

#include <tucsonProject.hpp>
/* Handles files class, heritance of Tucson (godLike class) */

class	OutputHandler 
{
	public :
		OutputHandler(std::string file_Name);
		~OutputHandler();
		void	openFile();
		void	closeFile();
		int	fileFinder(std::string coincidence);
	private :
		std::string 	fileName;
		std::ifstream	file;
};

#endif
