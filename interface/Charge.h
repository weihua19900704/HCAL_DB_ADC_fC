#include <iostream>
#include <string>
#include <vector>

class Charge
{
 public:
  void getQIEChannel(
                     int eta,
                     int phi,
                     int dep,
                     std::string det,
                     int cap,
                     int rng,
                     double offset,
                     double slope
                    );

  double ChargeCalculator(
                          int chargenumber
                         );

 private: 
  int eta_ , phi_ , dep_ , cap_ , rng_;
  std::string det_;
  double offset_ , slope_;

  int chargenumbertoADC(
                        int chargenumber
                       );
};


