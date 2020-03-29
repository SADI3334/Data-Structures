#include <bits/stdc++.h>
#define mx 100
int arr[mx];
int tree[mx];
using namespace std;

int query (int idx) {
    int sum = 0;
    while (idx) {
        sum = sum + tree[idx];
        idx = idx - (idx & -idx);
    }
    return sum;
}

int rangeQuery(int i, int j) {
    return query(j) - query(i - 1);
}

void update(int idx, int value, int n) {
    while (idx <= n) {
        tree[idx] = tree[idx] + value;
        idx = idx + (idx & -idx);
    }
}

void print(int * tree, int n) {
    cout << "Elements are: " << endl;
    for (int i = 1; i <= n; ++i) {
        cout << tree[i] << " ";
    }
    cout << endl << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        update(i, arr[i], n);
    }
    cout << query(4) << endl;
    update(4, 5, n);
    cout << query(4) << endl;
    int i, j;
    cin >> i >> j;
    cout << rangeQuery(i, j) << endl;
    print(arr, n);
    print(tree, n);
    return 0;
}
