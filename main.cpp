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



int simulate(vector<pair<string, int>> & program){
    int accum = 0;
    set<int> visitedLines;

    for (int i = 0; i < program.size(); ++i) {
        if (visitedLines.find(i) != visitedLines.end()){
            return 0;
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

    return accum;
}


void solution8(){
    std::ifstream file(INPUT_DIRECTORY + "input8.txt");
    assert(file.is_open());

    vector<pair<string, int>> program;
    string line;
    while(getline(file, line)){
        program.push_back({line.substr(0, line.find(' ')), stoi(line.substr(line.find(' ') + 1))});
    }

    for (int i = 0; i < program.size(); ++i) {
        string command = program[i].first;

        if (program[i].first  == "jmp"){
            program[i].first = "nop";
            int accum = simulate(program);
            if (accum != 0){
                cout << "Solution: " << accum;
            }
            program[i].first = "jmp";
        }

        else if (program[i].first  == "nop"){
            program[i].first = "jmp";
            int accum = simulate(program);
            if (accum != 0){
                cout << "Solution: " << accum;
            }
            program[i].first = "nop";
        }

    }

}







int main() {
    solution8();
    return 0;
}
