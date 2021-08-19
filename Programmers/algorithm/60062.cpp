#include <string>
#include <vector>
#include <algorithm>
// 외벽점검
// Permutation, brute-force
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = -1;
    sort(dist.begin(), dist.end());
    for(int i = 0; i < weak.size(); ++i){
        int tmp = weak[0] + n;
        for(int j = 1; j < weak.size(); ++j){
            weak[j-1] = weak[j];
        }
        weak[weak.size()-1] = tmp;
        do{
            int w = 0, f = 0;
            for(f = 0; f < dist.size(); ++f){
                int fin = weak[w] + dist[f];
                while(fin >= weak[w]){
                    ++w;
                    if(w == weak.size()) break;
                }
                if(w == weak.size()) break;
            }

            if(w == weak.size()){
                if(answer == -1 || f+1 < answer){
                    answer = f+1;
                }
            }
        }while(next_permutation(dist.begin(), dist.end()));
    }
    return answer;
}