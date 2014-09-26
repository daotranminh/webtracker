#ifndef ___DATABASE_HPP___
#define ___DATABASE_HPP___

#include "tracker/DataItem.hpp"


class Database
{
public:
  Database(const std::string &name = "");

  void
  add(const DataItem &di);

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

#endif // ___DATABASE_HPP___
