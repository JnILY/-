#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


extern void elimDups(vector<string> &words);
extern bool isShorter(const string &s1, const string &s2);


int main()
{
    vector<string> svec;
    string s;
    while (cin >> s)
        svec.push_back(s);
    elimDups(svec);
    /*stable_sort(svec.begin(), svec.end(), isShorter);*/
    for (auto &s : svec)
        cout << s << " ";
    return 0;
}


void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end(),isShorter);
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}


bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}