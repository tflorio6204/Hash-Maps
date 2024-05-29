// Name: Thomas Florio

#include <iostream>
#include "makeModel.hpp"
#include <time.h>
#include <stdlib.h>

using namespace std;
int main() {
	srand(time(NULL));
	
	// Choose one of the 2 blocks to uncomment, depending on which input file
	// you'd like to run your hashmap on
	
	// Dr. Seuss input

	makeModel voice1("C:\\Users\\Tommy\\CLionProjects\\HashMaps\\HashMapProject\\DrSeuss.txt","C:\\Users\\Tommy\\CLionProjects\\HashMaps\\HashMapProject\\Seussout1.txt",true,true);
	makeModel voice2("C:\\Users\\Tommy\\CLionProjects\\HashMaps\\HashMapProject\\DrSeuss.txt","C:\\Users\\Tommy\\CLionProjects\\HashMaps\\HashMapProject\\Seussout2.txt",false,true);
	makeModel voice3("C:\\Users\\Tommy\\CLionProjects\\HashMaps\\HashMapProject\\DrSeuss.txt","C:\\Users\\Tommy\\CLionProjects\\HashMaps\\HashMapProject\\Seussout3.txt",true,false);
    makeModel voice4("C:\\Users\\Tommy\\CLionProjects\\HashMaps\\HashMapProject\\DrSeuss.txt","C:\\Users\\Tommy\\CLionProjects\\HashMaps\\HashMapProject\\Seussout4.txt",false,false);
	
	// OR
	
	// Great Expectations input
	//makeModel voice5("C:\\Users\\Tommy\\CLionProjects\\HashMaps\\HashMapProject\\GEChap.txt","C:\\Users\\Tommy\\CLionProjects\\HashMaps\\HashMapProject\\GEout1.txt",true,true);
	//makeModel voice6("C:\\Users\\Tommy\\CLionProjects\\HashMaps\\HashMapProject\\GEChap.txt","C:\\Users\\Tommy\\CLionProjects\\HashMaps\\HashMapProject\\GEout2.txt",false,true);
	//makeModel voice7("C:\\Users\\Tommy\\CLionProjects\\HashMaps\\HashMapProject\\GEChap.txt","C:\\Users\\Tommy\\CLionProjects\\HashMaps\\HashMapProject\\GEout3.txt",true,false);
	//makeModel voice8("C:\\Users\\Tommy\\CLionProjects\\HashMaps\\HashMapProject\\GEChap.txt","C:\\Users\\Tommy\\CLionProjects\\HashMaps\\HashMapProject\\GEout4.txt",false,false);

	return 0;
}
