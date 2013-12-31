GGA Sentence Generation and Processing
======================================

This repository contains files corresponding to a:
  * C++ Program for generating random GGA Sentences
  * C++ script for processing GGA Sentences

Files that make up the GGA Sentence generation program are:
  1. Runner.cpp (contains the main function)
  2. GGASimulator.cpp (contains a class that does the generation)
  3. GGASimulator.h (contains the class declaration of the class in GGASimulator.cpp)


Compiling and Running the programs
----------------------------------
Running runSimulation.sh on linux will automatically:
  1. compile both the generator program and the processing script
  2. run the generator program to obtain a random GGA sentence
  3. escape special characters in the generated GGA sentence
  4. pass the clean GGA sentence to the processing script that then does the processing and outputs the result

You can however manually compile the GGA sentence generation program by running on console
   
    g++ -std=c++11 -o ggagenerator Runner.cpp GGASimulator.cpp

You can also manually compile the GGA sentence processor by running on console
   
    g++ -std=c++11 -o ggaprocessor GGAProcessor.cpp

To generate a random GGA sentence run (ofcourse after you have compiled the GGA sentence generator):

    ./ggagenerator

To process a GGA sentence run:
   
    ./ggaprocessor <GGA Sentence with bash special characters escaped>
