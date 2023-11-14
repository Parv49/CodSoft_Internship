#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
int countWords(const std::string &filename) {
    std::ifstream file(filename);
    std::string line;
    int wordCount = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string word;
            while (iss >> word) {
                wordCount++;
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
    return wordCount;
}
int main() {
    std::string filename;
    std::cout << "Enter the file name: ";
    std::cin >> filename;
    int wordCount = countWords(filename);
    std::cout << "Total word count in the file: " << wordCount << std::endl;
    return 0;
}