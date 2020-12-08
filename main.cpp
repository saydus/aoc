#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <list>
#include <vector>
#include <unordered_set>
#include <set>

const std::string INPUT_DIRECTORY = "../inputs/";


void parseEdges(std::string edge, std::string& outcomingNode, std::vector<std::string>& incomingNodes){
    outcomingNode = edge.substr(0, edge.find("bags") - 1);
    std::string incomingString = edge.substr(edge.find("bags contain ") + 13);

    if (incomingString != "no other bags."){
        std::string currentStr = "";

        for (int i = 0; i < incomingString.size(); ++i) {
            if (incomingString[i] == ',' || incomingString[i] == '.'){
                incomingNodes.push_back(currentStr.substr(0, currentStr.find(" bag")));
                currentStr = "";
                ++i;
            }
            else if(isdigit(incomingString[i])){
                currentStr = "";
                ++i;
            }
            else{
                currentStr += incomingString[i];
            }
        }
    }

}

void addAllNodes(std::unordered_set<std::string>& bagsOfTarget, std::string target, std::unordered_map<std::string, std::set<std::string>>& adjacencyList){
    if (adjacencyList[target].size() != 0){
        for (auto i : adjacencyList[target]) {
            int initialSize = bagsOfTarget.size();
            bagsOfTarget.insert(i);
            // If we haven't yet explored it, recurse
            if (bagsOfTarget.size() > initialSize){
                addAllNodes(bagsOfTarget, i, adjacencyList);
            }
        }
    }
}

void solution7(){
    std::string target = "shiny gold";


    std::ifstream file(INPUT_DIRECTORY + "input7.txt");

    // Parse the input into an adjacency list
    std::unordered_map<std::string, std::set<std::string>> adjacencyList;
    std::string edge;
    if (file.is_open())
    {
        while ( getline (file,edge) )
        {
            // Parse the edge of the graph in reverse order for traversal
            std::string outcomingNode;
            std::vector<std::string> incomingNodes;
            parseEdges(edge, outcomingNode, incomingNodes);

            for (auto i : incomingNodes) {
                adjacencyList[i].insert(outcomingNode);
            }
        }
        file.close();
    }
    else {
        std::cout << "Unable to open file";
    }

    std::unordered_set<std::string> bagsOfTarget;
    addAllNodes(bagsOfTarget, target, adjacencyList);

    std::cout << "Solution 7: " << bagsOfTarget.size() << std::endl;
}




void solution1(){
    std::ifstream file(INPUT_DIRECTORY + "input1.txt");
    int target = 2020;
    std::unordered_map<int, int> subToNum;
    int answer;

    if (file.is_open()){
        std::string numStr;
        while(getline(file, numStr)){
            int num = std::stoi(numStr);
            if (subToNum.find(num) != subToNum.end()){
                answer = subToNum[num] * num;
                break;
            }
            else{
                subToNum[target - num] = num;
            }
        }
    } else{
        std::cout << "Unable to open file";
    }

    std::cout << "Solution 1: " << answer << std::endl;
}

int main() {
    std::cout << "Solutions to AOC 2020!" << std::endl;
    solution1();
    solution7();


    return 0;
}
