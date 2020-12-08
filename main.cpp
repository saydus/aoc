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


bool isValid(){

}

void solution4(){
    vector<string> fields = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};

    ifstream file(INPUT_DIRECTORY + "input4.txt");
    assert(file.is_open());


    int validPassports = 0;
    string creds;
    std::string credentials;
    while(getline(file, credentials)){
        if(credentials == ""){
            bool valid = true;
            for (auto i : fields) {
                if (creds.find(i) == string::npos){
                    valid = false;
                } else{
//                    valid = isValid(creds[i]);
                }
            }
            if (valid) ++validPassports;
            creds.clear();
        }
        else {
            creds += credentials;
        }
    }

    cout << "Answer 4: " << validPassports << endl;
}



int main() {
    solution4();
    return 0;
}
