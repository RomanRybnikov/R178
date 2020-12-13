#pragma once
#include "ILogout.h"

class IPublisher {
public: 
	virtual void addSub(ILogOut&) = 0;
	virtual void publish(ItemType) = 0;
	virtual ~IPublisher() {};
};

class Publisher : public IPublisher {
public:
    void addSub(ILogOut& logOut) override {
        this->logOut = &logOut;
    };
    void publish(ItemType type) override {
        logOut->subscribe(type);
    };

private:
    ILogOut* logOut;
};