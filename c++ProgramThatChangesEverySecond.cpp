#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <thread>

// Function to generate a random double within a range
double randomDouble(double min, double max) {
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_real_distribution<> dis(min, max); // Define the range
    return dis(gen);
}

// Function to update the variable values in a file
void updateValuesInFile(const std::string& filename) {
    // Generate random values for V1 and V2 such that V1 < V2
    double V1 = randomDouble(0.0, 50.0);
    double V2 = randomDouble(V1 + 1.0, 100.0);  // Ensure V2 is always greater than V1

    // Generate a random value for A0 such that 3 < A0 < 15
    double A0 = randomDouble(3.0, 15.0);

    // Generate random values for T, S, and A1
    double T = randomDouble(0.0, 100.0);
    double S = randomDouble(0.0, 100.0);
    double A1 = randomDouble(0.0, 100.0);

    // Open the file for writing
    std::ofstream outfile(filename);
    if (!outfile) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    // Write the variable values to the file
    outfile << "V1: " << V1 << std::endl;
    outfile << "V2: " << V2 << std::endl;
    outfile << "T: " << T << std::endl;
    outfile << "S: " << S << std::endl;
    outfile << "A1: " << A1 << std::endl;
    outfile << "A0: " << A0 << std::endl;

    // Close the file
    outfile.close();
    std::cout << "Updated values in file: V1 = " << V1 << ", V2 = " << V2 << ", T = " << T << ", S = " << S << ", A1 = " << A1 << ", A0 = " << A0 << std::endl;
}

int main() {
    const std::string filename = "/Users/jasminealgama/Desktop/helloworld.txt";

    while (true) {
        // Update the variable values in the file
        updateValuesInFile(filename);

        // Wait for 5 seconds
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    return 0;
}

