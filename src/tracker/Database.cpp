#include <fstream>

#include "tracker/Database.hpp"
#include "utilities/Configuration.hpp"
#include "utilities/Logger.hpp"

Database::Database(const std::string &name)
  : m_Name(name)
{
  if (m_Name != "") loadDatabase();
}



void
Database::add(const DataItemPtr &di)
{
  m_DataItems.push_back(di);
}



void
Database::writeDatabase()
{
  std::ofstream file_db(m_Name.c_str());
  Configuration *config = Configuration::instance();

  if (file_db.is_open())
    {
      for (DataItemVec::const_iterator it = m_DataItems.begin(); it != m_DataItems.end(); ++it)
        {
          const DataItemPtr &di = *it;
          file_db << config->beginURL() << std::endl
                  << di->m_URL << std::endl
                  << config->endURL() << std::endl
                  << config->beginTitle() << std::endl
                  << di->m_Title << std::endl
                  << config->endTitle() << std::endl
                  << config->beginDesc() << std::endl
                  << di->m_Description << std::endl
                  << config->endDesc() << std::endl
                  << config->beginPrice() << std::endl
                  << di->m_Price << std::endl
                  << config->endPrice() << std::endl;
        }
    }
  else
    {
      DBGERR(__FUNCTION__ << ": Cannot write to database file \"" << m_Name << "\"!")
    }

  file_db.close();
}



std::string
readContent(std::ifstream &file_input,
            const std::string &beg,
            const std::string &end)
{
  std::string content = "";
  std::string line;

  while (file_input.good() && line != beg) 
    std::getline(file_input, line);

  std::getline(file_input, line);
  while (file_input.good() && line != end)
    {
      content = content + line + "\n";
      std::getline(file_input, line);
    }

  return content;
}


void
Database::loadDatabase()
{
  std::ifstream file_db(m_Name.c_str());

  if (file_db.is_open())
    {
      Configuration *config = Configuration::instance();
      while (file_db.good())
        {
          std::string url = readContent(file_db, config->beginURL(), config->endURL());
          std::string title = readContent(file_db, config->beginTitle(), config->endTitle());
          std::string desc = readContent(file_db, config->beginDesc(), config->endDesc());
          std::string str_price = readContent(file_db, config->beginPrice(), config->endPrice());
          float price = ::atof(str_price.c_str());

          DataItemPtr di = DataItemPtr(new DataItem(url, title, desc, price));
          m_DataItems.push_back(di);
        }
    }
}
