#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

struct oneQIEChannel
{
  int eta;
  int phi;
  int dep;
  std::string det;
  int cap;
  int rng;
  double offset;
  double slope;
};

class QIEChannels
{
 private:
  int eta_;
  int phi_;
  int dep_;
  std::string det_;
  double offsets_[16];
  double slopes_[16];

  void ConvertQIEChannels( );

 public:
  std::vector<oneQIEChannel> HBQIEchannels;
  std::vector<oneQIEChannel> HEQIEchannels;
  std::vector<oneQIEChannel> HFQIEchannels;
  std::vector<oneQIEChannel> HOQIEchannels;
  std::vector<oneQIEChannel> OtherQIEchannels;

  void buildQIEChannels( std::ifstream& qietable );
  void printQIEChannels( );

  double getoffset(
                   int eta,
                   int phi,
                   int dep,
                   std::string det,
                   int cap,
                   int rng
                  );
  double getslope(
                  int eta,
                  int phi,
                  int dep,
                  std::string det,
                  int cap,
                  int rng
                 );
};

namespace tools
{
  // Split a string into a vector of strings that are split by a delimiter
  void split ( const std::string & content,
               std::vector<std::string> & output,
               const char & delimiter );

};


