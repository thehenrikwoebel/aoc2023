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

vector<string> getHands(vector<string> file) {
    file.shrink_to_fit();
    vector<string> out;
    string hand = "";
    for(int i = 0; i < file.size();++i) {
        for(int j = 0; j < 5;++j) {
            hand += file[i][j];
        }
        out.push_back(hand);
        //cout << hand << endl;
        hand = "";
    }
    return out;
}

vector<int> getWinnings(vector<string> file) {
    file.shrink_to_fit();
    vector<int> out;
    string win = "";
    for(int i = 0; i < file.size();++i) {
        for(int j = 6; j < file[i].size();++j) {
            win += file[i][j];
        }
        out.push_back(stoi(win));
        //cout << win << endl;
        win = "";
    }
    return out;
}

enum Hands {Five_of_a_kind=5, Four_of_a_kind=4, Full_house=-3, Three_of_a_kind=3, Two_pair=2, One_pair=1, High_card=-1, none};



Hands checkForMultiples(string hand) {
    vector<int> multiples;
    vector<int> letters;
    int letter;
    int max = 0;
    int max2 = 0;
    for(int i = 0; i < 5;++i) {
        multiples.push_back(0);
    }
    for(char character: hand) {
        letters.push_back(int(character));
        cout << to_string(int(character)) << endl;
    }
    for(int i = 0; i < letters.size();++i) {
        letter = letters.at(i);
        for(int j = 0; j < letters.size();j++) {
            if(letters[j] == letter) {
                multiples[i]++;
            }
        }
    }
    for(int i = 0; i < multiples.size();i++) {
        if(multiples[i] > max) {
            max = multiples[i];
        }
    }
    for(int i = 0; i < multiples.size();++i) {
        if(multiples[i] == max) {
            cout << multiples.at(i) << endl;
            multiples.erase(multiples.begin() + i);
        }
    }
    for(int i = 0; i < multiples.size();i++) {
        cout << multiples.at(i) << endl;
        if(multiples[i] > max2) {
            max2 = multiples[i];
        }
    }
    switch(max) {
        case 5:
            cout << "Five_of_a_kind";
            return Five_of_a_kind;
        case 4:
            cout << "Four_of_a_kind";
            return Four_of_a_kind;
        case 3:
            if(max2 > 1) {
                cout << "Full_house";
                return Full_house;
            }
            cout << "Three_of_a_kind";
            return Three_of_a_kind;
        case 2:
            if(max2 > 1) {
                cout << "Two_pair";
                return Two_pair;
            }
            cout << "One_pair";
            return One_pair;
    }
    return none;
}



Hands calcHand(string hand) {
    Hands out;
    return static_cast<Hands>(0);
}

int main() {
    vector<string> in = readFile("input.txt");
    vector<int> winnings = getWinnings(in);
    vector<string> hands = getHands(in);
    checkForMultiples("22567");
    return 0;
}