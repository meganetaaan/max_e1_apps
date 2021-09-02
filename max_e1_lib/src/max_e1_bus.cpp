
#include <iostream>
#include "max_e1_bus.hpp"

// CM-550 e-manual:https://emanual.robotis.com/docs/en/parts/controller/cm-550/
constexpr uint16_t ADDR_BYPASS_PORT = 20;
constexpr uint16_t ADDR_APP_PORT = 36;
constexpr uint16_t ADDR_REMOTE_PORT = 43;

MaxE1Bus::MaxE1Bus(const std::shared_ptr<MaxE1Core> & core)
    : core_(core)
{
}

MaxE1Bus::~MaxE1Bus()
{
}

bool MaxE1Bus::init()
{
    std::cout<<"Modes init() is called."<<std::endl;
    return true;
}

uint8_t MaxE1Bus::get_bypass_port()
{
    uint8_t data8;
    if(core_->read_1byte(ADDR_BYPASS_PORT, &data8)) {
        return data8;
    } else {
        return 255;
    }
}

uint8_t MaxE1Bus::get_app_port()
{
    uint8_t data8;
    if(core_->read_1byte(ADDR_APP_PORT, &data8)) {
        return data8;
    } else {
        return 255;
    }
}

uint8_t MaxE1Bus::get_remote_port()
{
    uint8_t data8;
    if(core_->read_1byte(ADDR_REMOTE_PORT, &data8)) {
        return data8;
    } else {
        return 255;
    }
}

bool MaxE1Bus::set_app_port(uint8_t port)
{
    return core_->write_1byte(ADDR_APP_PORT, port);
}

bool MaxE1Bus::set_bypass_port(uint8_t port)
{
    return core_->write_1byte(ADDR_BYPASS_PORT, port);
}

bool MaxE1Bus::set_remote_port(uint8_t port)
{
    return core_->write_1byte(ADDR_REMOTE_PORT, port);
}
