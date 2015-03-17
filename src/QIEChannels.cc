#include "QIEChannels.h"
#include <algorithm>


void QIEChannels::buildQIEChannels( std::ifstream& qietable )
{
  std::string line;

  if ( qietable.is_open() )
  {
    while ( getline( qietable , line ) )
    {
      char *tmp = new char[line.length() + 1];
      strcpy( tmp,line.c_str() );

      sscanf( tmp , "%i %i %i %s %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f", &eta, &phi , &dep , det ,&offsets[0] , &offsets[1] ,  &offsets[2] , &offsets[3] , &offsets[4] , &offsets[5] , &offsets[6] , &offsets[7] , &offsets[8] , &offsets[9] , &offsets[10] , &offsets[11] , &offsets[12] , &offsets[13] , &offsets[14] , &offsets[15] , &slopes[0] , &slopes[1] ,  &slopes[2] , &slopes[3] , &slopes[4] , &slopes[5] , &slopes[6] , &slopes[7] , &slopes[8] , &slopes[9] , &slopes[10] , &slopes[11] , &slopes[12] , &slopes[13] , &slopes[14] , &slopes[15] );
 
      delete [] tmp;

      ConvertQIEChannels( );  
    }
  }
}

void QIEChannels::ConvertQIEChannels( )
{
  oneQIEchannel media;

  media.eta = eta;
  media.phi = phi;
  media.dep = dep;
  media.det = det;

  for( int i=0 ; i < 16 ; i++ )
  {
    media.cap = i/4;
    media.rng = i%4;
    media.offset = offsets[i];
    media.slope = slopes[i];
    QIEchannels.push_back(media);
  }
}

