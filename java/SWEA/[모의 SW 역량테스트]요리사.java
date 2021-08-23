package com.ssafy.algo;

import java.io.*;
import java.util.*;

public class Solution4012_김경준 {
	static int T, N, answer;
	static int map[][];
	static int[] idn;
	static int[] arr;
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			N = Integer.parseInt(br.readLine());
			map = new int[N][N];
			for(int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j = 0; j < N; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			answer = Integer.MAX_VALUE;
			arr = new int[N];
			combi();
			sb.append("#").append(tc).append(" ").append(answer).append("\n");
		}
		System.out.print(sb);
	}
	static void solve() {
		int fst = 0;
		int snd = 0;
		for(int i = 0; i < N; i++) {  // 1과 같은그룹 , 2와 같은그룹,,,
			if(idn[i] == 1) {
				for(int j = 0; j < N; j++) {
					if(i != j && idn[j] == 1) fst += map[i][j];
				}
			}else {
				for(int j = 0; j < N; j++) {
					if(i != j && idn[j] == 0) snd += map[i][j];
				}
			}
		}
		int num = Math.abs((fst - snd));
		answer = Math.min(answer, num);
	}
	static void combi() {
		idn = new int[N];
		for(int i = N/2; i < N; i++) idn[i] = 1;
		do {  // nC(n/2) 구하기  --> 1: A그룹, 0 : B그룹
			solve();
		}while(next_permutation(idn));
	}
	static boolean next_permutation(int[] arr) {
		int N = arr.length;

		int i = N - 1;
		while (i > 0 && arr[i - 1] >= arr[i]) --i;
		if (i == 0) return false;

		int j = N - 1;
		while (arr[i - 1] >= arr[j]) --j;
		swap(arr, i - 1, j);

		int k = N - 1;
		while (i < k) swap(arr, i++, k--);
		return true;
	}

	static void swap(int[] arr, int fst, int snd) {
		int temp = arr[fst];
		arr[fst] = arr[snd];
		arr[snd] = temp;
	}
}
