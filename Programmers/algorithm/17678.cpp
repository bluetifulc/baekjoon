#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// [1차] 셔틀버스
// Simulation, String Parse
string solution(int n, int t, int m, vector<string> timetable) {
    sort(timetable.begin(), timetable.end());
    string answer = "";
    int hour = 9;
    int minute = 0;
    int idx = 0;
    int time = 0;
    int bus = m;
    while(time < n){
        if(idx != timetable.size()){
            int curh = stoi(timetable[idx].substr(0,2));
            int curm = stoi(timetable[idx].substr(3,2));
            while(curh < hour || (curh == hour && curm <= minute)){
                if(bus == 0) break;
                bus--;
                if(++idx == timetable.size()) break;
                curh = stoi(timetable[idx].substr(0,2));
                curm = stoi(timetable[idx].substr(3,2));
            }
        }
        if(time == n-1) break;
        bus = m;
        time++;
        minute += t;
        if(minute >= 60){
            hour += (minute/60);
            minute %= 60;
        }
    }
    // cout << "LEFT:" << bus << endl;
    // cout << hour << ":" << minute << endl;
    if(bus >= 1){
        if(hour < 10) answer = "0" +to_string(hour)+ ':';
        else answer = to_string(hour)+":";
        if(minute < 10) answer += "0"+to_string(minute);
        else answer.append(to_string(minute));
    }else{
        idx--;
        int curh = stoi(timetable[idx].substr(0,2));
        int curm = stoi(timetable[idx].substr(3,2));
        curm--;
        if(curm == -1){
            curh--;
            curm = 59;
        }
        if(curh < 10) answer = "0" +to_string(curh)+ ':';
        else answer = to_string(curh)+":";
        if(curm < 10) answer += "0"+to_string(curm);
        else answer.append(to_string(curm));
    }
    return answer;
}
int main(){
    int n = 10;
    int t = 60;
    int m = 45;
    vector<string> timetable = {"23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"};
    cout << solution(n,t,m,timetable)<<endl;
}