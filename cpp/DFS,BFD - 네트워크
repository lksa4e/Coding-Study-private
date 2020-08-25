문제 설명
네트워크란 컴퓨터 상호 간에 정보를 교환할 수 있도록 연결된 형태를 의미합니다. 예를 들어, 컴퓨터 A와 컴퓨터 B가 직접적으로 연결되어있고, 
컴퓨터 B와 컴퓨터 C가 직접적으로 연결되어 있을 때 컴퓨터 A와 컴퓨터 C도 간접적으로 연결되어 정보를 교환할 수 있습니다. 
따라서 컴퓨터 A, B, C는 모두 같은 네트워크 상에 있다고 할 수 있습니다.

컴퓨터의 개수 n, 연결에 대한 정보가 담긴 2차원 배열 computers가 매개변수로 주어질 때, 네트워크의 개수를 return 하도록 solution 함수를 작성하시오.

제한사항
  컴퓨터의 개수 n은 1 이상 200 이하인 자연수입니다.
  각 컴퓨터는 0부터 n-1인 정수로 표현합니다.
  i번 컴퓨터와 j번 컴퓨터가 연결되어 있으면 computers[i][j]를 1로 표현합니다.
  computer[i][i]는 항상 1입니다.

입출력 예
n	  computers	                          return
3	  [[1, 1, 0], [1, 1, 0], [0, 0, 1]]	  2
3	  [[1, 1, 0], [1, 1, 1], [0, 1, 1]]	  1

입출력 예 설명

예제 #1
아래와 같이 2개의 네트워크가 있습니다.
A-B / C

예제 #2
아래와 같이 1개의 네트워크가 있습니다.
A-B-C

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 풀이 원리
전체 인덱스에 대해 반복하면서 방문안한 것이 있다면 dfs를 수행한다. (dfs를 한번 돌고 나서 체크된 것들은 전부 하나의 네트워크에 해당한다.)

하나에서 시작하여 dfs를 돌면서 연결된 모든 애들을 체크하고, dfs 전체 과정이 끝나고 나면 answer를 하나 증가시킨다.
dfs를 돌고 남은 index에 대해서 다시 dfs를 수행하는 작업을 모든 index에 대해 반복하여 모든 index가 check상태가 되도록 한다.
이후에 answer를 출력한다.


#include <string>
#include <vector>

using namespace std;
bool check[200];
int num = 0;
void dfs(int start, vector<vector<int>> computers){
    if(check[start]) return;                                                // 이미 체크한거면 탈출
    check[start] = 1;                                                       // 체크
    for(int i = 0; i < num; i++){                                           // 모든 원소에 대해
        if(i != start && computers[start][i] == 1 && check[i] == 0){        // 자기 자신이 아니고, 연결되어있고, 기존에 체크 안된거면
            dfs(i,computers);                                               // dfs 수행
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    num = n;
    for(int i = 0; i < num; i++){                                           //모든 index에 대해
        if(check[i] == 0){                                                  //체크된 것이 아니라면(기존 찾아진 네트워크가 아니면)
            dfs(i, computers);                                              //새로운 dfs 수행
            answer++;                                                       //연결된 네트워크 한개에 대한 dfs 탐색 후 answer 증가
        }
    }
    return answer;
}
