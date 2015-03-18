#include <iostream>
#include <string>
#include <vector>

class Charge
{
 public:
  void getQIEChannel(
                     int rng,
                     double offset,
                     double slope
                    );

  double ChargeCalculator(
                          int chargenumber
                         );

 private: 
  int rng_;
  double offset_ , slope_;

  int chargenumbertoADC(
                        int chargenumber
                       );
};


