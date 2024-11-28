#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

vector<int> result;

struct Compare {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
	    return a.first > b.first;
	}
};

priority_queue<int, vector<int>, greater<int> > have_card;
priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> share_card;

void check_cards()
{
	while (!share_card.empty()) {
		pair<int, int> now = share_card.top();
		share_card.pop();
		bool check_pass = false;

		if (!have_card.empty()) {
			while (!have_card.empty()) {
				int target = have_card.top();
				if (now.first == target) {
					have_card.pop();
					result[now.second] = 1;
					check_pass = true;
					break;
				}
				else if (now.first < target) {
					result[now.second] = 0;
					break;
				}
				else {
					have_card.pop();
				}
			}
			if (have_card.empty() && check_pass == false) {
			    result[now.second] = 0;
			}
		}
		else {
			result[now.second] = 0;
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cin.ignore();

	string data;
	int num;
	getline(cin, data);
	istringstream iss(data);
	while (iss >> num) {
		have_card.push(num);
	}

	cin >> M;
	cin.ignore();
    result.resize(M, -1);

	getline(cin, data);
	istringstream isss(data);
	int idx = 0;
	while (isss >> num) {
		share_card.push({num, idx});
		idx++;
	}

	check_cards();
	
	for (int a : result) {
	    cout << a << " ";
	}

	return 0;
}
