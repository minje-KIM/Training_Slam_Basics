//  General C++ Code
//  Compile this code using CMake.
//  We will gonna make CMakeLists.txt file.
#include <iostream>
#include "lib_1.h"
#include "lib_2.h"

using namespace std;

int main(int argc, char **argv)
{
    cout << "This is the Main Part" << endl;
    cout << "Hello World!" << endl;
    cout << "MY name is Minje KIM!" << endl;
    cout << "I'm Really Interested in SLAM" << endl;
    cout << endl;

    Func_lib1();
    Func_lib2();

    return 0;
}