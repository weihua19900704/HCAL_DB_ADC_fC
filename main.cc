#include <iostream>
#include <fstream>
#include "interface/QIEChannels.h"
#include "interface/Charge.h"
#include "interface/Histgram.h"

int main()
{
  std::ifstream qiechannels_old ("data/DumpQIEData_v7.02_offline_Run220500.txt");
  std::ifstream qiechannels_new ("data/QIE_normalmode_OfflineDB_without_HOX_G.txt");

  QIEChannels myQIEChannels_old;
  QIEChannels myQIEChannels_new;

  myQIEChannels_old.buildQIEChannels( qiechannels_old );
  myQIEChannels_new.buildQIEChannels( qiechannels_new );

  //test slope,offset
  //double testslope = myQIEChannels_new.getslope(
  //                                                -1,
  //                                                1,
  //                                                1,
  //                                                "HB",
  //                                                0,
  //                                                3
  //                                               );
  //std::cout << testslope << std::endl;

  //test QIEChannels class
  //myQIEChannels_old.printQIEChannels();
  //myQIEChannels_new.printQIEChannels();

  Charge myCharge;
  int chargenumber = 7;

  BaseHistgram myBaseHistgram;
  myBaseHistgram.BookHistgram("test.root");

  //test Charge Class
  //myCharge.getQIEChannel(
  //                       3,
  //                       0.1624,
  //                       0.9278
  //                      );
  //double testcharge = myCharge.ChargeCalculator(chargenumber);
  //std::cout << testcharge << std::endl;

  std::vector<oneQIEChannel>::iterator iter;
  for( iter = myQIEChannels_new.HBQIEchannels.begin() ; iter != myQIEChannels_new.HBQIEchannels.end() ; iter++)
  {
    double charge_old = 0, charge_new = 0;
    myCharge.getQIEChannel(
                           (*iter).rng,
                           (*iter).offset,
                           (*iter).slope
                          );
    charge_new = myCharge.ChargeCalculator(chargenumber);
    
    double offset_tmp = 0, slope_tmp = 0;
    offset_tmp = myQIEChannels_old.getoffset(
                                             (*iter).eta,
                                             (*iter).phi,
                                             (*iter).dep,
                                             (*iter).det,
                                             (*iter).cap,
                                             (*iter).rng
                                            );
    slope_tmp = myQIEChannels_old.getslope(
                                           (*iter).eta,
                                           (*iter).phi,
                                           (*iter).dep,
                                           (*iter).det,
                                           (*iter).cap,
                                           (*iter).rng
                                          );
    if( offset_tmp < -900 || slope_tmp < -900 )
      continue;
    myCharge.getQIEChannel(
                           (*iter).rng,
                           offset_tmp,
                           slope_tmp
                          );
    charge_old = myCharge.ChargeCalculator(chargenumber);
    double charge_diff = 0;
    charge_diff = (charge_new - charge_old) / charge_new;
    (myBaseHistgram.h_Charge_Diff)->Fill(charge_diff);
    /*
    if( charge_diff > 0.3 || charge_diff < -0.3)
    {
      std::cout << charge_diff << std::endl;
      std::cout << (*iter).offset <<","<< (*iter).slope << std::endl;
      std::cout << offset_tmp <<","<< slope_tmp << std::endl;
      std::cout << (*iter).eta << "(eta),"<< (*iter).phi << "(phi)," << (*iter).dep << "(depth),"<< (*iter).det << "(subdet),"<< (*iter).cap << "(capId),"<< (*iter).rng << "(range)" << std::endl;
    }
    */
    //std::cout << charge_diff << std::endl;
  }

  (myBaseHistgram.oFile)->Write();
  return 0;
}

