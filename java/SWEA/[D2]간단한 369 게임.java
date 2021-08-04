/*
문제 링크 : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PTeo6AHUDFAUq&
문제 풀이
1 ~ N 까지 반복문 탐색
  숫자 길이만큼 탐색(to_string)
    3 || 6 || 9 가 들어간 개수 찾기
  3,6,9가 들어갔으면 박수
  안들어갔으면 원래숫자 출력
*/

import java.util.*;
import java.io.FileInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		System.setIn(new FileInputStream("res/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		int T, N, a;
		String s;
		N = Integer.parseInt(br.readLine());
		for(int i = 1; i <= N; i++) {
			String temp = Integer.toString(i);
			int cnt = 0;
			for(int j = 0; j < temp.length(); j++) {
				if(temp.charAt(j)-'0' == 3 || temp.charAt(j)-'0' == 6 || temp.charAt(j)-'0' == 9){
					cnt++;
				}
			}
			if(cnt > 0) {
				for(int k = 0; k < cnt; k++) {
					System.out.print("-");
				}
				System.out.print(" ");
			}else {
				System.out.print(i+" ");
			}
		}
	}
}
