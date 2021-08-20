#include <iostream>
#include<string>
#include <vector>
using namespace std;


int main() {

    freopen("search1.in", "r", stdin);
    freopen("search1.out", "w", stdout);

    string str, pattern;
    vector<unsigned>vector;
    int num = 0;

    cin >> pattern >> str;

    for(int i = 0; i < str.size(); i++)
        if(str[i] == pattern[0] && str.size() >= i + pattern.size())
        {
            bool is_equal = true;
            for(int j = 0; j < pattern.size(); j++)
                if(str[i + j] != pattern[j])
                    is_equal = false;
            if(is_equal)
            {
                vector.push_back(i + 1);
                num++;
            }
        }

    cout << num << endl;
    for(auto i : vector)
        cout << i << " ";

    return 0;
}
