#include <cassert>
#include <iostream>
#include <fstream>

#include "utilities/Configuration.hpp"
#include "utilities/Logger.hpp"

Configuration* 
Configuration::_instance = 0;

Configuration::Configuration()
  : m_PathRoot("")
{ }



Configuration*
Configuration::instance()
{
  if (_instance == 0)
    {
      _instance = new Configuration;
    }
  return _instance;
}



std::string
Configuration::readLine(const std::string& filename, const std::string& key)
{
  // configuration follows CSV format
  std::ifstream config_file(filename.c_str());
  if (config_file.is_open())
    {
      std::string line;
      while (config_file.good())
	{
	  std::getline(config_file, line);
	  std::size_t pos = line.find(key);
	  if (pos != std::string::npos)
	    {
	      std::string value = line.substr(pos + key.length() + 1);
	      config_file.close();
	      return value;
	    }
	}
      config_file.close();
    }
  else 
    {
      DBGERR(__FUNCTION__ << ": Cannot read configuration file: " << filename << "!")
    }
	
  return "ERROR";
}



void
Configuration::readConfig(const std::string& filename)
{
  m_PathRoot     = readLine(filename, "PATH_ROOT");
  m_PathDatabase = m_PathRoot + readLine(filename, "DIR_DATABASE");
  m_BeginURL     = readLine(filename, "BEGINURL");
  m_EndURL       = readLine(filename, "ENDURL");
  m_BeginTitle   = readLine(filename, "BEGINTITLE");
  m_EndTitle     = readLine(filename, "ENDTITLE");
  m_BeginDesc    = readLine(filename, "BEGINDESC");
  m_EndDesc      = readLine(filename, "ENDDESC");
  m_BeginPrice   = readLine(filename, "BEGINPRICE");
  m_EndPrice     = readLine(filename, "ENDPRICE");

  std::ifstream config_file(filename.c_str());
  if (config_file.is_open())
    {
      std::string line;
      while (config_file.good())
	{
	  std::getline(config_file, line);
          std::size_t pos = line.find("URL");
          if (pos == 0)
            {
              std::string link = line.substr(pos + 4); // 4 == length("URL") + 1
              std::getline(config_file, line);
              pos = line.find("PREFIX");
              std::cout << line << std::endl;
              assert(pos != std::string::npos);
              std::string prefix = line.substr(pos + 7); // 7 == length("PREFIX") + 1
              TrackedSite ts(link, prefix);
              m_TrackedSites.push_back(ts);
            }
        }
    }
  else
    {
      DBGERR(__FUNCTION__ << ": Cannot read configuration file: " << filename << "!")
    }
}
