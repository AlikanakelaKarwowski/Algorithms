/***
prepared for CS435 Project 1 part 2
**/

#include <string.h>
#include <iostream>
#include <fstream>
#include "sha256.h"
#include "BigIntegerLibrary.hh"


int main(int argc, char *argv[])
  {
    if ((argc != 4 && argc != 3) || (argv[1][0]!='s' && argv[1][0]!='v'))
      std::cout << "wrong format! should be \"a.exe s filename\"\n";
    else {
      std::string filename = argv[2];

      //read the file
      std::streampos begin,end;
      std::ifstream myfile (filename.c_str(), std::ios::binary);
      begin = myfile.tellg();
      myfile.seekg (0, std::ios::end);
      end = myfile.tellg();
      std::streampos size = end-begin;
      //std::cout << "size of the file: " << size << " bytes."; //size of the file

      myfile.seekg (0, std::ios::beg);
      char * memblock = new char[size];
      myfile.read (memblock, size); //read file; it's saved in the char array memblock
      myfile.close();

      std::string copyOFfile = filename+".Copy";
      std::ofstream myfile2 (copyOFfile.c_str(), std::ios::binary);
      myfile2.write (memblock, size); //write to a file
      myfile2.close();

      //std::cout<<memblock;

      if (argv[1][0]=='s')
      {
        std::cout << "Need to sign the doc.\n";

        //make hash
        std::string sha256Hash = sha256(memblock);
        //convert from from base 16 to base 10
        BigUnsignedInABase shaBase16 = BigUnsignedInABase(sha256Hash, 16);
        //save as originalMessage
        BigUnsigned originalMessage = shaBase16;

        //open up the d_n.txt
        std::fstream d_n("d_n.txt", std::fstream::in | std::fstream::out);
        std::string temp;

        //read the first line into the temp string
        d_n >> temp;
        //convert from string to big unsigned
        BigUnsigned bigD = stringToBigUnsigned(temp);
        temp = "";
        //read second line into temp string
        d_n >> temp;
        //convert from string to big unsigned
        BigUnsigned bigN = stringToBigUnsigned(temp);

        //do modexp to get the signature
        BigUnsigned signature = modexp(originalMessage,bigD,bigN);

        //create file signature
        std::ofstream sign;
        sign.open( filename + ".signature");
        sign << signature;
        sign.close();
        std::cout << "Message is signed.\n";
        std::cout << "Please use the \'v\' flag and \"" << filename << ".signature\" to verify authenticity\n";
      }
      else if (argv[1][0] =='v') {
        std::cout <<"Need to verify the doc.\n";

        //make hash
        std::string sha256Hash = sha256(memblock);
        //convert from from base 16 to base 10
        BigUnsignedInABase shaBase16 = BigUnsignedInABase(sha256Hash, 16);
        //save as originalMessage
        BigUnsigned originalMessage = shaBase16;

        //open up the e_n.txt file
        std::fstream e_n("e_n.txt", std::fstream::in | std::fstream::out);
        std::string temp;

        //read the first line into the temp string
        e_n >> temp;
        //convert from string to big unsigned
        BigUnsigned bigE = stringToBigUnsigned(temp);
        temp = "";

        //read second line into temp string
        e_n >> temp;
        //convert from string to big unsigned
        BigUnsigned bigN = stringToBigUnsigned(temp);
        e_n.close();

        //open signature file
        std::fstream sign;
        std::string signatureKey;
        sign.open(argv[3]);
        //read the signature from file
        sign >> signatureKey;
        sign.close();

        //convert string to BigUnsigned
        BigUnsigned signature = stringToBigUnsigned(signatureKey);

        //decrypt the signature key
        BigUnsigned decrypt = modexp(signature,bigE,bigN);

        //check to see if the signature key is the same or if the file has been modified
        if(originalMessage == decrypt)
        {
          std::cout << "Document is Authentic.\n";
        }
        else
        {
          std::cout << "Document is not Authentic.\n";
        }
      }
      delete[] memblock;
    }
  return 0;
  }
