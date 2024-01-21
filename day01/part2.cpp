#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <unordered_map>
#include <chrono>
using namespace std;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;

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
    string temp = "";
    string temp2 = "";
    string temp3 = "";
    unordered_map<string, string> spelledToDigit;
    spelledToDigit["one"] = "1";
    spelledToDigit["two"] = "2";
    spelledToDigit["three"] = "3";
    spelledToDigit["four"] = "4";
    spelledToDigit["five"] = "5";
    spelledToDigit["six"] = "6";
    spelledToDigit["seven"] = "7";
    spelledToDigit["eight"] = "8";
    spelledToDigit["nine"] = "9";
    for(int i = 0; i < text.length();++i) {
        if(isdigit(text[i])) {
            out += text[i];
            break;
        }
        if(i > 1) {
            temp += text[i-2];
            temp += text[i-1];
            temp += text[i];
        }
        if(i > 2) {
            temp2 += text[i-3];//f
            temp2 += text[i-2];//i
            temp2 += text[i-1];//v
            temp2 += text[i];  //e
        }
        if(i > 3) {
            temp3 += text[i-4];//e
            temp3 += text[i-3];//f
            temp3 += text[i-2];//i
            temp3 += text[i-1];//v
            temp3 += text[i];  //e
        }
        if(i > 1 && spelledToDigit.find(temp) != spelledToDigit.end()) {
            out += spelledToDigit.at(temp);
        }
        if(i > 2 && spelledToDigit.find(temp2) != spelledToDigit.end()) {
            out += spelledToDigit.at(temp2);
        }
        if(i > 3 && spelledToDigit.find(temp3) != spelledToDigit.end()) {
            out += spelledToDigit.at(temp3);
        }
        temp = temp2 = temp3 = "";
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
    auto start =
      duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    getSumOfNumbers(lines);
    auto end =
      duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    double clock = end-start;
    cout << end-start;
    return 0;
}

