#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution{
public:
    string printf_min_number(vector<int> numbers){
        string answer = "";
        sort(numbers.begin(),numbers.end(),cmp);
        for(int i = 0;i < (int)numbers.size();++i){
            answer+=to_string(numbers[i]);
        }
        return answer;
    }
private:
    static bool cmp(int a,int b){
        string A="";
        string B="";
        A += to_string(a);
        A += to_string(b);
        B += to_string(b);
        B += to_string(a);

        return A < B;
    }
};
