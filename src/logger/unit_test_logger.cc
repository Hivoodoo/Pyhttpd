#include "logger.h"
#include <bits/stdc++.h>

int main()
{
  using namespace Log;
  using namespace std;
  for (int i = 0; i < static_cast<int>(LogLevel::kNUM_T); i++){
    Logger::level(static_cast<LogLevel>(i));
    cout<<"cur level:"<<kCODESTRING[i]<<endl;
    for (int j = 0; j < static_cast<int>(LogLevel::kNUM_T); j++){
      Logger::i(static_cast<LogLevel>(j),"test");
    }
    cout<<endl;
  }
  return 0;
}

