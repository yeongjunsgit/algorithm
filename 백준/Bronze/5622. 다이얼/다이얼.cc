#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    string data;
    cin >> data;

    int result = 0;
    
    map<string, int> changeNum;
    changeNum.insert(pair<string, int>("A", 3));
    changeNum.insert(pair<string, int>("B", 3));
    changeNum.insert(pair<string, int>("C", 3));
    changeNum.insert(pair<string, int>("D", 4));
    changeNum.insert(pair<string, int>("E", 4));
    changeNum.insert(pair<string, int>("F", 4));
    changeNum.insert(pair<string, int>("G", 5));
    changeNum.insert(pair<string, int>("H", 5));
    changeNum.insert(pair<string, int>("I", 5));
    changeNum.insert(pair<string, int>("J", 6));
    changeNum.insert(pair<string, int>("K", 6));
    changeNum.insert(pair<string, int>("L", 6));
    changeNum.insert(pair<string, int>("M", 7));
    changeNum.insert(pair<string, int>("N", 7));
    changeNum.insert(pair<string, int>("O", 7));
    changeNum.insert(pair<string, int>("P", 8));
    changeNum.insert(pair<string, int>("Q", 8));
    changeNum.insert(pair<string, int>("R", 8));
    changeNum.insert(pair<string, int>("S", 8));
    changeNum.insert(pair<string, int>("T", 9));
    changeNum.insert(pair<string, int>("U", 9));
    changeNum.insert(pair<string, int>("V", 9));
    changeNum.insert(pair<string, int>("W", 10));
    changeNum.insert(pair<string, int>("X", 10));
    changeNum.insert(pair<string, int>("Y", 10));
    changeNum.insert(pair<string, int>("Z", 10));

    // data[i]는 char 타입이라서 key값이 string으로 들어갔기 때문에 에러가남
    // char 를 string으로 만들어줌
    for (int i=0; i<data.size(); ++i) {
        // data[i]를 길이 1짜리 string으로 변환하는 코드
        string key(1, data[i]);
        result += changeNum[key];
    }
    
    cout << result;

    return 0;
}
