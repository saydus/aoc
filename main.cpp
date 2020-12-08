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





void solution8(){
    std::ifstream file(INPUT_DIRECTORY + "input8.txt");
    assert(file.is_open());

    vector<pair<string, int>> program;
    string line;
    while(getline(file, line)){
        program.push_back({line.substr(0, line.find(' ')), stoi(line.substr(line.find(' ') + 1))});
    }

    int accum = 0;
    set<int> visitedLines;

    for (int i = 0; i < program.size(); ++i) {
        if (visitedLines.find(i) != visitedLines.end()){
            cout << accum << std::endl;
            break;
        }

        visitedLines.insert(i);
        string command = program[i].first;
        int argument  = program[i].second;

        if (command == "acc"){
            accum += argument;
        }
        else if (command == "jmp"){
            i += argument - 1;
        }
    }
}







int main() {
    solution8();
    return 0;
}
