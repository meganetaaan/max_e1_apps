#ifndef MAX_E1_MODES_HPP_
#define MAX_E1_MODES_HPP_

#include "max_e1_core.hpp"

class MaxE1Bus
{
public:
    MaxE1Bus(const std::shared_ptr<MaxE1Core> & core);
    ~MaxE1Bus();
    bool init();
    bool set_app_port(uint8_t port);
    bool set_bypass_port(uint8_t port);
    bool set_remote_port(uint8_t port);
    uint8_t get_app_port();
    uint8_t get_bypass_port();
    uint8_t get_remote_port();

private:
    std::shared_ptr<MaxE1Core> core_;
    int app_port_;
    int bypass_port_;
    int remote_port_;
};

#endif