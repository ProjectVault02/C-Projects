//
//  main.cpp
//  ThathaProject
//Created by JA on 7/12/24.
//The following program rounds numbers to significant digits.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

double roundToSigDigits(double value){
    if (value == 0.0) return 0.0;
    double absValue = abs(value);
    double sign = value/ absValue;
    double scale = pow(10, ceil(log10(absValue)) - 2);
    return sign * round(absValue/scale) * scale;
}
int main() {
    // insert code here...
   ifstream inFile("/Users/jasminealgama/Desktop/helloworld.txt");
    if(!inFile){
        cerr << "Unable to open file. " << endl;
        return 1;
    }
//variables to hold the values read from the file
    double v1 {0.0};
    double v2 {0.0};
    double s {0.0};
    double t {0.0};
    double a0 {0.0};
    double a1 {0.0};
    
    string line;
    while(getline(inFile, line)){
        istringstream iss(line);
        string varName;
        char eq;
        double value;
        
        if(iss >> varName >> eq >> value){
            if(eq == '='){
                if (varName == "v1") v1 = value;
                else if (varName == "v2") v2 = value;
                else if (varName == "s") s = value;
                else if (varName == "t") t = value;
                else if (varName == "a0") a0 = value;
                else if (varName == "a1") a1 = value;
            }
        }
    }

    inFile.close();
    
    v1 = roundToSigDigits(v1);
    cout << "v1 = " << v1 << endl;
    v2 = roundToSigDigits(v2);
    cout << "v2 = " << v2 << endl;
    s = roundToSigDigits(s);
    cout << "s = " << s << endl;
    t = roundToSigDigits(t);
    cout << "t = " << t << endl;
    a0 = roundToSigDigits(a0);
    cout << "a0 = " << a0 << endl;
    a1 = roundToSigDigits(a1);
    cout << "a1 = " << a1 << endl;
        
    
  //  if (outFile.is_open()){
  //      outFile << "Hello World!" << endl;
   //     outFile.close();
   // }else{
    //    cerr << "Unable to open file." << endl;
    //}
    return 0;
}
