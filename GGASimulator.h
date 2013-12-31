#include <string>

using namespace std;

class GGASimulator
{
   public:
      GGASimulator();
      ~GGASimulator();
   
      string getRandTime();
      string getRandLat();
      string getRandLon();
      string getRandFixQual();
      string getRandSatNo();
      string getRandHorDil();
      string getRandAlt();
      string getRandGeoidH();
      string getRandLastDGPSUpdt();
      string getRandDGPSRefSID();
      string getChecksum(string currMsg);
};
