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

		//set the seed to get random numbers
		srand (time(NULL));

		//generate p and q
		BigUnsigned bigPP = createBig();
	  while (!isPrime(bigPP))
	  {
	      bigPP = createBig();
	  }

		//print out results to verify correct operations have occurred
		std::cout << "bigPP:\n" << bigPP;
	  std::cout << std::endl;

		BigUnsigned bigPQ = createBig();
	  while (!isPrime(bigPQ))
	  {
	      bigPQ = createBig();
	  }

		//print out results to verify correct operation have occurred
	  std::cout << "bigPQ:\n" << bigPQ;
	  std::cout << std::endl;

		//write the prime number p and q to file, then close the file
		p_q.open("p_q.txt");
		p_q << bigPP << '\n' << bigPQ;
		p_q.close();

		BigUnsigned bigN = BigUnsigned(bigPP*bigPQ);
		std::cout <<"BigN:\n" << bigN << std::endl;

		BigUnsigned phiN = (bigPP-1)*(bigPQ-1);
		std::cout <<"PhiN:\n" << phiN << std::endl;

		BigUnsigned bigE = BigUnsigned(rand() % 999 + 100);

		//find a valid big E for coprimes
		int failsafe = 0;
		while(true)
		{
			if(gcd(bigE,phiN)!=1)
				bigE +=1;

			failsafe++;

			if(failsafe >=1000)
			{
				std::cout << "WARNING No Coprimes"<<std::endl;
				break;
			}

			if(gcd(bigE,phiN) == 1)
				break;
		}

		std::cout << "BigE:\n" << bigE << std::endl;

		BigUnsigned bigD = modinv(bigE, phiN);
    std::cout << "bigD:\n" << bigD << std::endl;
    BigUnsigned modInv= bigD * bigE;
    BigUnsigned remainder2;
    modInv.divideWithRemainder(phiN, remainder2);
    std::cout << "modInverse:\n" << modInv << std::endl << std:: endl;

		e_n.open("e_n.txt");
		e_n << bigE << '\n' << bigN;
		e_n.close();

		d_n.open("d_n.txt");
		d_n << bigD << '\n' << bigN;
		d_n.close();

	} catch(char const* err) {
		std::cout << "The library threw an exception:\n"<< err << std::endl;
	}
	return 0;
}
BigUnsigned createBig()
{
	// get random BigUnsigned int >= 512 bits
	 BigUnsigned bigInt512 = BigUnsigned(1);
	 while (bigInt512.bitLength() < 512)
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
