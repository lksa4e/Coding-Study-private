문제 설명
n개의 노드가 있는 그래프가 있습니다. 각 노드는 1부터 n까지 번호가 적혀있습니다. 
1번 노드에서 가장 멀리 떨어진 노드의 갯수를 구하려고 합니다. 가장 멀리 떨어진 노드란 최단경로로 이동했을 때 간선의 개수가 가장 많은 노드들을 의미합니다.

노드의 개수 n, 간선에 대한 정보가 담긴 2차원 배열 vertex가 매개변수로 주어질 때, 1번 노드로부터 가장 멀리 떨어진 노드가 몇 개인지를 return 하도록 solution 함수를 작성해주세요.

제한사항
노드의 개수 n은 2 이상 20,000 이하입니다.
간선은 양방향이며 총 1개 이상 50,000개 이하의 간선이 있습니다.
vertex 배열 각 행 [a, b]는 a번 노드와 b번 노드 사이에 간선이 있다는 의미입니다.

입출력 예
n	  vertex	                                                   return
6	  [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]	 3

입출력 예 설명
예제의 그래프를 표현하면 아래 그림과 같고, 1번 노드에서 가장 멀리 떨어진 노드는 4,5,6번 노드입니다.

----------------------------------------------------------------------------------------------------
간선의 가중치가 없으므로 최단거리 알고리즘을 사용할 필요 없이 dfs, bfs 알고리즘을 통해 해결 가능하다.
하지만 문제에서 특정 노드로 가기 위한 경로가 여러개인데 dfs를 사용할 경우 최단으로 가지 않고 돌아서 가는 경우가 발생 가능하다.
따라서 bfs를 통해 문제를 해결한다.


#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
vector<int> graph[20001];
bool visit[20001];                        // 방문 여부 check
int level[20001];                         // 특정 depth에 속하는 node의 개수
int max_lev = 0;                          // 최대 depth를 저장
void bfs(int start){
    queue<pair<int,int>> q;
    q.push({start,0});
    while(!q.empty()){
        int node_num = q.front().first;
        int lev = q.front().second;
        q.pop();
        if(visit[node_num] == 1) continue;               // 이미 방문한 노드인 경우 재방문하는 경우에는 빙글 돌아서 오는 것이므로 패스한다.
        visit[node_num] = 1;                             // 해당 노드 방문처리
        level[lev]++;                                    // 해당 Node가 속하는 level의 노드개수 증가
        max_lev = max(lev, max_lev);                     // 최대 depth 저장
        
        for(auto next : graph[node_num]){
            if(!visit[next]){
                q.push({next,lev + 1});
            }
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i = 0; i < edge.size(); i++){
        int u = edge[i][0];
        int v = edge[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs(1);
    cout << max_lev;
    answer = level[max_lev];
    return answer;
}
