package com.ssafy.algo;

import java.io.*;
import java.util.*;

public class Solution5644_김경준 {
	static int T, move, bc_num, a_x = 1, a_y = 1, b_x = 10, b_y= 10, answer;
	static ArrayList<Pair> map[][] = new ArrayList[11][11];
	static Charger[] c_List;
	static int a_dir[], b_dir[];
	static int[] dx = {-1,0,1,0}, dy = {0,1,0,-1};  // 상 우 하 좌
	static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			move = Integer.parseInt(st.nextToken());
			bc_num = Integer.parseInt(st.nextToken());	
			
			init();
			
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < move; j++) {
				a_dir[j] = Integer.parseInt(st.nextToken());
			}
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < move; j++) {
				b_dir[j] = Integer.parseInt(st.nextToken());
			}
			for(int j = 0; j < bc_num; j++) {
				st = new StringTokenizer(br.readLine());
				int y = Integer.parseInt(st.nextToken());
				int x = Integer.parseInt(st.nextToken());
				int c = Integer.parseInt(st.nextToken());
				int p = Integer.parseInt(st.nextToken());
				c_List[j] = new Charger(x, y, c, p);
			}
			
			setting();
			solve();
			for(int i = 0; i < move; i++) {
				if(a_dir[i] != 0) {
					a_x += dx[a_dir[i] - 1];
					a_y += dy[a_dir[i] - 1];
				}
				if(b_dir[i] != 0) {
					b_x += dx[b_dir[i] - 1];
					b_y += dy[b_dir[i] - 1];
				}
				solve();
			}
			sb.append("#").append(tc).append(" ").append(answer).append("\n");
		}
		System.out.print(sb);
	}
	static void init() {
		a_x = a_y = 1;
		b_x = b_y = 10;
		a_dir = new int[move];
		b_dir = new int[move];
		answer = 0;
		for(int i = 1; i <= 10; i++) {
			for(int j = 1; j <= 10; j++) {
				map[i][j] = new ArrayList<Pair>();
			}
		}
		c_List = new Charger[bc_num];
	}
	static void solve() {
		if(map[a_x][a_y].isEmpty()) { // a가 충전시킬 곳 없을 때
			if(!map[b_x][b_y].isEmpty()) {  // a는 충전시킬 곳 없고 b는 충전시킬 곳 있음
				Collections.sort(map[b_x][b_y]);
				answer += map[b_x][b_y].get(map[b_x][b_y].size()-1).x;
			}
		}else { // a 충전시킬 곳 있음
			if(map[b_x][b_y].isEmpty()) {  // a는 충전시킬 곳 있고, b는 없음
				Collections.sort(map[a_x][a_y]);
				answer += map[a_x][a_y].get(map[a_x][a_y].size()-1).x;
			}else { // a b 둘 다 충전시킬 곳 있음
				//case 1. 둘 다 쓸 곳이 한 곳밖에 없음
				if(map[a_x][a_y].size() == 1 && map[b_x][b_y].size() == 1) {
					// 둘이 같은 곳 공유 -> 나눠쓰기
					if(map[a_x][a_y].get(0).y == map[b_x][b_y].get(0).y) {
						answer += map[a_x][a_y].get(0).x;
					}else { // 둘이 다른 곳 사용
						answer += map[a_x][a_y].get(0).x;
						answer += map[b_x][b_y].get(0).x;
					}
				}else{ //case 2. 둘이 각자 쓸 곳 있음
					if(map[a_x][a_y].size() == 1 && map[b_x][b_y].size() > 1) {  // a는 한개, b는 여러개
						Collections.sort(map[b_x][b_y]);
						if(map[a_x][a_y].get(0).y == map[b_x][b_y].get(map[b_x][b_y].size()- 1).y) {  // a b 같은곳 공유 b는 다른선택지 존재
							answer += map[a_x][a_y].get(0).x;
							answer += map[b_x][b_y].get(map[b_x][b_y].size() - 2).x;
						}else {  // a b 다른곳 b 제일 큰거
							answer += map[a_x][a_y].get(0).x;
							answer += map[b_x][b_y].get(map[b_x][b_y].size() - 1).x;
						}
					}else if (map[a_x][a_y].size() > 1 && map[b_x][b_y].size() == 1) {  // a는 여러개, b는 한개
						Collections.sort(map[a_x][a_y]);
						if(map[b_x][b_y].get(0).y == map[a_x][a_y].get(map[a_x][a_y].size()- 1).y) {
							answer += map[b_x][b_y].get(0).x;
							answer += map[a_x][a_y].get(map[a_x][a_y].size() - 2).x;
						}else {
							answer += map[b_x][b_y].get(0).x;
							answer += map[a_x][a_y].get(map[a_x][a_y].size() - 1).x;
						}
					}else {  // a도 여러개 b도 여러개
						Collections.sort(map[a_x][a_y]);
						Collections.sort(map[b_x][b_y]);
						// 둘의 최고치가 같을 때
						if(map[a_x][a_y].get(map[a_x][a_y].size() - 1).y == map[b_x][b_y].get(map[b_x][b_y].size() - 1).y) {
							if(map[a_x][a_y].get(map[a_x][a_y].size() - 2).x <= map[b_x][b_y].get(map[b_x][b_y].size() - 2).x) { // b 줄이는게 이득이면
								answer += map[a_x][a_y].get(map[a_x][a_y].size() - 1).x;
								answer += map[b_x][b_y].get(map[b_x][b_y].size() - 2).x;
							}else { // a 줄이는게 이득이면 
								answer += map[a_x][a_y].get(map[a_x][a_y].size() - 2).x;
								answer += map[b_x][b_y].get(map[b_x][b_y].size() - 1).x;
							}
						}else {
							answer += map[a_x][a_y].get(map[a_x][a_y].size() - 1).x;
							answer += map[b_x][b_y].get(map[b_x][b_y].size() - 1).x;
						}
					}
				}
			}
		}
	}
	static void setting() {
		// 충전기로 맵 세팅
		for(int i = 0; i < bc_num; i++) {
			mapSetting(c_List[i], i);
		}
	}
	static void mapSetting(Charger bc, int bcNum) {
		Queue<Pair> q = new ArrayDeque<Pair>();
		boolean[][] visit = new boolean[11][11];
		visit[bc.x][bc.y] = true;
		map[bc.x][bc.y].add(new Pair(bc.p, bcNum));
		q.offer(new Pair(bc.x,bc.y));
		int cnt = 1;
		while(!q.isEmpty()) {
			int size = q.size();
			while(size-->0) {
				Pair cur = q.poll();
				for(int i = 0; i < 4; i++) {
					int nx = cur.x + dx[i];
					int ny = cur.y + dy[i];
					if(!oob(nx,ny) && !visit[nx][ny]){
						visit[nx][ny] = true;
						map[nx][ny].add(new Pair(bc.p, bcNum));
						q.offer(new Pair(nx,ny));
					}
				}
			}
			if(cnt == bc.c) break;
			cnt++;
		}
	}
	static boolean oob(int x, int y) {
		return x < 1 || x >= 11 || y < 1 || y >= 11;
	}
}
class Pair implements Comparable<Pair>{
	int x, y;
	public Pair(int x, int y){
		this.x = x; this.y = y;
	}
	@Override
	public int compareTo(Pair o) {
		return this.x - o.x;
	}
}
class Charger{
	int x, y, c, p;  // xy 좌표, 범위, 성능
	public Charger(int x, int y, int c, int p) {
		this.x = x; this.y = y; this.c = c; this.p = p;
	}
}
