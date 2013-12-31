#include "GGASimulator.h"
#include <iostream>

using namespace std;
/**
 * GGA Sentence generation starts here
 */
int main(int argc, char* argv[])
{
   GGASimulator* simulator;
   simulator = new GGASimulator();
   
   /*
   *  Construct the GGA sentence that looks something like:
   *     
   *     $GPGGA,hhmmss.ss,llll.ll,a,yyyyy.yy,a,x,xx,x.x,x.x,M,x.x,M,x.x,xxxx*hh
   *
   *  where:
   *     
   *     hhmmss.ss = UTC of position 
   *     llll.ll = latitude of position
   *     a = N or S
   *     yyyyy.yy = Longitude of position
   *     a = E or W 
   *     x = GPS Quality indicator (0=no fix, 1=GPS fix, 2=Dif. GPS fix) 
   *     xx = number of satellites in use 
   *     x.x = horizontal dilution of precision 
   *     x.x = Antenna altitude above mean-sea-level
   *     M = units of antenna altitude, meters 
   *     x.x = Geoidal separation
   *     M = units of geoidal separation, meters 
   *     x.x = Age of Differential GPS data (seconds) 
   *     xxxx = Differential reference station ID 
   *     hh = checksum for the sentence
   *
   */ 
   string message = "GPGGA," + simulator->getRandTime() + "," + simulator->getRandLat() + "," + simulator->getRandLon() + "," + simulator->getRandFixQual() + "," ;
   message = message + simulator->getRandSatNo() + "," + simulator->getRandHorDil() + "," + simulator->getRandAlt() + "," + simulator->getRandGeoidH() + ",";
   message = message + simulator->getRandLastDGPSUpdt() + "," + simulator->getRandDGPSRefSID();

   string checksum = simulator->getChecksum(message);

   message = "$" + message + "*" + checksum;

   cout << message;
   return 0;   
}
