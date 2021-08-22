package com.ssafy.algo;

import java.io.*;
import java.util.*;

public class Main15686_김경준 {
	static int N, M, house_num, chicken_num, answer = Integer.MAX_VALUE;
	static int[] idn; // 조합 생성용 
	static List<Pair> chickens = new ArrayList<Pair>();  // 치킨집 리스트
	static List<Pair> houses = new ArrayList<Pair>();  // 가정집 리스트
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		// 입력
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				int num = Integer.parseInt(st.nextToken());
				if (num == 2) {
					chicken_num++;
					chickens.add(new Pair(i,j));
				}
				if (num == 1) {
					house_num++;
					houses.add(new Pair(i,j));
				}
			}
		}
		solve();
		System.out.println(answer);
	}
	static void solve() {
		//조합 만들기
		idn = new int[chicken_num];
		for(int i = 0; i < chicken_num - M; i++) idn[i] = 0;
		for(int i = chicken_num - M; i < chicken_num ; i++) idn[i] = 1;
		// M개 치킨집을 만드는 각 조합에 대해
		do {
			search();
		}while(next_permutation(idn));
	}
	
	static void search() {  // house[i] * chicken[j] 반복하며 각 집에서의 치킨집 거리 중 최단거리 구하고 최단거리의 합
		int middle = 0; // 해당 조합에서의 치킨거리
		for(int i = 0; i < house_num; i++) {
			int dist = Integer.MAX_VALUE;
			for(int j = 0; j < chicken_num; j++) {
				if(idn[j] != 0) dist = Math.min(dist,Math.abs(chickens.get(j).x - houses.get(i).x) + Math.abs(chickens.get(j).y - houses.get(i).y));
			}
			middle += dist;
		}
		answer = Math.min(answer, middle); // 도시의 치킨거리
	}
	static boolean next_permutation(int[] arr) {  // 다음 순열 만들기
		int N = arr.length;

		int i = N - 1;
		while (i > 0 && arr[i - 1] >= arr[i])
			--i;
		if (i == 0)
			return false;

		int j = N - 1;
		while (arr[i - 1] >= arr[j])
			--j;
		swap(arr, i - 1, j);

		int k = N - 1;
		while (i < k)
			swap(arr, i++, k--);
		return true;
	}

	static void swap(int[] arr, int fst, int snd) {
		int temp = arr[fst];
		arr[fst] = arr[snd];
		arr[snd] = temp;
	}
}
class Pair {
	int x, y;

	public Pair(int x, int y) {
		this.x = x;
		this.y = y;
	}
}
