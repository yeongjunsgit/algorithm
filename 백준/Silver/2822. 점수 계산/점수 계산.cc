#include <iostream>
#include <vector>
#include <algorithm>

#define pll pair<int, int>

using namespace std;

int main()
{
    vector<pll> questions(8);
    vector<int> pick_quiz;
    for (int i=0; i<8; ++i) {
        cin >> questions[i].first;
        questions[i].second = i + 1;
    }

    sort(questions.begin(), questions.end(), greater());
    int total_score = questions[0].first + questions[1].first + questions[2].first + questions[3].first + questions[4].first;
    cout << total_score << "\n";
    for (int i=0; i<5; ++i) {
        pick_quiz.push_back(questions[i].second);
    }
    sort(pick_quiz.begin(), pick_quiz.end());
    for (int i : pick_quiz) {
        cout << i << " ";
    }

    return 0;
}