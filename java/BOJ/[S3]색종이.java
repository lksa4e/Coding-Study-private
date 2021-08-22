package com.ssafy.algo;

import java.io.*;
import java.util.*;
/**
 * BOJ 2630 색종이 : https://www.acmicpc.net/problem/2630
 * 전체 종이가 모두 같은 색으로 칠해져 있지 않으면 4등분 한다.
 * 위의 과정으로 잘라진 종이가 모두 같은 색으로 칠해져 있을때까지 반복
 * 
 * 1. 주어진 정사각형(왼쪽 위 [x][y], 길이 N) 이 모두 같은 색으로 되어있는지 확인
 *    1.1 모두 같은색이라면?
 *         - 파란색 / 흰색 ++
 *    1.2 다른색이라면 -> 4등분
 *         -  1사분면 == x , y , N/2
 *         -  2사분면 == x, y + N/2 , N/2
 *         -  3사분면 == x + N/2, y, N/2
 *         -  4사분면 == x + N/2 , y + N/2 , N/2
 */
public class Main2630_김경준 {
	static int N, white = 0, blue = 0;
	static int map[][];
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		N = Integer.parseInt(br.readLine());
		map = new int[N][N];
		// 입력
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		solve(0,0,N);
		System.out.println(white);
		System.out.println(blue);
	}
	// 모두 같은색인지 체크하고, 다른 색이면 4등분 시키는 분할정복 함수
	// x,y : 정사각형의 왼쪽 위 좌표 ㅡㅡ len : 정사각형의 한 변의 길이
	static void solve(int x, int y, int len) {   
		boolean flag = check(x,y,len);
		if(flag == true) { // 모두 같은색
			if(map[x][y] == 1) blue++;  // 시작점이 파랭이면 파랭이++
			else white++;
			return;
		}else {  //
			solve(x, y, len/2);           // 4등분이니 왼쪽 위
			solve(x + len/2, y, len/2);
			solve(x, y + len / 2, len/2);
			solve(x + len/2, y + len / 2, len/2);
		}
	}
	
	static boolean check(int x, int y, int len) {  // 시작점을 기준으로 주어진 정사각형을 전체 탐색하면서 시작점과 같은지 판단.
		int flag = map[x][y];
		for(int i = x; i < x + len; i++) {
			for(int j = y; j < y + len; j++) {
				if(map[i][j] != flag) return false;   // 하나라도 다른게 나오면 false 리턴
			}
		}
		return true;
	}	
}
