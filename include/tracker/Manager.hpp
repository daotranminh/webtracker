#ifndef ___MANAGER_HPP___
#define ___MANAGER_HPP___

#include <string>

class Manager
{
public:
  void
  process();

private:
  void
  trackSingleSite(const std::string &url,
                  const std::string &prefix);
};

#endif // ___MANAGER_HPP___
