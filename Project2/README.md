# Algorithms Project 2

* The zipped file contains 4 files labeled *convexHull435.cpp*, *ConvexHull_GUI.java*, *Makefile*, *README.md* and a folder labeled *output*

* **Do not modify these files or folders unless you want to run them using your own makefile**

## convexHull435.cpp:

* To run the program, in a terminal type `make`
* Once it is done type `make runJ` or `make runG` or `make runQ` to run the program with the appropriate Algorithm.
* It may take a while to run **ALL** the datasets for an Algorithm but please be patient.

* The program should generate a file for each datafile in the *output/[Algorithm]/* folder that shows the time it took to run the algorithm on specific types of data sets.
* These files are called *test_[Algorithm]_[Data File Name].txt*

This folder contains the program to generate very large Prime numbers. It creates a random large integer (using BigUnsigned to allow large numbers) of 512 bits long. It then uses Fermat's Little Theorem to test for primality using the number 2 and 3. P and Q are then stored in the file called "p_q.txt"

Next once 2 prime numbers P and Q are found, the program find N and phi(N). To find N it multiplies P and Q together, and to find phi(N) it multiply (P-1) and (Q-1) together.

Next the program find creates a BigUnsigned E, that starts at a random number between 100 and 999. It then checks the to see if E is a coprime of phi(N) by determining if the greatest common denomenator between the two numbers is 1. If its not the program adds 1 to E, and checks again until a valid E is found.

Finally the program finds D, by using the modulus inverse (using function modinv) of E and phi(N). It then saves the values of D and N into file "d_n.txt" and the values of E and N into the file of "e_n.txt"


For part 2 of the project, make sure you copy the files "d_n.txt" and "e_n.txt" into the messageDigest435 folder.


Project1Part2:
To run this program, in terminal type "make" then type "./messageDigest435 s file.txt" where file.txt is the file you would like to sign.

Then type "./messageDigest435 v file.txt file.txt.signature" where file.txt is replaced with the name of the file you signed the first one, and file.txt.signature if replaced by the filename of the file you signed previously but with .signature at the end of it.

If the files are not modified from signing and verifying then it will return authentic, and if they are modified it will return not authentic.

This folder contains the sha256 implementation as well as the signing and verification implementation. The signing portion of the program takes the contents of the file and passes it into the sha256 function to make a base 16 hash of the content. Then the base 16 hash is converted to base 10, and then we take the modulus inverse (modinv function) using the base 10 hash, D (read from the file in part 1) and N (also read from part 1). This value is then stored into the filename.signature file for checking against later (default file name is  "file.txt.signature").

The verification part does everything the signing part does up until the modulus inverse is done. From there it reads the signature into a variable and takes the modulus inverse of the signature, E (read from file) and N (also read from file). This value is then compared to the value of the hash taken of the file. If the values match then the file is authentic, if they dont match then the file has been modified or changed from the original.



Perform a make clean in both directories when done to delete all unneeded object, and text files created during the proccess.
