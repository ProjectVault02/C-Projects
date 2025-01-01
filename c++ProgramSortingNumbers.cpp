//
//  main.cpp
//  NEWsortingNumbers(afterUPDATED)
//
//  Created by Jasmine Algama on 8/15/24.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    //Declare 10 separate float variables
    float num1, num2, num3, num4, num5, num6, num7, num8, num9, num10;
    
    //Vector to store numbers temporarily:
    vector<float> numbers;
    
    //Open the file for reading!
    ifstream inputFile("/Users/jasminealgama/Desktop/floats.txt");
    if(!inputFile){
        cerr << "Error: could not open the input file for reading. " << endl;
        return 1;
    }
    
    //Read the file line by line.
    string line;
    while(getline(inputFile, line)){
        //Skip lines when starting with '#'comments
        if (line.empty() || line[0] == '#'){
            continue;
        }
        
        //Use stringstream to parse the line
        stringstream ss(line);
        string dummy;
        float value;
        
        //Read the variable name and the float value
        ss >> dummy >> value;
        
        //Add the value to the vector;
        numbers.push_back(value);
    }
        //Close the input file afater reading:
        inputFile.close();
        
        //Make sure 10 numbers are read:
        if(numbers.size() != 10){
            cerr << "Error: Expected 10 numbers but found " << numbers.size() << ". ";
            return 1;
        }
        
        //Sort the numbers from greatest to least
        sort(numbers.begin(), numbers.end(), greater<float>());
        
        //Open the ouput file for writing
        ofstream outputFile("/Users/jasminealgama/Desktop/sortedFloats.txt");
        if(!outputFile){
            cerr << "Error: could not open the output file for writing." << endl;
            return 1;
        }
        //Write the sorted numbers to the output file with their variable names
        for(size_t i = 0; i < numbers.size(); ++i){
            outputFile << "num" << (i + 1) << " " << numbers[i] << endl;
        }
        //Ensure the output file is properly flushed and closed
        outputFile.flush();
        outputFile.close();
        
        if(outputFile.fail()){
            cerr<< "Error: Failed to write to the output file. " << endl;
            return 1;
        }
    
    //Print the sorted numbers to the screen:
    cout << "The sorted numbers (from greatest to least) are: " << endl;
    for (size_t i = 0; i < numbers.size(); ++i) {
        cout << "num " << (i + 1) << " " << numbers[i] << endl;
    }
    return 0;
}
