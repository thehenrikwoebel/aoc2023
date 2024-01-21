#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int power(int base, int exponent) {
    int out = base;
    if(exponent == 0) {
        return 1;
    } else {
        for(int i = 1; i < exponent;++i) {
            out *= base;
        }
        return out;
    }
}

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

vector<int> getWinningNumbers(vector<string> file) {
    file.shrink_to_fit();
    string number = "";
    vector<int> out;
    for(int i = 0; i < file.size();++i) {
        for(int j = 10; j < 42;++j) {
            if(isdigit(file[i][j])) {
                number += file[i][j];
            } else if(number.length() > 0 && file[i][j] == ' '){
                //cout << number << endl;
                out.push_back(stoi(number));
                number = "";
            }
        }
        number = "";
    }
    return out;
}

vector<int> getNumbers(vector<string> file) {
    file.shrink_to_fit();
    vector<int> out;
    string number = "";
    for(int i = 0; i < file.size();++i) {
        for(int j = 42; j < 116;++j) {
            if(isdigit(file[i][j])) {
                number += file[i][j];
            } else if(number.length() > 0) {
                //cout << number << endl;
                out.push_back(stoi(number));
                number = "";
            }
        }
        //cout << number << endl;
        out.push_back(stoi(number));
        number = "";
    }
    return out;
}

vector<vector<int>> cutWinningNumbers(vector<int> wNumbers) {
    wNumbers.shrink_to_fit();
    vector<vector<int>> out;
    vector<int> temp;
    for(int i = 0; i < wNumbers.size();++i) {
        //cout << wNumbers[i] << endl;
        temp.push_back(wNumbers[i]);
        if((i+1) % 10 == 0) {
            //cout << "Neue Zeile!" << endl;
            out.push_back(temp);
            temp = {};
        }
    }
    return out;
}

bool checkNumber(vector<int> wNumbers, int number) {
    wNumbers.shrink_to_fit();
    for(int i = 0; i < wNumbers.size();++i) {
        if(wNumbers[i] == number) {
            //cout << "Winning Number!";
            //cout << number << endl;
            return true;
        }
    }
    return false;
}

vector<int> compareNumbers(vector<vector<int>> wNumbers, vector<int> numbers) {
    wNumbers.shrink_to_fit();
    numbers.shrink_to_fit();
    int out = 0;
    int it = 0;
    vector<int> correctOnes;
    int number = -1;
    for(int i = 0; i < numbers.size();++i) {
        if(checkNumber(wNumbers[it], numbers[i])) {
            ++number;
        }
        if((i+1) % 25 == 0 && i != 0 && i != 193) {
            //cout << number << endl;
            //cout << i/24 << endl;
            ++it;
            if(number > -1) {
                correctOnes.push_back(number);
            }
            number = -1;
        }
    }
    return correctOnes;
}

int getSum(vector<int> correctNums) {
    int out = 0;
    for(int i = 0; i < correctNums.size();++i) {
        out += power(2, correctNums.at(i));
    }
    cout << out;
    return out;
}

int main() {
    vector<string> cards = readFile("input.txt");
    vector<vector<int>> wNum = cutWinningNumbers(getWinningNumbers(cards));
    vector<vector<int>> winningNumbers = cutWinningNumbers(getWinningNumbers(cards));
    vector<int> anumbers = getNumbers(cards);
    getSum(compareNumbers(winningNumbers, anumbers));
    return 0;
}