#ifndef ___DATABASE_HPP___
#define ___DATABASE_HPP___

#include <boost/shared_ptr.hpp>

#include "tracker/DataItem.hpp"

class Database
{
public:
  Database(const std::string &name = "");

  void
  add(const DataItemPtr &di);

  void
  writeDatabase();

private:
  void
  loadDatabase();

  std::string
  readContent(std::ifstream &file_input,
              const std::string &beg,
              const std::string &end);

private:
  const std::string m_Name;
  DataItemVec       m_DataItems;
};

typedef boost::shared_ptr<Database> DatabasePtr;


#endif // ___DATABASE_HPP___
