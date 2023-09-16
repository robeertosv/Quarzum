#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Error: Not enough arguments." << endl;
        return 1;
    }
    cout << "Hello world" << endl;
    cout << argv[1] << endl;
    return 0;
}