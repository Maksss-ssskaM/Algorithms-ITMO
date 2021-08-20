#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int size;
    string str;
    cin >> size;
    cin >> str;
    str+="#";

    vector<int> prefixes(str.size());
    vector<vector<int>>result(str.size(), vector<int>(size));


    for (int i = 1; i < str.size(); i++)
    {
        int j = prefixes[i - 1];

        while (j > 0 and str[i] != str[j])
            j = prefixes[j - 1];

        if (str[i] == str[j])
            j++;

        prefixes[i] = j;
    }

    for(int i = 0; i < str.size(); i++)
        for(char j = 'a'; j < 'a' + size; j++)
            if(i > 0 and j != str[i])
                result[i][j - 'a'] = result[prefixes[i - 1]][j - 'a'];
            else
                result[i][j - 'a'] = i + (j == str[i]);

    for(const auto& i : result)
    {
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
