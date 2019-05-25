#include "config_reader.h"

void ConfigurationReader::ReadConfig()
{
    try
    {
        BOOST_LOG_TRIVIAL(debug) << "Config file is: " << config_file_;
        object_cfg_.readFile(config_file_);
        //object_cfg_.readFile("../src/use.conf");
        // Read the file. 
        // If there is an error, report it and exit.
    }
    catch(const FileIOException &fioex)
    {
         BOOST_LOG_TRIVIAL(error) << "I/O error while reading file.";
        config_available_ = false;
        return;
        //return(EXIT_FAILURE);
    }
    catch(const ParseException &pex)
    {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                << " - " << pex.getError() << std::endl;
        config_available_ = false;
        return;
        //return(EXIT_FAILURE);
    }
    config_available_ = true;
    //return(EXIT_SUCCESS);
}

void ConfigurationReader::SetConfigValues()
{
    ReadConfig();
    if(config_available_)
    {
        BOOST_LOG_TRIVIAL(debug) << "A config file is available";
        const Setting& root = object_cfg_.getRoot();
        try
        {
            const Setting &albums = root["albums"];
            for(int i = 0; i < albums.getLength(); ++i)
            {
              const Setting &album = albums[i];
              string mytitle;
              int myyear;
              vector<string> my_songs;

              album.lookupValue(config_title_, mytitle);
              BOOST_LOG_TRIVIAL(debug) << "title: " << mytitle;
              //cout << "title: " << mytitle << endl;
              album.lookupValue(config_sub_title_, myyear);
              BOOST_LOG_TRIVIAL(debug) << "year: " << myyear;

              const Setting &songs_settings = album.lookup("songs");
              vector<string> songs;
              for (int n = 0; n < songs_settings.getLength(); ++n)
              {
                  my_songs.push_back(songs_settings[i]);
                  BOOST_LOG_TRIVIAL(debug) << "song number " << n << ": " << my_songs[n];
                  //cout << "song number " << n << ": " << my_songs[n] << endl;
              }
            }
        }
        catch(const SettingNotFoundException &nfex)
        {
        // Ignore.
        }
    }
}