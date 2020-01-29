// You need to complete this program for a part of your first project.

// Standard libraries
#include <string>
#include <iostream>
#include <stdlib.h>


// 'BigIntegerLibrary.hh' includes all of the library headers.
#include "BigIntegerLibrary.hh"

BigUnsigned createPrime();
bool isPrime(BigUnsigned);

int main(){
	/* The library throws 'const char *' error messages when things go
	 * wrong.  It's a good idea to catch them using a 'try' block like this
	 * one.  Your C++ compiler might need a command-line option to compile
	 * code that uses exceptions. */
	try {

      std::cout << "a couple of test cases for 3460:435/535 Algorithms!!!\n";
      BigUnsigned big1 = BigUnsigned(1);
      for (int i=0;i<400;i++) {
         big1 = big1*10 +rand();
      }
      std::cout << "\n\nmy big1 !!!\n";
      std::cout << big1;
      BigUnsigned big2 = BigUnsigned(1);
      for (int i=0;i<400;i++) {
         big2 = big2*10 +rand();
      }
      std::cout << "\n\nmy big2 !!!\n";
      std::cout << big2;
      std::cout << "\n\nmy big3 = big1*big2 !!!\n";
      BigUnsigned big3 = big1*big2;
      std::cout <<big3;
      std::cout << "\n\nmy big3/big2 !!!\n";
      std::cout <<big3/big2;
			std::cout <<'\n';

			BigUnsigned small = BigUnsigned(big1);
			BigUnsigned expo = BigUnsigned(big2-1);
			BigUnsigned modulo = BigUnsigned(big2);
			BigUnsigned BigD = modexp(small, expo, modulo);
			if(BigD == 1)
			std::cout <<"Is a prime\n" << BigD << std::endl;
			else
				std::cout << "Not Prime D\n" << BigD<< std::endl;

	} catch(char const* err) {
		std::cout << "The library threw an exception:\n"
			<< err << std::endl;
	}

	return 0;
}

BigUnsigned createPrime()
{
	int timeout = 0;
	BigUnsigned big1 = BigUnsigned(1);
	for (int i=0;i<512;i++)
		 big1 = big1*10 +rand();
	while(true)
	{
		if(isPrime(big1))
			break;

		timeout += 1;

		if(timeout <30)
		{
			std::cout << "Still working, tried 30 iterations of generating a prime number. Please be patient."<< std::endl;
			timeout = 0;
		}
		big1 += 101;
	}
	return big1;
}
bool isPrime(BigUnsigned bigD)
{
	auto d = generateBigD(bigD);
	if (modexp(bigD, (big - 1), big)) == 1)
}
