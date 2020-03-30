#include <iostream>
#include <cmath>
using namespace std;
int input[10000];
int segment[10000];

int preprocess(int input[], int n) {
    int current_segment = -1;
    int segment_size = sqrt(n);
    for (int i = 0; i < n; ++i) {
        if (i % segment_size == 0) {
            current_segment++;
        }
        segment[current_segment] += input[i];
    }
    return segment_size;
}

int query (int input[], int segment_size, int l, int r) {
    int sum = 0;
    while (l <= r && l % segment_size != 0) {
        sum += input[l];
        l++;
    }
    while (l + segment_size <= r) {
        sum += input[l / segment_size];
        l += segment_size;
    }
    while (l <= r) {
        sum += input[l];
        l++;
    }
    return sum;
}

void update(int segment[], int segment_size, int i, int val) {
    int segment_no = i / segment_size;
    segment[segment_no] -= input[i];
    segment[segment_no] += val;
    input[i] = val;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        input[i] = i + 1;
    }
    int segment_size = preprocess(input, n);
    int l, r;
    cin >> l >> r;
    cout << query(input, segment_size, l, r) << endl;
    int index, val;
    cin >> index;
    cin >> val;
    update(segment, segment_size, index, val);
    cin >> l >> r;
    cout << query(input, segment_size, l, r) << endl;
    return 0;
}
