#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution{
public:
    void insert(int num){
        if(p.empty() || num <= p.top())
            p.push(num);
        else
            q.push(num);
        if(p.size() == q.size()+2){
            q.push(p.top());
            p.pop();
        }
        if(p.size()+1 == q.size()){
            p.push(q.top());
            q.pop();
        }
    }

    double get_median(){
        return p.size() == q.size()?(p.top()+q.top())/2.0 : p.top();
    }
private:
    priority_queue<int,vector<int>,less<int> > p;
    priority_queue<int,vector<int>,greater<int> > q;
};
