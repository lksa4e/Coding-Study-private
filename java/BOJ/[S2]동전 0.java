/**
* 문제 링크 : https://www.acmicpc.net/problem/11047
* (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)
* 문제에서 모든 동전은 배수의 형태를 이루고 있으므로, 큰 동전부터 차례로 주는 그리디 방식을 사용하는 경우 무조건 작은 동전을 주는 것보다 적은 수로 돈전을 주게 된다.
* 따라서 큰 동전부터 그리디한 방식으로 문제를 해결한다.
*/


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
	static int N, M;
	static int[] arr;
	static int answer = 0;
	static int money;
	static void solve() {
		for(int i = N-1; i >=0; i--) {
			if(money >= arr[i]) {
				answer += money / arr[i];
				money %= arr[i];
			}
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); //선언
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		money = Integer.parseInt(st.nextToken());
		arr = new int[N];
		for(int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		solve();
		System.out.println(answer);
	}
}
