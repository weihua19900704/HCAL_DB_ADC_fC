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

      //char *tmp = new char[line.length() + 1];
      //strcpy( tmp , line.c_str() );
      //char det_char[5];

      //sscanf( tmp , "%i %i %i %s %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f", &eta_ , &phi_ , &dep_ , det_char , &offsets_[0] , &offsets_[1] ,  &offsets_[2] , &offsets_[3] , &offsets_[4] , &offsets_[5] , &offsets_[6] , &offsets_[7] , &offsets_[8] , &offsets_[9] , &offsets_[10] , &offsets_[11] , &offsets_[12] , &offsets_[13] , &offsets_[14] , &offsets_[15] , &slopes_[0] , &slopes_[1] ,  &slopes_[2] , &slopes_[3] , &slopes_[4] , &slopes_[5] , &slopes_[6] , &slopes_[7] , &slopes_[8] , &slopes_[9] , &slopes_[10] , &slopes_[11] , &slopes_[12] , &slopes_[13] , &slopes_[14] , &slopes_[15] );
 
      //det_.append( det_char );
      //delete [] tmp;

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

