#include <iostream>
#include <fstream>
#include "interface/QIEChannels.h"
#include "interface/Charge.h"

int main()
{
  std::ifstream qiechannels_old ("data/DumpQIEData_v7.02_offline_Run220500.txt");
  std::ifstream qiechannels_new ("data/QIE_normalmode_OfflineDB_without_HOX_G.txt");

  QIEChannels myQIEChannels_old;
  QIEChannels myQIEChannels_new;

  myQIEChannels_old.buildQIEChannels( qiechannels_old );
  myQIEChannels_new.buildQIEChannels( qiechannels_new );

  double testslope = myQIEChannels_new.getslope(
                                                  -1,
                                                  1,
                                                  1,
                                                  "HB",
                                                  0,
                                                  3
                                                 );
  std::cout << testslope << std::endl;

  //test QIEChannels class
  //myQIEChannels_old.printQIEChannels();
  //myQIEChannels_new.printQIEChannels();

  Charge myCharge;
  int chargenumber = 0;

  //test Charge Class
  //myCharge.getQIEChannel(
  //                       3,
  //                       0.1624,
  //                       0.9278
  //                      );
  
  //double testcharge = myCharge.ChargeCalculator(chargenumber);
  //std::cout << testcharge << std::endl;

  return 0;
}

