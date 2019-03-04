/*
 *        File: copy_file_extra_credit.cc
 *      Author: Meredith Wammes
 *        Date: March 04, 2019
 * Description: Demonstrate output streams using functions
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

//function prototypes

int main(int argc, char const *argv[]) {
    ifstream inStream;
    ofstream outStream;
    string inFileName, outFileName;
    cout << "Enter the input file name: ";
    cin >> inFileName;
    inStream.open(inFileName.c_str());
    //check for failure
    cout << "Enter the output file name: ";
    cin >> outFileName;
    outStream.open(outFileName.c_str());
    //check for failure
    char ch;
    inStream.get(ch);
    while(!inStream.eof()){
        outStream << ch;
        inStream.get(ch);
    }
    inStream.close();
    outStream.close();




    return 0;
}// main
