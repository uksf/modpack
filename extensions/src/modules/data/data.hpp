#pragma once
#include "component.hpp"

class uksf_data : public singleton<uksf_data>, public threaded<uksf_data> {
public:
    uksf_data();

    void function() override;

private:
    bool _enabled = ENABLED_DEFAULT;
    int _frequency = ENABLED_DEFAULT;
};
