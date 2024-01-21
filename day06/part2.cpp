#include <iostream>
#include <vector>
#include <fstream>
#include <string>
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

vector<int> getDistances(vector<string> file) {
    file.shrink_to_fit();
    vector<int> out;
    string number = "";
    for(int i = 10; i < file[1].length();++i) {
        if(isdigit(file[1][i])) {
            number += file[1][i];
        } else if(number.length() > 0) {
            out.push_back(stoi(number));
            //cout << number << endl;
            number = "";
        }
    }
    out.push_back(stoi(number));
    //cout << number << endl;
    return out;
}

vector<int> getTimes(vector<string> file) {
    file.shrink_to_fit();
    vector<int> out;
    string number = "";
    for(int i = 0; i < file[0].length();++i) {
        if(isdigit(file[0][i])) {
            number += file[0][i];
        } else if(number.length() > 0) {
            out.push_back(stoi(number));
            //cout << number << endl;
            number = "";
        }
    }
    out.push_back(stoi(number));
    //cout << number << endl;
    return out;
}

long long addVector(vector<int> v) {
    v.shrink_to_fit();
    string out = "";
    for(int i = 0; i < v.size();++i) {
        out += to_string(v[i]);
    }
    cout << out << endl;
    return stoll(out);
}

long long calcPossibleWins(int time, long long distance) {
    long long distanceTraveled;
    long long velocity = 0;
    long long effectiveTime;
    long long out = 0;
    for(int i = 1; i < time;++i) {
        velocity = i;
        effectiveTime = time - i;
    	distanceTraveled = velocity * effectiveTime;
        if(distanceTraveled > distance) {
            ++out;
        }
    }
    cout << to_string(out) << endl;
    return out;
}

int main() {
    vector<string> input = readFile("input.txt");
    vector<int> times = getTimes(input);
    vector<int> distances = getDistances(input);
    int t = addVector(times);
    long long d = addVector(distances);
    calcPossibleWins(t, d);
    return 0;
}