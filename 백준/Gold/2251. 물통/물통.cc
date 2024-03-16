/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <queue>

using namespace std;

int main()
{
    set<vector<int>> visited;
    set<int> visited_num;
    deque<vector<int>> que;
    int A, B, C;
    cin >> A >> B >> C;

    vector<int> waters{ A, B, C };

    vector<int> start{ 0, 0, C };

    que.push_back(start);
    visited.insert(start);

    priority_queue<int> result;
    result.push(-C);
    visited_num.insert(-C);


    while (!que.empty()) {
        vector<int> now = que.front();
        que.pop_front();

        for (int i = 0; i < 3; ++i) {
            int base = now[i];
            for (int j = 1; j < 3; ++j) {
                int target = (i + j) % 3;
                int tmp = now[target] + base;

                if (tmp > waters[target]) {
                    int rest = tmp - waters[target];
                    tmp = waters[target];

                    vector<int> new_vec = now;
                    new_vec[i] = rest;
                    new_vec[target] = tmp;

                    if (visited.find(new_vec) == visited.end()) {
                        visited.insert(new_vec);
                        que.push_back(new_vec);
                        if (new_vec[0] == 0) {
                            if (visited_num.find(-new_vec[2]) == visited_num.end()) {
                                result.push(-new_vec[2]);
                                visited_num.insert(-new_vec[2]);
                            }
                        }
                    }
                }
                else {
                    vector<int> new_vec = now;
                    new_vec[i] = 0;
                    new_vec[target] = tmp;

                    if (visited.find(new_vec) == visited.end()) {
                        visited.insert(new_vec);
                        que.push_back(new_vec);
                        if (new_vec[0] == 0) {
                            if (visited_num.find(-new_vec[2]) == visited_num.end()) {
                                result.push(-new_vec[2]);
                                visited_num.insert(-new_vec[2]);
                            }
                        }
                    }
                }
            }
        }
    }

    while (!result.empty()) {
        int r = result.top();
        cout << -r << " ";
        result.pop();
    }

    return 0;
}
