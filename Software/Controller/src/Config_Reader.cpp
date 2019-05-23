#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <libconfig.h++>

using namespace std;
using namespace libconfig;

int call(int argc, char **argv)
{
  Config cfg;

  // Read the file. If there is an error, report it and exit.
  try
  {
    cfg.readFile("../example_simple.cfg");
  }
  catch(const FileIOException &fioex)
  {
    std::cerr << "I/O error while reading file." << std::endl;
    return(EXIT_FAILURE);
  }
  catch(const ParseException &pex)
  {
    std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
              << " - " << pex.getError() << std::endl;
    return(EXIT_FAILURE);
  }

  const Setting& root = cfg.getRoot();
  try
  {
    const Setting &albums = root["albums"];
    for(int i = 0; i < albums.getLength(); ++i)
    {
      const Setting &album = albums[i];
      string my_title;
      int my_year;
      vector<string> my_songs;

      album.lookupValue("title", my_title);
      cout << "title: " << my_title << endl;
      album.lookupValue("year", my_year);
      cout << "year: " << my_year << endl;

      const Setting &songs_settings = album.lookup("songs");
      vector<string> songs;
      for (int n = 0; n < songs_settings.getLength(); ++n)
      {
          my_songs.push_back(songs_settings[i]);
          cout << "song number " << n << ": " << my_songs[n] << endl;
      }
    }
  }
  catch(const SettingNotFoundException &nfex)
  {
    // Ignore.
  }

  return(EXIT_SUCCESS);
}