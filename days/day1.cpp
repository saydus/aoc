/*
 * PROBLEM 1
 */

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <list>

const std::string INPUT_DIRECTORY = "../inputs/";

void solution1(){
    std::ifstream file(INPUT_DIRECTORY + "input1.txt");
    assert(file.is_open());

    int target = 2020;
    std::unordered_map<int, int> subToNum;

    std::string numStr;
    while(getline(file, numStr)){
        int num = std::stoi(numStr);
        if (subToNum.find(num) != subToNum.end()){
            std::cout << "Solution 1: " << subToNum[num] * num << std::endl;
            break;
        }
        else{
            subToNum[target - num] = num;
        }
    }
}
