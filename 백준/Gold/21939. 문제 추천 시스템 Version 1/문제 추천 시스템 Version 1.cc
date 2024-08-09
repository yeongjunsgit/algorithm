#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int N, M;

void recommand_guy(map<int, set<int>>& quiz_list, map<int, int>& is_solved, string command, int one, int two) {
	if (command == "add") {
		quiz_list[two].insert(one);
		is_solved[one] = two;
	}
	else if (command == "solved") {
        int difficulty = is_solved[one];
        if (difficulty != 0) {
            quiz_list[difficulty].erase(one);
            if (quiz_list[difficulty].empty()) {
                quiz_list.erase(difficulty);
            }
        }
	    is_solved[one] = 0;
	}
	else if (command == "recommend") {
        if (one == 1) {
            while (!quiz_list.empty()) {
                auto& top_set = quiz_list.rbegin()->second;
                if (!top_set.empty()) {
                    int now_best = *top_set.rbegin();
                    cout << now_best << "\n";
                    return;
                }
                quiz_list.erase(quiz_list.rbegin()->first);
            }
        }
        
        else if (one == -1) {
            while (!quiz_list.empty()) {
                auto& top_set = quiz_list.begin()->second;
                if (!top_set.empty()) {
                    int now_best = *top_set.begin();
                    cout << now_best << "\n";
                    return;
                }
                quiz_list.erase(quiz_list.begin()->first);
            }
        }
	}
	
	return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin >> N;

	map<int, set<int>> quiz_list;
	map<int, int> is_solved;
	int num, difficult;

	for (int i=0; i<N; ++i) {
		cin >> num >> difficult;
		quiz_list[difficult].insert(num);
		is_solved[num] = difficult;
	}

	cin >> M;
	string command;
	int one, two;

	for (int i=0; i<M; ++i) {
		cin >> command;
		if (command == "add") {
			cin >> one >> two;
			recommand_guy(quiz_list, is_solved, command, one, two);
		}
		else {
			cin >> one;
			recommand_guy(quiz_list, is_solved, command, one, 0);
		}
	}

	return 0;
}
