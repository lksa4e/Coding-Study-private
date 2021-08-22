package com.ssafy.algo;

import java.io.*;
import java.util.*;

public class Main17135_김경준 {
	static int N, M, D, real_unit_count = 0, unit_count = 0, kill = 0, answer = 0; // origin 전체유닛, 조합마다 전체유닛
	static int[][] real_map, map;  // origin 지도, 조합마다 지도
	static int[] idn; // 조합 생성용 
	static Pair[] archer = new Pair[3]; // 궁수 좌표
	static Pair[] kill_list;  // 죽일 타겟 좌표
	static boolean visit[][]; // bfs 방문
	static int[] dx = { 0, -1, 0 }; // 좌 상 우
	static int[] dy = { -1, 0, 1 };
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		real_map = new int[N][M];
		map = new int[N][M];
		// 입력
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				real_map[i][j] = Integer.parseInt(st.nextToken());
				if (real_map[i][j] != 0)
					real_unit_count++;  // 잔여적군 수 카운트
			}
		}
		set_after_kill(); 
		System.out.println(answer);
	}

	static void init() {  // 변수 초기화, 지도 초기화
		unit_count = real_unit_count;
		kill = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				map[i][j] = real_map[i][j];
		}
	}

	static void set_after_kill() {  // 궁수 세팅 -> 목표 설정 -> 목표 kill -> 적군 이동
		idn = new int[M];
		for (int i = 0; i < M - 3; i++)
			idn[i] = 0;
		for (int i = M - 1; i >= M - 3; i--)
			idn[i] = 1;
		do {
			init(); // map, unitcount, kill 초기화
			int cnt = 0;
			for (int i = 0; i < M; i++) { // Combination을 통한 궁수 3명 선택
				if (idn[i] == 1) {
					archer[cnt++] = new Pair(N - 1, i);
				}
			}
			while (unit_count > 0) { // 해당 조합으로 게임 한번씩 진행
				kill_list = new Pair[3];  // 죽일 타겟
				for (int i = 0; i < 3; i++) {
					set_enemy(archer[i].x, archer[i].y, i); // BFS 탐색을 통한 궁수 3명 타겟지정
				}
				kill_enemy(); // kill
				enemy_go(); // 적군 전진
			}
			set_max(); // 최대값 세팅
		} while (next_permutation(idn));
	}

	static void set_enemy(int x, int y, int num) {
		Deque<Pair> q = new ArrayDeque<Pair>();
		visit = new boolean[N][M];
		q.offer(new Pair(x, y));
		visit[x][y] = true;
		int cnt = 1;
		while (!q.isEmpty()) {
			if (cnt > D) return;  // 이동거리 벗어나면 return
			int size = q.size();
			while (size-- > 0) {
				Pair current = q.poll();
				if (map[current.x][current.y] == 1) {  // 이동거리 내에 적군 있으면 kill_list에 추가
					kill_list[num] = new Pair(current.x, current.y);
					return;
				}
				for (int i = 0; i < 3; i++) {
					int nx = current.x + dx[i];
					int ny = current.y + dy[i];
					if (!oob(nx, ny) && !visit[nx][ny]) {
						visit[nx][ny] = true;
						q.offer(new Pair(nx, ny));
					}
				}
			}
			cnt++;
		}
	}

	static void kill_enemy() {  // 목표 타겟 죽이기 
		for (int i = 0; i < 3; i++) {
			if (kill_list[i] != null && map[kill_list[i].x][kill_list[i].y] == 1) {  // i번째 궁수가 맞출 타겟이 존재하고, 타겟 생존해있을경우
				map[kill_list[i].x][kill_list[i].y] = 0;
				kill++;
				unit_count--;
			}
		}
	}

	static void set_max() {  // 최대값 갱신
		answer = Math.max(kill, answer);
	}

	static void enemy_go() {   // 맨아랫줄 유닛 죽이고, 한칸씩 아래로 당기고, 맨 윗줄 0
		for (int i = 0; i < M; i++) {
			if (map[N - 1][i] == 1)
				unit_count--;
		}
		for (int i = N - 1; i > 0; i--) {
			for (int j = 0; j < M; j++)
				map[i][j] = map[i - 1][j];
		}
		for (int i = 0; i < M; i++)
			map[0][i] = 0;
	}

	static boolean oob(int x, int y) { // 경계체크
		return x < 0 || x >= N || y < 0 || y >= M;
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