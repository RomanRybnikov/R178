#pragma once
#include "ILogout.h"
#include <map>
#include "LogFile.h"
#include "enum.h"
#include "Subscribers.h"


class FileLogOut : public ILogOut {
public:
    std::map<ItemType, ISubscriber*> subMap;
    FileLogOut() {
        logFile = new LogFile();
    }
    void createSubDict() override {
        subMap[ItemType::PERSON] = new PersonSub();
        subMap[ItemType::COIN] = new CoinSub();
        subMap[ItemType::TRAP] = new TrapSub();
        subMap[ItemType::LIFE_BUFFER] = new LifeBufferSub();
        subMap[ItemType::NONE] = new NoneSub();
    }

    void subscribe(ItemType item) override {
        subMap[item]->printInfo(logFile->getLogFile());
    }
    ~FileLogOut() {
        delete logFile;
    }

private:
    LogFile* logFile;
};