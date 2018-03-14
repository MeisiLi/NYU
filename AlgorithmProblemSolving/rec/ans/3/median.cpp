#include<iostream>
#include<set>
#include<vector>
#include<queue>
using namespace std;
const int N = 1e3 + 10;
int n, cas;
int a[N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> cas >> n;
        cout << cas << " " << (n + 1) / 2 << endl;

        priority_queue<int, vector<int>> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int x;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            if (i % 2) {
                if (minHeap.size() == 0 || minHeap.top() >= x) {
                    maxHeap.push(x);
                } else {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(x);
                }
            } else {
                if (x >= maxHeap.top()) {
                    minHeap.push(x);
                } else {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(x);
                }
            }
            if (i % 2) {
                int res = maxHeap.top();
                if (cnt == 10) {
                    cnt = 0;
                    cout << endl;
                }
                if (cnt > 0) cout << " ";
                cout << res;
                cnt++;
            }
        }
        cout << endl;


    }
    return 0;
}