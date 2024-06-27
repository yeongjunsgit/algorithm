#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<vector<int>>>elements(N, vector<vector<int>>(M, vector<int>(3, 0)));

    string data;
    for (int i = 0; i < N; ++i) {
        cin >> data;
        for (int j = 0; j < M; ++j) {
            if (j == 0) {
                if (data[j] == 'J') {
                    elements[i][j][0] += 1;
                    
                }
                else if (data[j] == 'O') {
                    elements[i][j][1] += 1;
                    
                }
                else if (data[j] == 'I') {
                    elements[i][j][2] += 1;
                }
            }
            else {
                elements[i][j] = elements[i][j - 1];
                if (data[j] == 'J') {
                    elements[i][j][0] += 1;
                    
                }
                else if (data[j] == 'O') {
                    elements[i][j][1] += 1;
                    
                }
                else if (data[j] == 'I') {
                    elements[i][j][2] += 1;
                    
                }
                
            }
		}
	}
	for (int i = 1; i < N; ++i) {
	    for (int j = 0; j < M; ++j) {
	        for (int k = 0; k < 3; ++k) {
	            elements[i][j][k] += elements[i - 1][j][k];
			}
		}
	}
	
	for (int i = 0; i < K; ++i) {
	    int x1, y1, x2, y2;
	    cin >> x1 >> y1 >> x2 >> y2;
	    vector < int >now = elements[x2 - 1][y2 - 1];
	    if (x1 - 1 != 0 || y1 - 1 != 0) {
		    vector < int >tmp_now_one, tmp_now_two, multiple;
		    if (x1 - 1 == 0) {
		        tmp_now_one = {0, 0, 0};
		        tmp_now_two = elements[x2 - 1][y1 - 2];
		        multiple = {0, 0, 0};
		    }
		    else if (y1 - 1 == 0) {
  		        tmp_now_one = elements[x1 - 2][y2 - 1];
		        tmp_now_two = {0, 0, 0};
		        multiple = {0, 0, 0};
		    }
		    else {
    	  	  tmp_now_one = elements[x1 - 2][y2 - 1];
    	  	  tmp_now_two = elements[x2 - 1][max (0, y1 - 2)];
    	  	  multiple = elements[x1 - 2][y1 - 2];
		    }

		    now[0] -= (tmp_now_one[0] + tmp_now_two[0] - multiple[0]);
		    now[1] -= (tmp_now_one[1] + tmp_now_two[1] - multiple[1]);
		    now[2] -= (tmp_now_one[2] + tmp_now_two[2] - multiple[2]);
	    }

	    cout << now[0] << " " << now[1] << " " << now[2] << "\n";

	}
	
	return 0;
}
