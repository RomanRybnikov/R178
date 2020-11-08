#include "Loger.h"

unsigned int Loger::m_LogCount = 0;

Loger::Loger(){
    // открываем файл (по идиоме ROII открываем в конструкторе)
    if (m_LogCount == 0) m_File = new std::ofstream(LOG_FILE_NAME, std::ios_base::trunc); // если логов небыло то очистка всего что было      
    else m_File = new std::ofstream(LOG_FILE_NAME, std::ios_base::app); // если логи уже были то ничего не удаляем а пишем вконец
    ++m_LogCount;
}
// trunc - Задает удаление содержимого существующего файла при создании его управляющего объекта.
// app - Задает поиск до конца потока перед каждой вставкой.

Loger::~Loger(){
    m_File->close(); // по идиоме ROII закрываем в деструкторе (ресурс гарантировано открыт и закрыт в нужной области видимости)
    delete m_File;
}

std::ostream& Loger::Stream() // возвращает поток вывода логов
{
    return *m_File;
}
