#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;

vector<string> readFile(string path) {
    vector<string> out;
    string line;
    ifstream file;
    file.open(path);
    if(file.is_open()) {
        while(getline(file, line)) {
            out.push_back(line);
        }
    }
    file.close();
    return out;
}

vector<int> getNumbersinLine(vector<string> file) {
    file.shrink_to_fit();
    string lastLine = "";
    string number = "";
    vector<int> numbers;
    vector<int> indices;
    vector<int> out;
    bool hasSymbol = false;
    for(int i = 0; i < file.size();++i) {
        for(int j = 0; j < file[i].length();++j) {
            if(isdigit(file[i][j])) {
                number += file[i][j];
                cout << number << endl;
                if(i < file.size() - 1) {
                    if(file[i+1][j] != '.' && !isdigit(file[i+1][j])) {
                        hasSymbol = true;
                        cout << "Hat ein Symbol unter sich" << endl;
                    }
                    if(j > 0) {
                        if(file[i+1][j-1] != '.' && !isdigit(file[i+1][j-1])) {
                            hasSymbol = true;
                            cout << "Hat ein Symbol unter sich" << endl;
                        }
                    }
                }
                if(j < file[i].length() - 1) {
                    if(file[i][j+1] != '.' && !isdigit(file[i][j+1])) {
                        out.push_back(stoi(number));
                        number = "";
                        cout << "Hat ein Symbol rechts neben sich" << endl;
                    }
                    if(i < file.size() - 1) {
                        if(file[i+1][j+1] != '.' && !isdigit(file[i+1][j+1])) {
                            hasSymbol = true;
                        }
                    }
                    if(i > 0) {
                        if(file[i-1][j+1] != '.' && !isdigit(file[i-1][j+1])) {
                            hasSymbol = true;
                        }
                    }
                }
                if(i > 0) {
                    if(file[i-1][j] != '.' && !isdigit(file[i-1][j])) {
                        hasSymbol = true;
                    }
                    if(j > 0) {
                        if(file[i-1][j-1] != '.' && !isdigit(file[i-1][j-1])) {
                            hasSymbol = true;
                        }
                    }
                }
                if(j > 0) {
                    if(file[i][j-1] != '.' && !isdigit(file[i][j-1])) {
                        hasSymbol = true;
                        cout << "Hat ein Symbol links neben sich" << endl;
                    }
                }
            } else {
                if(hasSymbol) {
                    out.push_back(stoi(number));
                    hasSymbol = false;
                    number = "";
                } else {
                    number = "";
                    cout << "Hat kein Symbol bei sich" << endl;
                }
            }   
        }
    }
    return out;
}

int getSum(vector<int> partnumbers) {
    int out = 0;
    partnumbers.shrink_to_fit();
    for(int i = 0; i < partnumbers.size();++i) {
        out += partnumbers[i];
    }
    cout << out << endl;
    return out;
}

int main() {
    vector<string> lines = readFile("input.txt");
    getSum(getNumbersinLine(lines));
    return 0;
}