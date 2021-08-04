/*
문제 링크 : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LrsUaDxcDFAXc
문제 풀이
문제풀이의 핵심 원리는 현재일 기준으로 앞으로 남은 날 중 더 비싸게 팔 수 있는 경우의 수가 있는 경우를 확인하고,
내가 현재 팔 수 있는 최대 금액인 경우에 판매하는 것이다.

1. 앞에서부터 탐색하면서 i 번째일 때 남은 날 중 더 비싸게 팔 수 있는 경우가 있는지 체크
2. 뒤에서부터 탐색하면서 새롭게 더 비싸게 팔 수 있는 경우가 있으면 최대값을 change

  ==> 뒤에서부터 탐색하다가 기존의 최대값보다 더 큰 값이 나오게 된다면?
      (앞에서부터 계산했을 때) 해당 위치에서 지금까지 구매한 물건들을 팔고 뒤쪽 물건들을 다시 구매할 것이다.
      따라서 더 큰 값이 나오게 된다면 최대값을 해당 위치의 값으로 change 해 준다.
*/

import java.util.*;
import java.io.FileInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		//System.setIn(new FileInputStream("res/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		int T, N, a;
		String s;
		
		T = Integer.parseInt(br.readLine());
		for(int i = 1; i <= T; i++) {            //Test Case
			long answer = 0;
			N = Integer.parseInt(br.readLine());
			int arr[] = new int[N + 1];
			st = new StringTokenizer(br.readLine());
			for(int j = 1; j <= N; j++) {
				arr[j] = Integer.parseInt(st.nextToken());
			}
			int temp_max = 0;
			for(int j = N; j > 0; j--) {
				if(arr[j] < temp_max) {
					answer += temp_max - arr[j];
				}else {
					temp_max = Math.max(temp_max, arr[j]);
				}
			}
			System.out.println("#" + i + " "+ answer);
		}
	}
}
