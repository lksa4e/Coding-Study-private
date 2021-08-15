문제 설명
두 개의 단어 begin, target과 단어의 집합 words가 있습니다. 아래와 같은 규칙을 이용하여 begin에서 target으로 변환하는 가장 짧은 변환 과정을 찾으려고 합니다.

  1. 한 번에 한 개의 알파벳만 바꿀 수 있습니다.
  2. words에 있는 단어로만 변환할 수 있습니다.
예를 들어 begin이 hit, target가 cog, words가 [hot,dot,dog,lot,log,cog]라면 hit -> hot -> dot -> dog -> cog와 같이 4단계를 거쳐 변환할 수 있습니다.

두 개의 단어 begin, target과 단어의 집합 words가 매개변수로 주어질 때, 최소 몇 단계의 과정을 거쳐 begin을 target으로 변환할 수 있는지 return 하도록 solution 함수를 작성해주세요.

제한사항
  각 단어는 알파벳 소문자로만 이루어져 있습니다.
  각 단어의 길이는 3 이상 10 이하이며 모든 단어의 길이는 같습니다.
  words에는 3개 이상 50개 이하의 단어가 있으며 중복되는 단어는 없습니다.
  begin과 target은 같지 않습니다.
  변환할 수 없는 경우에는 0를 return 합니다.
  
입출력 예
begin	    target	    words	                            return
hit	      cog	        [hot, dot, dog, lot, log, cog]	  4
hit	      cog	        [hot, dot, dog, lot, log]	        0


입출력 예 설명
예제 #1
문제에 나온 예와 같습니다.

예제 #2
target인 cog는 words 안에 없기 때문에 변환할 수 없습니다.


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string>
#include <vector>
using namespace std;
size_t s;                                             // 단어의 개수
int len;                                              // 단어의 길이
bool check[50];                                       // dfs 체크 배열
vector<int> realanswer;                               // 가능한 방법 중 최소단계를 찾기 위한 임시 정답보관벡터

bool test(string begin, string word){                 // 두 스트링이 알파벳 1개 변형으로 바꿔지는지 검사하는 함수
    int temp = 0;
    for(int i = 0; i < len; i++){                     // 알파벳 다를때마다 count 증가시켜서
        if(begin[i] != word[i]) temp++;
    }
    if(temp > 1) {                                    // 카운트 2 이상이면 변환 불가
        return false;
    }else{
        return true;
    }
}
void dfs(int start, string begin, string target, vector<string> words, int cnt){        //start -> 검사하는 index , begin -> 검사하는 string
    if(begin == target){                                                                // 목표 target에 도착 , 임시벡터에 카운트 저장
        realanswer.push_back(cnt);
        return;
    }
    for(int i = 0; i < s; i++){ 
        bool result = test(begin, words[i]);                                            // 알파벳 한개로 변환 가능한지 체크
        if(result == 1 && check[i] == 0){                                               // 변환 가능하고 아직 체크 안했다면
            check[i] = 1;
            dfs(i, words[i], target, words, cnt + 1);                                   // dfs 수행
            check[i] = 0;                                                               // 다른 조합에 의해서 쓰일 수 있으니 체크 해제
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    s = words.size();
    len = words[0].size();                                                              
    dfs(0, begin, target, words, 0);
    int max = 9999;
    for(int i = 0; i < realanswer.size(); i++){                                         // 임시저장 벡터에 들어있는거 중 최소값 찾기
        if(max > realanswer[i]) max = realanswer[i];
    }
    if(realanswer.size() != 0 ) answer = max;                                           // 임시저장 벡터에 들어있는게 없으면 할 수 없음
    return answer;
}
