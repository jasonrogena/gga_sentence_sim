#include "GGASimulator.h"
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;
/**
 * The constructor. Herein the rand() function is made time dependent to avoid comming up with the same number all the time
 */
GGASimulator::GGASimulator()
{
   //make random time dependent

   srand(time(0));

}

GGASimulator::~GGASimulator()
{
   //TODO: release mem gotten from heap mem
}

/**
 * This method generates random time in the form 
 *    
 *       hhmmss.ss
 *
 *       @return  string   the string representation of the time
 */
string GGASimulator::getRandTime()
{
   //time in the format hhmmss.sss
   //get random number for hour, minute, and second separatelly
   int hour = rand() % 25; //random number between 0 and 24
   string hString = to_string(hour);
   while(hString.size() < 2 )
   {
      hString  = "0" + hString;
   }
   
   int min = rand() % 61; //random number between 0 - 60
   string mString = to_string(min);
   while(mString.size() < 2)
   {
      mString = "0" + mString;
   }
      
   int sec = rand() % 61;
   string sString = to_string(sec);
   while(sString.size() < 2)
   {
      sString = "0" + sString;
   }
    
   int msec = rand() % 100;
   string msString = to_string(msec);
   while(msString.size() < 2)
   {
      msString = "0" + msString;
   }   
   
   return hString + mString + sString + "." + msString;
}

/**
 * This method generates a random latitude in the form
 *
 *   llll.ll,a
 * 
 * where 'a' is the hemisphere    
 *
 * @return  string   the string representation of the latitude
 */
string GGASimulator::getRandLat()
{
   //latitude in the form of xxxx.xxxx
   //the first two digits are the degrees
   int latPrefix = rand() % 91;

   //each degree is 60 minutes
   int latSuffix = rand() % 60;

   int latSuffixMantissa = rand() % 10000;
   
   string lat = to_string(latPrefix);
   
   while(lat.size() < 2)
   {
      lat = "0" + lat;
   }

   string lSuffString = to_string(latSuffix);
   while(lSuffString.size() < 2)
   {
      lSuffString = "0" + lSuffString;
   }
   
   lat = lat + lSuffString;

   string mantissa = to_string(latSuffixMantissa);
   while(mantissa.size() < 2)
   {
      mantissa = "0" + mantissa;
   }
    
   char hem[2] = {'N','S'};
   int randHem = rand() % 2;
   
   return lat + "." + mantissa  + "," + hem[randHem];
}

/**
 * This method generates a random longitude in the form
 *    
 *    yyyyy.yy,a
 *
 * where a is the hemisphere (for lack of a better word)
 *
 * @return  string   the string representation of the longitude
 */
string GGASimulator::getRandLon()
{
   //longitude is in the form xxxxx.xxxx
   //the first three digits are the degrees
   int lonPrefix = rand() % 181;
   
   int lonSuffix = rand() % 60;
   int lonSuffixMantissa = rand() % 10000;

   string lon = to_string(lonPrefix);
   while(lon.size()<3)
   {
      lon = "0" + lon;
   }   
   
   string lSuffString = to_string(lonSuffix); 
   while(lSuffString.size()<2)
   {
      lSuffString = "0" + lSuffString;
   }
   
   lon = lon + lSuffString;
   
   string mantissa = to_string(lonSuffixMantissa);
   while(mantissa.size() < 2)
   {
      mantissa = "0" + mantissa;
   }
    
   char hem[2] = {'W','E'};
   int randHem = rand() % 2;
   return lon + "." + mantissa  + "," + hem[randHem];
}

/**
 * This method generates a random fix quality that can eiter be 0, 1 or 2
 *
 * @return  string   the string representation of the fix-quality
 */
string GGASimulator::getRandFixQual()
{
   //can either be 0,1 or 2
   return to_string(rand() % 3);
}

/**
 * This method generates a random number of viwable satellites which is the form
 *    
 *    xx 
 *
 * @return  string   the string representation of the number of viewable satellites
 */
string GGASimulator::getRandSatNo()
{
   //max viewable sats = 12,min number of sats for fix = 4
   int satNo = rand() % 8 + 4;// range between 4 - 12
   string result = to_string(satNo);
   
   while(result.size() < 2)
   {
      result = "0" + result;
   }
   
   return result;
}

/**
 * This method generates a random horizontal dilution in the form
 *    
 *    x.x
 *
 * @return  string   the string representation of the horizontal dilution
 */
string GGASimulator::getRandHorDil()
{
   //horizontal dil greater than 20 should be ignored
   int horDil = rand() % 29 + 1; //range from 1 - 30
   int mantissa = rand() % 10;
   
   return to_string(horDil)+"."+to_string(mantissa);
}

/**
 * This method generates a random altitude in the form
 *
 *    x.x,M
 *
 * where M is the unit used. M - Meters used by default
 *
 * @return  string   the string representation of the altitude
 */
string GGASimulator::getRandAlt()
{
   //limiting altitude to a max of 10,000. Heighest point on earth is 8,848. This is just a simulator
   int alt = rand() % 10001;
   int mantissa = rand() % 100;
   
   return to_string(alt) + "." + to_string(mantissa) + ",M";
}

/**
 * This method generates a random geoid height in the form
 * 
 *    x.x,M
 *
 * where M is the unit used. M-Metres used by default
 *
 * @return  string   the string representation of the geoid height
 */
string GGASimulator::getRandGeoidH()
{
   int geoidH = rand() % 100;
   int mantissa = rand() % 100;
   string posNeg[2] = {"","-"};
   
   int randPosNeg = rand() % 2;
   
   return posNeg[randPosNeg] + to_string(geoidH) + "." + to_string(mantissa) +",M";
}

/**
 * This method generates a random last-DGPS update in the format
 *    
 *    x.x
 *
 * @return  string   the string representation of the last DGSP update
 */
string GGASimulator::getRandLastDGPSUpdt()
{
   //time from last DGPS update in seconds
   int time = rand() % 1001;
   int mantissa = rand() % 100;
   
   return to_string(time) + "." + to_string(mantissa);
}

/**
 * This method generates a random DGPS reference station ID in the format
 *
 *   xxxx
 *
 * @return  string   the string representation of the random reference station ID 
 */
string GGASimulator::getRandDGPSRefSID()
{
   //range between 0000 and 9999
   int sID = rand() % 10000;
   
   string idString = to_string(sID);
   
   while(idString.size() < 4)
   {
      idString = "0" + idString;
   }
   
   return idString;
}

/**
 * This method calculates the checksum for the message using a Cyclic redundancy check and outputs the checksum in the format
 *
 *    hh (Hexadecimal)
 *
 * @param   string   currMsg   The message from which the checksum is to be generated
 *
 * @return  string   String representation of the hexadecimal checksum
 */
string GGASimulator::getChecksum(string currMsg)
{
   //The checksum field consists of a '*' and two hex digits representing an 8 bit exclusive OR of all characters between,but not including,the '$' and '*'
   
   //1. convert string to char array#
   char msg[currMsg.size()];
   strcpy(msg,currMsg.c_str());
   
   //create the crc crc
   unsigned int crc = 0;
   for(int i = 0; i < sizeof(msg); i++)
   {
      crc = crc ^ msg[i];
   }
   
   //convert crc to hexadecimal
   stringstream sstream;
   sstream << hex << crc;
   string hexString = sstream.str();
   
   return hexString;
}
