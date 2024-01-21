#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Game {
    int green;
    int red;
    int blue;
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

Game readLine(string line) {
    string number = "";
    string temp = "";
    int green_max = 0;
    int blue_max = 0;
    int red_max = 0;
    char whitespace = ' ';
    char comma = ',';
    char semicolon = ';';
    char doublepoint = ':';
    Game out;
    for(int i = 7; i < line.length();++i) {
        if(isdigit(line[i])) {
            number += line[i];
        } else if(line[i] != whitespace && line[i] != comma && line[i] != semicolon && line[i] != doublepoint){
            temp += line[i];
        }
        if(temp.compare("red") == 0) {
            if(stoi(number) >= red_max) {
                out.red = stoi(number);
                temp = "";
                red_max = stoi(number);
                number = "";
            }
            temp = "";
            number = "";
        }
        if(temp.compare("blue") == 0) {
            if(stoi(number) >= blue_max) {
                out.blue = stoi(number);
                temp = "";
                blue_max = stoi(number);
                number = "";
            }
            temp = "";
            number = "";
        }
        if(temp.compare("green") == 0) {
            if(stoi(number) >= green_max) {
                out.green = stoi(number);
                temp = "";
                green_max = stoi(number);
                number = "";
            }
            temp = "";
            number = "";
        }
    }
    return out;
}

vector<Game> getGames(vector<string> rows) {
    vector<Game> out;
    rows.shrink_to_fit();
    for(int i = 0; i < rows.size();++i) {
        out.push_back(readLine(rows[i]));
    }
    return out;
}

int getSumOfPossibleGames(vector<Game> games) {
    int out = 0;
    games.shrink_to_fit();
    for(int i = 0; i < games.size();++i) {
        if(games[i].green <= 13 && games[i].red <= 12 && games[i].blue <= 14) {
            out += i+1;
        }
    }
    cout << out << endl;
    return out;
}

int main() {
    vector<string> lines = readFile("input.txt");
    getSumOfPossibleGames(getGames(lines));
    //readLine(lines[0]);
    return 0;
}