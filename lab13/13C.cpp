#include <iostream>
#include <vector>

using namespace std;


int main() {

    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);

    string str;

    cin >> str;

    vector<int> prefixes(str.size());
    int j;

    for (int i = 1; i < str.size(); i++)
    {
        j = prefixes[i - 1];

        while (j > 0 && str[i] != str[j])
            j = prefixes[j - 1];

        if (str[i] == str[j])
            j++;

        prefixes[i] = j;
    }

    for(auto i : prefixes)
        cout << i << " ";

    return 0;
}
