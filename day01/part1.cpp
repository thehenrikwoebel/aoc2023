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

int getnumber(string text) {
    string out = "";
    string temp;
    for(int i = 0; i < text.length();++i) {
        if(isdigit(text[i])) {
            out += text[i];
        }
    }
    if(out.length() < 2) {
        out += out[0];
    } else if(out.length() > 2) {
        temp = out;
        out = out[0];
        out += temp[temp.length() - 1];
    }
    return stoi(out);
}

int getSumOfNumbers(vector<string> file) {
    int out = 0;
    file.shrink_to_fit();
    for(int i = 0; i < file.size();++i) {
        out += getnumber(file[i]);
    }
    cout << out << endl;
    return out;
}

int main() {
    vector<string> lines;
    lines = readFile("input.txt");
    getSumOfNumbers(lines);
    return 0;
}

