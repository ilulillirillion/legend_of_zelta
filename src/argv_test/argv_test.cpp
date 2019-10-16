// Name of program: argv_test 
// Ported from https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/
#include <iostream> 
  
int main(int argc, char** argv) 
{ 
	std::cout << "You have entered " << argc 
		<< " arguments:" << "\n"; 

	for (int i = 0; i < argc; ++i) 
		std::cout << argv[i] << "\n"; 

	return 0; 
} 
