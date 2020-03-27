#include <bits/stdc++.h>

using namespace std;

void compressed() {
    map <int, int> m;
    int input[10000];
    vector <int> v;
    int n, assign = 0;
    cout << "Enter Number of Elements: " << endl;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
        int x = input[i];
        if (m.find(x) == m.end()) {
            m[x] = assign;
            cout << "Mapping" << " " << x << " " << "To" << " " << assign << endl;
            assign++;
        }
        x = m[x];
        v.push_back(x);
    }
    cout << "\nCompressed Array Elements are: " << endl;
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\nWhich One Do You Want to Find?" << endl;
    int query;
    cin >> query;
    cout <<"Your Query is Mapped to: " << m[query] << " " << "and is at index" << endl;
    auto it = find(v.begin(), v.end(), m[query]);
    cout << distance(v.begin(), it);
}
int main()
{
    compressed();
    return 0;
}
