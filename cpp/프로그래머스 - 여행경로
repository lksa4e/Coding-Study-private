문제 설명
주어진 항공권을 모두 이용하여 여행경로를 짜려고 합니다. 항상 ICN 공항에서 출발합니다.

항공권 정보가 담긴 2차원 배열 tickets가 매개변수로 주어질 때, 방문하는 공항 경로를 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한사항
  모든 공항은 알파벳 대문자 3글자로 이루어집니다.
  주어진 공항 수는 3개 이상 10,000개 이하입니다.
  tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.
  주어진 항공권은 모두 사용해야 합니다.
  만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
  모든 도시를 방문할 수 없는 경우는 주어지지 않습니다.
  
입출력 예
tickets	                                                        return
[[ICN, JFK], [HND, IAD], [JFK, HND]]	                          [ICN, JFK, HND, IAD]
[[ICN, SFO], [ICN, ATL], [SFO, ATL], [ATL, ICN], [ATL,SFO]]	    [ICN, ATL, ICN, SFO, ATL, SFO]

입출력 예 설명
예제 #1

[ICN, JFK, HND, IAD] 순으로 방문할 수 있습니다.

예제 #2

[ICN, SFO, ATL, ICN, ATL, SFO] 순으로 방문할 수도 있지만 [ICN, ATL, ICN, SFO, ATL, SFO] 가 알파벳 순으로 앞섭니다.

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
deque<string> q;
size_t s;
int flag = 0;                                                                       //정답 찾을 시 dfs 안돌게 하기위한 flag 변수
bool check[30000];                                                                  //dfs를 위한 check 배열
vector<string> temp;
bool cmp(vector<string> ticket1 , vector<string> ticket2){                          //알파벳 순으로 나열하고 출발지가 같을 땐 도착지가 알파벳 순으로 나오게 하는 cmp함수
    if(ticket1[0] == ticket2[0]){
        return ticket1[1] < ticket2[1];
    }else{
        return ticket1[0] < ticket2[0];
    }
}
void dfs(vector<vector<string>> tickets, vector<string> arr, int cnt){              // tickets -> 전체티켓 벡터 // arr -> 출발지, 도착지 담은 티켓// cnt -> count
    if(flag == 1) return;                                                           // 이미 정답을 찾았으면 dfs 안돌게
    if(q.size() == s){                                                              // deque 사이즈가 입력배열 사이즈 -> 모든 원소 다썼다.
        q.push_back(arr[1]);                                                        // 기존에 출발지 정보만 저장했으므로 마지막 도착지까지 정답큐에 넣기
        flag = 1;                                                                   // 정답 찾았다고 flag 표시
        temp.assign(q.begin(),q.end());                                             // 정답벡터에 assign
        return;
    }
    for(int i = 0; i < s; i++){                                                     // 정답 아직 못찾았을 경우
        if(tickets[i][0] == arr[1] && check[i] == 0){                               // 전체 티켓 중에서 출발지가 내가 가진 티켓의 도착지와 일치하는(도착해서 다음에 갈수있는) 
                                                                                    //        티켓을 찾는다. 
            check[i] = 1;                                                           // 체크
            q.push_back(tickets[i][0]);                                             // 해당 티켓(전체 티켓 중 내가 다음번에 가야할 곳)의 출발지를 정답큐에 넣기
            dfs(tickets, tickets[i], cnt + 1);                                      // 내가 기존의 가진 티켓의 도착지가 출발지인 티켓을 들고 dfs 시작
            q.pop_back();
            check[i] = 0;
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end(), cmp);                                          //알파벳 순 정렬
    s = tickets.size();
    for(int i = 0; i < s; i ++){
        if(tickets[i][0] == "ICN"){                                                     //티켓 충 출발지가 ICN인 티켓 찾기
            check[i] = 1;
            q.push_back(tickets[i][0]);                                                 // 정답큐에 출발지가 ICN인 티켓을 넣는다.
            dfs(tickets, tickets[i], 0);                                                // 출발지가 ICN인 티켓을 들고 dfs를 시작한다.
            q.pop_back();
            check[i] = 0;
        }
    }
    return temp;
}
