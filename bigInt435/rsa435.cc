// You need to complete this program for a part of your first project.

// Standard libraries
#include <string>
#include <iostream>
#include <stdlib.h>

//librarys added to meet project requirements
#include <time.h>
#include <fstream>

// 'BigIntegerLibrary.hh' includes all of the library headers.
#include "BigIntegerLibrary.hh"

bool isPrime(BigUnsigned&);
BigUnsigned createBig();
int main(){

	/* The library throws 'const char *' error messages when things go
	 * wrong.  It's a good idea to catch them using a 'try' block like this
	 * one.  Your C++ compiler might need a command-line option to compile
	 * code that uses exceptions. */
	try
	{
		std::ofstream p_q, e_n, d_n;
		p_q.open("p_q.txt");

		//set the seed to get random numbers
		srand (time(NULL));

		BigUnsigned bigPP = createBig();
	  while (!isPrime(bigPP))
	  {
	      bigPP = createBig();
	  }
		std::cout << "bigPP:\n" << bigPP;
	  std::cout << std::endl << std::endl;

		p_q << bigPP << '\n';

		BigUnsigned bigPQ = createBig();
	  while (!isPrime(bigPQ))
	  {
	      bigPQ = createBig();
	  }
	  std::cout << "bigPQ:\n" << bigPQ;
	  std::cout << std::endl << std::endl;

		p_q << bigPQ << '\n';

	} catch(char const* err) {
		std::cout << "The library threw an exception:\n"
			<< err << std::endl;
	}


	return 0;
}
BigUnsigned createBig()
{
	// get random BigUnsigned int >= 512 bits
	 BigUnsigned bigInt512 = BigUnsigned(1);
	 while (bigInt512.bitLength() < 10)
	 {
			 bigInt512 = bigInt512*10 +rand();
	 }
	 return bigInt512;
}

bool isPrime(BigUnsigned& bigInt){
    // the a value in Fermat's test - (a ^ ( p - 1)) % p
    BigInteger aValue1 = 2, aValue2 = 3;

    // perform Fermat's test
    BigUnsigned remainder1 = modexp(aValue1, (bigInt - 1), bigInt);
    BigUnsigned remainder2 = modexp(aValue2, (bigInt - 1), bigInt);

    // if both remainders are 1, then Fermat's test is true / passed - number is prime
    if ((remainder1 == 1) && (remainder2 == 1))
        return true;
    else
        return false;
}
