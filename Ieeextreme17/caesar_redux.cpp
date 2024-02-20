//
// Created by JOHNSON on 2/20/2024.
// 100% score
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char getcharr(char x, int y) {
    int n = ((x - 'a' - y) + 26) % 26;

    return static_cast<char>(n + 'a');
}

char gettchar(char x, int y) {
    int n = ((x - 'a' + y) + 26) % 26;

    return static_cast<char>(n + 'a');
}


bool check(const std::string &message) {
    string temp = "";
    for (char x: message) {
        if (x == ' ') {

            if (temp == "the") return true;
            temp = "";
        } else {
            temp += x;
        }
    }

    if (temp == "the") return true;
    return false;
}

std::string solve1(int value, const std::string &message) {
    std::string answer = "";
    for (char x: message) {
        if (std::isspace(x)) {
            answer += x;
        } else {
            answer += gettchar(x, value);
        }
    }
    return answer;
}

std::string solve(int value, const std::string &message) {
    std::string answer = "";
    for (char x: message) {
        if (std::isspace(x)) {
            answer += ' ';
        } else {
            answer += getcharr(x, value);
        }
    }
    return answer;
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(); // Consume the newline character

    std::vector <std::string> answer;

    for (int i = 0; i < n; ++i) {
        int shift;
        std::cin >> shift;
        std::cin.ignore(); // Consume the newline character

        std::string read;
        std::getline(std::cin, read);

        if (check(read)) {
            answer.push_back(solve(shift, read));
        } else {
            answer.push_back(solve1(shift, read));
        }
    }

    for (const std::string &ans: answer) {
        std::cout << ans << std::endl;
    }

    return 0;
}
