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

int calcPossibleWins(int time, int distance) {
    int distanceTraveled;
    int velocity = 0;
    int acceleration = 1;
    int effectiveTime;
    int out = 0;
    for(int i = 1; i < time;++i) {
        velocity = i * acceleration;
        effectiveTime = time - i;
    	distanceTraveled = velocity * effectiveTime;
        if(distanceTraveled > distance) {
            ++out;
        }
    }
    //cout << out << endl;
    return out;
}

int calcAllPairs(vector<int> t, vector<int> d) {
    t.shrink_to_fit();
    d.shrink_to_fit();
    int out = 1;
    for(int i = 0; i < t.size();++i) {
        out *= calcPossibleWins(t[i], d[i]);
        cout << calcPossibleWins(t[i], d[i]) << endl;
    }
    cout << out << endl;
    return out;
}

int main() {
    vector<string> input = readFile("input.txt");
    vector<int> times = getTimes(input);
    vector<int> distances = getDistances(input);
    calcAllPairs(times, distances);
    cout << times.size();
    return 0;
}