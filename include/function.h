#ifndef FUNCTIONTEST_H
#define FUNCTIONTEST_H

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <functional>
#include <thread>

namespace functionTest{
class A{
public:
    using connectHandler = std::function<void () >;
    using destoryHandler = std::function<void () >;
    connectHandler _destoryHandle;    
    destoryHandler _connectHandle; 

    void start(const std::function<void () > &connectHandle, const std::function<void () > &destoryHandle){
        std::cout << "A.start" << std::endl;
        //_connectHandle = nullptr;
       // _destoryHandle = nullptr;
    } 
    
};

class B {
public:
    void connectHandle(){
        std::cout << "connectHandle" << std::endl;
    }
	void destoryHandle(){
        std::cout << "destoryHandle" << std::endl;
    }

    void start(){
        std::cout << "B.start" << std::endl;
        startup(); 
    }

    void startup(){
        std::cout << "B.startup" << std::endl;
        A *client = dynamic_cast<A *>(_client.get());
        client->start(std::bind(&B::connectHandle, this), std::bind(&B::connectHandle, this));
    }

private:
    std::unique_ptr<A> _client = nullptr;


};

class C{
    public:
        void helloWorld(){
            std::cout << "hello world" << std::endl;
        }
};

}

#endif
