#ifndef LogFile_h
#define LogFile_h
#include <iostream>
#include <fstream>

#define LOG_FILE_NAME "/Users/ramka178rus/Desktop/Any_Poject_XC/lab_oop/lab_oop/log.txt"

class Loger { // выводит логи
    static unsigned int m_LogCount; // сколько всего логегов создавали

    std::ofstream* m_File;

public:
    Loger();
    ~Loger();

    std::ostream& Stream(); // возвращает поток вывода логов
};

#endif /* LogFile_h */
