#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;

struct Asterics {
    int line;
    int index;
};

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

vector<Asterics> getAsterics(vector<string> file) {
    file.shrink_to_fit();
    string number1 = "";
    string number2 = "";
    vector<Asterics> out;
    Asterics temp;
    for(int i = 0; i < file.size();++i) {
        for(int j = 0; j < file[i].length();++j) {
            if(file[i][j] == '*') {
                temp.line = i;
                temp.index = j;
                out.push_back(temp);
            }
        }
    }
    return out;
}

string getNumber(int line,int index, vector<string> file) {
    string out = "";
    int it = 0;
    for(int i = index; isdigit(file[line][i]);--i) {
        ++it;
    }
    while(isdigit(file[line][index - it])) {
        out += file[line][index - it];
        ++it;
    }
    cout << out << endl;
    return out;
}

vector<int> getNumbers(vector<Asterics> indices, vector<string> file) {
    indices.shrink_to_fit();
    file.shrink_to_fit();
    vector<int> out;
    for(int i = 0; i < indices.size();++i) {
        if(isdigit(file[indices[i].line][indices[i].index - 1])) {
                
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
    //getSum(getNumbersinLine(lines));
    getNumber(0, 9, lines);
    return 0;
}