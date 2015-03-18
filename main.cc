#include <iostream>
#include <fstream>
#include "interface/QIEChannels.h"

int main()
{
  std::ifstream qiechannels_old ("data/DumpQIEData_v7.02_offline_Run220500.txt");
  std::ifstream qiechannels_new ("data/QIE_normalmode_OfflineDB_without_HOX_G.txt");

  QIEChannels myQIEChannels_old;
  QIEChannels myQIEChannels_new;

  myQIEChannels_old.buildQIEChannels( qiechannels_old );
  myQIEChannels_new.buildQIEChannels( qiechannels_new );

  //test
  myQIEChannels_old.printQIEChannels();
  myQIEChannels_new.printQIEChannels();

  std::cout << " " << std::endl;

  return 0;
}

