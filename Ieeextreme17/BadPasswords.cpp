//
// Created by JOHNSON on 2/20/2024.
// 100%
#include<bits/stdc++.h>

using namespace std;


bool solve(const string &s1, const string &s2, unordered_map<string, int> &store) {

    string p1, p2, ss1, ss2;
    int n = min(s1.size(), s2.size());

    for (int i = 0; i <= n; i++) {
        p1 = s1.substr(0, i);
        p2 = s2.substr(0, i);
        //cout << p1 << " " << p2 << endl;
        if (p1 != p2)return false;
        for (int j = 0; j <= n; j++) {
//)
            if ((s1.size() - j - i) <= 10 and (s2.size() - j - i) <= 10) {
                ss1 = s1.substr(s1.size() - j);
                ss2 = s2.substr(s2.size() - j);
                //if(ss1 != ss2)break;;
                string p = s1.substr(i, (s1.size() - j - i)), q = s2.substr(i, s2.size() - j - i);
                //cout << p << " " << store[p] << " " << store[q] << endl;
                if (ss1 != ss2)break;

                if (p != "" and q != "" and p != q and store.find(p) != store.end() and store.find(q) != store.end()) {
                    //cout << "yo " << p << " " << q << endl;
                    //cout << store[p] << " " << store[q] << endl;
                    return store[p] == store[q];
                }
            }

        }
    }

    return false;
}

void prepare(const std::string &text, int group, unordered_map<string, int> &store) {
    std::vector <std::string> words;
    std::istringstream iss(text);
    std::string word;

    while (iss >> word) {
        words.push_back(word);
        //store[word] = group;
    }
    int n = stoi(words[0]);
    for (int i = 1; i <= n; i++) {
        store[words[i]] = group;
        //cout << words[i] << " " << group << " ";
    }
    // cout << endl;
}


int main() {
    int n;
    cin >> n;

    cin.ignore();
    unordered_map<string, int> store;
    string temp;
    int y = 0;
    for (int i = 0; i < n; i++) {
        getline(cin, temp);
        // cout << temp << endl;
        prepare(temp, y, store);
        y += 1;
    }
    getline(cin, temp);
    int k = stoi(temp);
    string s1, s2;

    for (int i = 0; i < k; i++) {
        cin >> s1 >> s2;
        if (solve(s1, s2, store)) {
            cout << "REJECT\n";
        } else {
            cout << "OK\n";
        }
    }


    //password!!! password???
    return 0;
}
