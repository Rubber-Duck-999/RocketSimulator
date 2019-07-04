#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <libconfig.h++>
#include "logging.h"
#include "data_structure.h"

using namespace std;
using namespace libconfig;

#ifndef CONFIG_READER_h
#define CONFIG_READER_h

class ConfigurationReader
{
public:
    ConfigurationReader() 
    {
        Config object_cfg_;
        char message_send[rocket_simulator::kConfig.length() + 1];
        strcpy(message_send, rocket_simulator::kConfig.c_str());
        config_file_ = message_send;
    };
    
    ~ConfigurationReader() {};
    
    void SetConfigValues();
    
    bool config_available_ = false;
    
private:

    Config object_cfg_;
    
    void ReadConfig();
    
    const char* config_file_;
    
    std::string config_title_ = "title";
    
    std::string config_sub_title_ = "year";
    
};

#endif