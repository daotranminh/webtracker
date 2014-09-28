#ifndef ___TRACKER_HPP___
#define ___TRACKER_HPP___

#include <curl/curl.h>
#include <string>

#include "html/ParserDom.h"
#include "tracker/Database.hpp"

using namespace htmlcxx;

class Tracker
{
public:
  Tracker(const std::string &url);

  DatabasePtr
  track(bool gratis = false);

private:
  std::string
  fetch();

  DataItemPtr
  getOneDataItem(const std::string &content,
                 tree<HTML::Node>::iterator &it,
                 bool gratis);

  bool
  inIgnoreList(const std::string &url);

private:
  const std::string m_URL;

  CURL *m_Curl;
  CURLcode m_Res;
};


std::size_t
writeData(char *ptr, 
	  std::size_t size, 
	  std::size_t nmemb, 
          void *userdata);


#endif // ___TRACKER_HPP___
