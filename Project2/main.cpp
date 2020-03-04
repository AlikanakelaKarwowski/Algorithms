#include <iostream>


int main(int argc, char* argv[])
{
    std::cout << "Number of arguments=" << argc << std::endl;
    if (argc !=3)
        std::cout << "Incorrect number of arguments.\nFormat should be \"cHull.exe G test.txt\"" << std::endl;
    if (*argv[2] == 'G')
    {

    }
}
