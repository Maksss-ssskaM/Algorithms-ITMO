#include <iostream>
#include<string>
#include <vector>
using namespace std;

vector<int> z_func(string str)
{
    vector<int> z(str.size());
    int left = 0, right = 0;
    for (int i = 1; i < str.size(); i++)
    {
        if (i + 1 < right)
            z[i] = min(right - i + 1, z[i - left]);

        while (i + z[i] < str.size() && str[z[i]] == str[i + z[i]])
            z[i]++;

        if (i + z[i] - 1 > right)
        {
            left = i;
            right = i + z[i] - 1;
        }
    }
    return z;
}



int main() {

    string str, pattern;

    vector<int>result, z;

    cin >> pattern >> str;
    z = z_func(pattern + "#" + str);

    for(unsigned long i = pattern.size(); i < z.size(); i++)
        if(z[i] == pattern.size())
            result.push_back(i - pattern.size());

    cout << result.size() << endl;
    for(auto i : result)
        cout << i << " ";

    return 0;
}
