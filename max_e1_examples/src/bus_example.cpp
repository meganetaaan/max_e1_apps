
#include <chrono>
#include <thread>
#include <iostream>

#include "max_e1.hpp"

int main() {
    MaxE1 max_e1("/dev/ttyACM0", 1000000);
    if(max_e1.connect()){
        max_e1.init();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        uint8_t port;
        std::cout<<"Show ports"<<std::endl;
        port = max_e1.bus->get_app_port();
        std::cout<<"App port: "<<unsigned(port)<<std::endl;
        port = max_e1.bus->get_remote_port();
        std::cout<<"Remote port: "<<unsigned(port)<<std::endl;
        port = max_e1.bus->get_bypass_port();
        std::cout<<"Bypass port: "<<unsigned(port)<<std::endl;

        std::cout<<"Set app port"<<std::endl;
        if (!max_e1.bus->set_app_port(1))
            std::cerr<<"Failed to set app port"<<std::endl;
        port = max_e1.bus->get_app_port();
        std::cout<<"App port: "<<unsigned(port)<<std::endl;

        std::cout<<"Set remote port"<<std::endl;
        if (!max_e1.bus->set_remote_port(1))
            std::cerr<<"Failed to set remote port"<<std::endl;
        port = max_e1.bus->get_remote_port();
        std::cout<<"Remote port: "<<unsigned(port)<<std::endl;
    }
    max_e1.disconnect();
}
