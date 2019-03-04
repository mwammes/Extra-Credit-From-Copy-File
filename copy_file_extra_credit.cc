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
//************************************************************
// Function: getInFileName ()
//
// Purpose: Have user enter input file name
//
// Parameters: 
//
// Pre Conditions: file name user enters is a valid string
//
// Post Conditions: returns the input file name string
//************************************************************
// Function: getOutFileName ()
//
// Purpose: Have user enter output file name
//
// Parameters: 
//
// Pre Conditions: file name user enters is a valid string
//
// Post Conditions: returns the output file name string
//************************************************************
// Function: copy (ifstream &inStream, ofstream &outStream)
//
// Purpose: Copy the contents from inStream to outStream
//
// Parameters: &inStream - reads and operates on file entered
//             &outStream - creates and modifies file entered
//
// Pre Conditions: &inStream and &outStream are files that can be
//                 opened and operated on
//
// Post Conditions: Creates the outStream file
//************************************************************


int main(int argc, char const *argv[]) {
//Initialization  
    ifstream inStream;
    ofstream outStream;
    string inFileName;
    string outFileName;

    inFileName = getInFileName ();
    inStream.open(inFileName.c_str());
        if (inStream.fail()){ // For errors opening
            cout << "Error: File name " << inFileName << " does not exist" << endl;
            exit (1);
        }
    outFileName = getOutFileName ();
    outStream.open(outFileName.c_str());
        if (outStream.fail()){ //For errors opening
            cout << "Error: File name " << outFileName << " does not exist" << endl;
            exit (1);
        }
    copy (inStream, outStream);

    inStream.close(); //always close your files
    outStream.close();

    return 0;
}// main

//Functions
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