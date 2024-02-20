//
// Created by JOHNSON on 2/20/2024.
// 100% score
#include <bits/stdc++.h>

using namespace std;


std::string toLower(std::string &str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}


void prepare(const std::string &text, int group, unordered_map<string, int> &store) {
    std::vector <std::string> words;
    std::istringstream iss(text);
    std::string word;

    while (iss >> word) {
        store[word] = group;
    }
}


int prepare1(const std::string &text, unordered_map<string, int> &store) {
    int answer = -1;
    std::vector <std::string> words;
    std::istringstream iss(text);
    std::string word;

    while (iss >> word) {
        word = toLower(word);
        words.push_back(word);

    }
    if (store.find(words[words.size() - 1]) != store.end()) {
        return store[words[words.size() - 1]];
    }

    return answer;
}


int main() {
    int n, x;
    cin >> n >> x;
    string temp;
    unordered_map<string, int> store;
    int y = 0;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, temp);
        prepare(temp, y, store);
        y += 1;
    }

    getline(cin, temp);
    vector<int> answer(x, -1);

    for (int i = 0; i < x; i++) {
        getline(cin, temp);
        answer[i] = prepare1(temp, store);
    }
    vector<char> answer1(x, 'X');
    vector<bool> visited(x, false);
    char start = 'A';
    for (int i = 0; i < x; i++) {
        if (answer[i] != -1 and visited[i] == false) {
            // cout << i << " " << start << endl;
            visited[i] = true;
            bool c = false;
            answer1[i] = start;
            for (int j = 0; j < x; j++) {
                if (j != i and answer[i] == answer[j]) {
                    c = true;
                    answer1[j] = start;
                    visited[j] = true;
                }
            }
            if (!c) {
                answer1[i] = 'X';
            } else {
                start++;
            }


        }

    }

    for (int i = 0; i < x; i++) {
        cout << answer1[i];
    }

    return 0;
}
