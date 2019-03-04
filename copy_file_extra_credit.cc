/*
 *        File: copy_file_extra_credit.cc
 *      Author: Meredith Wammes
 *        Date: March 04, 2019
 * Description: Demonstrate output streams using functions and
 *              getline command
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

//function prototypes
string getInFileName ();
string getOutFileName ();
void copy (ifstream &inStream, ofstream &outStream);

int main(int argc, char const *argv[]) {
    ifstream inStream;
    ofstream outStream;
    string inFileName;
    string outFileName;

    inFileName = getInFileName ();
    inStream.open(inFileName.c_str());
        if (inStream.fail()){
            cout << "Error: File name " << inFileName << " does not exist" << endl;
            exit (1);
        }
    outFileName = getOutFileName ();
    outStream.open(outFileName.c_str());
        if (outStream.fail()){
            cout << "Error: File name " << outFileName << " does not exist" << endl;
            exit (1);
        }
    copy (inStream, outStream);

    inStream.close();
    outStream.close();

    return 0;
}// main

    // Get the Input File Name
    string getInFileName (){
        ifstream inStream;
        string inFileName;
        cout << "Enter the input file name: ";
        cin >> inFileName;
        return (inFileName);
    }

    // Get the Input File Name
    string getOutFileName (){
        ifstream outStream;
        string outFileName;
        cout << "Enter the output file name: ";
        cin >> outFileName;
        return (outFileName);
    }

    // Copy Input to Output    
    void copy (ifstream &inStream, ofstream &outStream){
        string word;
        getline (inStream, word);

        while(!inStream.eof()){
            outStream << word;
            getline (inStream, word);
        }
    }