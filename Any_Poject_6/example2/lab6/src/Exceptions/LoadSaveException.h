#ifndef LOADSAVEEXCEPTION_H
#define LOADSAVEEXCEPTION_H

class LoadSaveException
{
public:
	const char* what() const throw()
	{
		return "An exception occurred while loading the save. File is corrupted.";
	}
};

#endif
