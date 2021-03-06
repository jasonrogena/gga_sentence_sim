#!/bin/sh
## compile the program responsible with generating the GGA sentences
### note that c++ 11 is used because of the function std::to_string requires this version
echo " - compiling program responsible for generating GGA sentences (Runner.cpp and GGASimulator.cpp)"
g++ -std=c++11 -o ggasimulator Runner.cpp GGASimulator.cpp

## compile the script responsible for processing the GGA sentences
echo " - compiling script responsible for processing GGA sentences (GGAProcessor.cpp)"
g++ -std=c++11 -o ggaprocessor GGAProcessor.cpp


echo " - running the program responsible for generating GGA sentences and passing the output to the script responsible for processing GGA sentence"

## starting the endless loop
while :
do
	printf "\n\n\n\n-------------- START OF NEW OUTPUT --------------\n\n"
	
	## run the program responsible for generating the GGA sentences and asign its ouput to the variable
	ggaSentence=$(./ggasimulator | sed -e "s/\\$/\\\\\$/g;s/\\,/\\\\\,/g;s/\\./\\\\\./g;s/\\-/\\\\\-/g;s/\\*/\\\\\*/g")


	## pass the GGA Sentence to the script responsible for analyzing it
	echo $ggaSentence | xargs ./ggaprocessor
	
	printf "\n\n---------------- END OF OUTPUT --------------\n\n"
	read -t 5 -p "Hit [ENTER] or wait five seconds to continue. Hit [Ctrl+C] to stop simulation"
done
