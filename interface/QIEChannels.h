#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

class QIEChannels
{
 private:
  struct oneQIEChannel
  {
    int eta;
    int phi;
    int dep;
    std::string det;
    int cap;
    int rng;
    double slope;
    double offset;
  };

  int eta_;
  int phi_;
  int dep_;
  std::string det_;
  double offsets_[16];
  double slopes_[16];

  void ConvertQIEChannels( );

 public:
  std::vector<oneQIEChannel> QIEchannels;
  void buildQIEChannels( std::ifstream& qietable );
  void printQIEChannels( );

};

namespace tools
{
  // Split a string into a vector of strings that are split by a delimiter
  void split ( const std::string & content,
               std::vector<std::string> & output,
               const char & delimiter );
};


