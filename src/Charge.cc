#include "../interface/Charge.h"

void Charge::getQIEChannel(
                           int eta,
                           int phi,
                           int dep,
                           std::string det,
                           int cap,
                           int rng,
                           double offset,
                           double slope
                          )
{

  eta_ = eta;
  phi_ = phi;
  dep_ = dep;
  det_ = det;
  cap_ = cap;
  rng_ = rng;
  offset_ = offset;
  slope_ = slope;
}

double Charge::ChargeCalculator(
                                int chargenumber
                               )
{
  int ADC = -100;
  ADC = chargenumbertoADC( chargenumber );

  double charge = -1000;
  charge = ( ADC - offset_ )/slope_;

  return charge;
}



int Charge::chargenumbertoADC(
                              int chargenumber
                             )
{
  int ADC = -2;
  int bin[32] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,
                  18,20,22,24,26,28,30,
                  33,36,39,42,
                  46,50,54,
                  59,64 };
  int gainfactor[4] = { 1 , 5 , 25 , 125 };

  if( rng_ == 0 )
  {
    ADC = ADC + bin[chargenumber]*gainfactor[rng_];
  }
  else if ( rng_ == 1)
  {
    ADC = ADC + 64 - 5*2 + bin[chargenumber]*gainfactor[rng_];
  }
  else if ( rng_ == 2)
  {
    ADC = ADC + 64 - 5*2 + 64*5 - 25*2 + bin[chargenumber]*gainfactor[rng_];
  }
  else if ( rng_ == 3)
  {
    ADC = ADC + 64 - 5*2 + 64*5 - 25*2 + 64*25 - 125*2 + bin[chargenumber]*gainfactor[rng_];
  }
  else
  {
    std::cout << "Error range!" << std::endl;
  }



  return ADC;
}
