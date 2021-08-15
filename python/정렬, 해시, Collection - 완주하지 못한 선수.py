문제 설명
수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.

마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.

제한사항
마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.
completion의 길이는 participant의 길이보다 1 작습니다.
참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
참가자 중에는 동명이인이 있을 수 있습니다.
입출력 예
participant	                                 completion	                        return
[leo, kiki, eden]	                          [eden, kiki]	                      leo
[marina, josipa, nikola, vinko, filipa]	    [josipa, filipa, marina, nikola]	  vinko
[mislav, stanko, mislav, ana]	              [stanko, ana, mislav]	              mislav

입출력 예 설명
예제 #1
leo는 참여자 명단에는 있지만, 완주자 명단에는 없기 때문에 완주하지 못했습니다.

예제 #2
vinko는 참여자 명단에는 있지만, 완주자 명단에는 없기 때문에 완주하지 못했습니다.

예제 #3
mislav는 참여자 명단에는 두 명이 있지만, 완주자 명단에는 한 명밖에 없기 때문에 한명은 완주하지 못했습니다.


----------------------------------------------------------------------------------------------------------------------------------------------------------------------
def solution(participant, completion):
    answer = ''
    participant.sort()    //정렬해서 앞에서부터 비교
    completion.sort()
    flag = 0
    for i in range(len(completion)):
        if participant[i] != completion[i]:
            answer = participant[i]
            flag = 1
            break
    if flag == 0:                           //만약 완주자 명단에서 전부 찾았는데도 정답못찾으면 참가자 마지막선수가 정답
        answer = participant.pop()
    return answer
    
    
-------------------------------유용한 다른사람 풀이 ---------------------------------------------------------------------------------------------------------------------
def solution(participant, completion):
    answer = ''
    temp = 0
    dic = {}
    for part in participant:
        dic[hash(part)] = part                  //hash(part) 하게되면 특정 숫자가 hash 키값으로 들어온다
        temp += int(hash(part))                 //그걸 더해줌
    for com in completion:
        temp -= hash(com)                       // 다 빼고나면 participant에서 하나가 남는다
    answer = dic[temp]

    return answer

//찾아야 하는 사람이 한명이기에 쓸 수 있는 풀이법

------------------------------------------유용한 다른사람풀이 2 ----------------------------------------------------------------------------------------------------------

import collections


def solution(participant, completion):
    answer = collections.Counter(participant) - collections.Counter(completion)   // Counter({'leo': 1, 'kiki': 1, 'eden': 1}) participant
                                                                                    //Counter({'eden': 1, 'kiki': 1})  completion
                                                                                    // print(answer) Counter({'leo': 1}) - 결과
    return list(answer.keys())[0]                                                   // answer.keys() -> dict_keys(['leo']) 
                                                                                    // list(answer.keys()) -> ['leo']
                                                                                    // list(answer.keys())[0] -> leo
    
