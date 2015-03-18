#include "../interface/QIEChannels.h"
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <sstream>
#include <string>
#include <functional>
#include <cctype>
#include <locale>

void QIEChannels::buildQIEChannels( std::ifstream& qietable )
{
  std::string line;

  if ( qietable.is_open() )
  {
    while ( getline( qietable , line ) )
    {
      std::vector<std::string> entries;
      tools::split( line , entries, ' ');
      
      //std::cout << entries[1] << std::endl; 
      //tricky part here, delete the first element in the vector because we get a space at the first of each line so the first element in the vector is empty, which will destroy the stod and stoi function
      entries.erase ( entries.begin() );

      eta_ = std::stoi( entries[0] );
      phi_ = std::stoi( entries[1] );
      dep_ = std::stoi( entries[2] );
      det_ = entries[3];
     
      for(int i = 0 ; i < 16 ; i++)
      {
        offsets_[i] = std::stod( entries[4+i] );
        slopes_[i] = std::stod( entries[4+16+i] );
      }

      ConvertQIEChannels( );  
      det_.clear();
      entries.clear();
    }
  }
}

void QIEChannels::ConvertQIEChannels( )
{
  oneQIEChannel media;

  media.eta = eta_;
  media.phi = phi_;
  media.dep = dep_;
  media.det = det_;

  for( int i=0 ; i < 16 ; i++ )
  {
    media.cap = i/4;
    media.rng = i%4;
    media.offset = offsets_[i];
    media.slope = slopes_[i];
    QIEchannels.push_back(media);
  }
}

void QIEChannels::printQIEChannels( )
{
  std::vector<oneQIEChannel>::iterator iter;

  for( iter = QIEchannels.begin() ; iter != QIEchannels.end() ; iter++)
  {
    std::cout << (*iter).eta << ","<< (*iter).phi << "," << (*iter).dep << ","<< (*iter).det << ","<< (*iter).cap << ","<< (*iter).rng << ","<< (*iter).offset << ","<< (*iter).slope << std::endl;
  }
}

// namepspace tools
void tools::split ( const std::string & content,
                    std::vector<std::string> & output,
                    const char & delimiter )
{
  output.clear();
  std::istringstream ss (content);
  std::string entry;
  while ( std::getline(ss, entry, delimiter ) )
    output.push_back ( entry );
}

