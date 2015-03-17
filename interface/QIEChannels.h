#include <string>
#include <iostream>
#include <vector>
#include <fstream>

class QIEChannels
{
 public:
  std::vector<onechannel> QIEchannels;
  void buildQIEChannels( std::ifstream& qietable );

 private:
  struct oneQIEchannel
  {
    int eta;
    int phi;
    int dep;
    std::string det;
    int cap;
    int rng;
    double slope;
    double offset;
  }
  
  int eta;
  int phi;
  int dep;
  std::string det;
  double offsets[16];
  double slopes[16];

  void ConvertQIEChannels( );
};

