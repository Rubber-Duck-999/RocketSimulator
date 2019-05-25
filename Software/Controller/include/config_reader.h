#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <libconfig.h++>
#include "logging.h"

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
    };
    
    ~ConfigurationReader() {};
    
    void SetConfigValues();
    
    bool config_available_ = false;
    
private:

    Config object_cfg_;
    
    void ReadConfig();
    
    const char* config_file_ = "/mnt/c/Users/simon/Documents/Config/use.conf";
    
    std::string config_title_ = "title";
    
    //int internal
    
    std::string config_sub_title_ = "year";
    
};

#endif