#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> get_lcs_line(string a, string b)
{
    vector<int> line(b.size() + 1, 0);

    for(int i = 0; i < a.size(); i++)
    {
        auto previous = line;
        for(int j = 0; j < b.size(); j++)
        {
            if(a[i] == b[j])
                line[j + 1] = previous[j] + 1;
            else
                line[j + 1] = max(line[j], previous[j + 1]);
        }
    }
    return line;
}

string hirshberg(string a, string b) {

    if (a.empty())
        return "";
    else if (a.size() == 1)
        {
            if (b.find(a[0]) != string::npos)
            {
                string tmp;
                tmp.push_back(a[0]);
                return tmp;
            }
            else
                return "";
        }
    else if (b.size() == 1)
    {
        if (a.find(b[0]) != string::npos)
        {
            string tmp;
            tmp.push_back(b[0]);
            return tmp;
        }
        else
            return "";
    }
    else
        {
            int middle_of_a = a.size() / 2;
            string a_first, a_second;

            for(int i  = 0; i < middle_of_a; i++)
                a_first.push_back(a[i]);
            for(int i = middle_of_a; i < a.size(); i++)
                a_second.push_back(a[i]);

            auto first_line = get_lcs_line(a_first, b);
            auto tmp1 = a_second;
            auto tmp2 = b;

            reverse(tmp1.begin(), tmp1.end());
            reverse(tmp2.begin(), tmp2.end());

            auto second_line = get_lcs_line(tmp1, tmp2);

            int max_ = -1;
            int max_index = -1;

            for(int i = 0; i <= b.size(); i++)
                if(max_ <= first_line[i] + second_line[b.size() - i])
                    max_ = first_line[i] + second_line[b.size() - i], max_index = i;

            string b_first, b_second;

            for(int i = 0; i < max_index; i++)
                b_first.push_back(b[i]);
            for(int i = max_index; i < b.size(); i++)
                b_second.push_back(b[i]);

            return hirshberg(a_first, b_first) + hirshberg(a_second, b_second);
        }
}

int main()
{
    string a, b;
    cin >> a >> b;

    cout << hirshberg(a, b) << endl;
    return 0;
}