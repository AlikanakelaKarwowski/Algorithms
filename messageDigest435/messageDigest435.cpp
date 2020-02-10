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

      std::cout<<memblock;

      if (argv[1][0]=='s') {
         std::cout << "\n"<<"Need to sign the doc.\n";
         //make hash function

         std::string sha256Hash = sha256(memblock);
         BigUnsignedInABase shaBase16 = BigUnsignedInABase(sha256Hash, 16);
         BigUnsigned shaBase10 = shaBase16;

         //open up the file generated in
         std::fstream d_n("..\\messageDigest435\\d_n.txt", std::fstream::in | std::fstream::out);
         std::string temp;
         d_n >> temp;
         BigUnsigned bigD = stringToBigUnsigned(temp);
         d_n >>temp;
         BigUnsigned bigN = stringToBigUnsigned(temp);

         BigUnsigned signature = modexp(shaBase10,bigD,bigN);
         std::ofstream signed;
         signed.open("file.txt.signature");
         signed << signature;
         signed.close();
         std::cout << "Message is signed.";
      }
      else {
         std::cout << "\n"<<"Need to verify the doc.\n";
         //.....

      }
      delete[] memblock;
    }
    return 0;
}
