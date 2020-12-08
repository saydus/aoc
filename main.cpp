#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <list>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

const string INPUT_DIRECTORY = "../inputs/";


/*
 * PROBLEM 2
 */

char parseInput(std::string inputLine, std::pair<int, int>& boundaries, std::string& password){
    int delimeterPos = inputLine.find('-');
    int spacePos = inputLine.find(' ');

    boundaries.first = std::stoi(inputLine.substr(0, delimeterPos));
    boundaries.second = std::stoi(inputLine.substr(delimeterPos + 1, spacePos - delimeterPos - 1 ));

    int secondSpace = inputLine.find(' ', spacePos + 1);
    password = inputLine.substr(secondSpace + 1);

    return inputLine[spacePos + 1];
}



void solution2(){
    std::ifstream file(INPUT_DIRECTORY + "input2.txt");
    assert(file.is_open());

    int answer = 0;

    std::string inputLine;
    while(getline(file, inputLine)){
        std::pair<int, int> boundaries;
        std::string password;
        char keyCharacter = parseInput(inputLine, boundaries, password);

        int count = std::count(password.begin(), password.end(), keyCharacter);

        if (count >= boundaries.first && count <= boundaries.second){
            ++answer;
        }
    }

    std::cout << "Solution to 2: " << answer << std::endl;
}








int main() {
    solution2();
    return 0;
}
