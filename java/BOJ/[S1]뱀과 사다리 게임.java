/*
문제 링크 : https://www.acmicpc.net/problem/16928
그리디로 풀면서 앞에서부터 채워나가는 경우 
뱀으로 내려온 다음에 사다리를 타서 위로 갔을 때 더 빠른 경우를 놓치게 된다. 

bfs를 통해 탐색한다.
기본적으로 현재 위치 + 1, 2, 3, 4, 5, 6을 queue에 넣지만, 사다리가 있는 경우 사다리 도착지점을 넣는다.
100에 도달하면 종료한다.
*/
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;
/*
풀이시작 : 10:01
풀이종료 : 10:30
 */

public class P16928 {
	static int N, M;
	static Map<Integer,Integer> m = new HashMap<Integer,Integer>();
	static boolean arr[] = new boolean[101];
	static int answer;
	static void solve() {
		Queue<Pair> q = new LinkedList<Pair>();
		q.add(new Pair(1,0));
		while(!q.isEmpty()) {
			Pair p = q.poll();
			if(p.x == 100) {
				answer = p.y;
				return;
			}
			for(int i = 1; i <= 6; i++) {
				int npos = p.x + i;
				if(npos <= 100) {
					if(m.get(npos) != null) {
						if(!arr[m.get(npos)]) {
							arr[m.get(npos)] = true;
							q.add(new Pair(m.get(npos), p.y + 1));
						}
					}else {
						if(!arr[npos]) {
							arr[npos] = true;
							q.add(new Pair(npos, p.y + 1));
						}
					}
				}
			}
		}
	}
	public static void main(String[] args) throws IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); //선언
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		for(int i = 0; i < N + M; i++) {
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			m.put(start,end);
		}
		solve();
		System.out.println(answer);
	}
}

