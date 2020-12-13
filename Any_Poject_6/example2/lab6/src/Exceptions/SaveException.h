#ifndef SAVEEXCEPTION_H
#define SAVEEXCEPTION_H

class SaveException
{
public:
	const char* what() const throw()
	{
		return "An exception occurred while saving.\n";
	}
};

#endif