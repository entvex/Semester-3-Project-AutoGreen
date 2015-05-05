#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include "stdio.h"
#include "Monitor.hpp"
#include "UART.h"
#include "DataLog.hpp"
#include "SystemLog.hpp"

using namespace std;

struct MtnPkg
{
  SystemLog syslog;
  UART uart_;
  DataLog datalog_;
};

void *MonitorTrd(void *data)
{
  Monitor* mon;
  MtnPkg msg = (MtnPkg)msg;
  mon->setInd(msg.uart_, msg.datalog_);
  for(;;){
    mon->compareData();
  }
}

int main()
{ 
  SystemLog sl;
  UART ua;
  DataLog data;
  
  MtnPkg msg;
  msg.uart_ = ua;
  msg.datalog_ = data;
 
  pthread_t monitor_;

  pthread_create(&monitor_, NULL, MonitorTrd, (void *) &msg);

  pthread_join(monitor_, NULL);

  return 0;
}
