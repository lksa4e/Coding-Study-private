/*
문제 링크 : https://www.acmicpc.net/problem/2529

1. 순열의 경우의 수를 먼저 구하고 그 다음에 조건 check
2. 순열의 경우의 수를 만드는 중간에 조건 check
   -> 더 빠르다.
   
순열 - dfs 백트래킹
int 범위 초과 - long 사용
*/

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigDecimal;
import java.io.FileInputStream;
import java.util.*;


public class P2529 {
	static boolean visit[] = new boolean[10];
	static boolean visit2[] = new boolean[10];
	static String arr[];
	static int N;
	static String max_str="";
	static String min_str="";
	static int flag1 = 0;
	static int flag2 = 0;
	
	static void permutation(int before_num, int depth, String str) {
		if(depth == N) {
			min_str = str;
			flag1 = 1;
			return;
		}
		
		for(int i = 0; i < 10; i++) {
			if(flag1 == 1) break;			
			if(before_num == -1) {
				visit[i] = true;
				permutation(i, 0, str + i);
				visit[i] = false;
			}else if(!visit[i]) {
				if(arr[depth].equals("<")) {
					if(before_num >= i) continue;
				}else {
					if(before_num <= i) continue;
				}
				visit[i] = true;
				permutation(i, depth + 1, str + i);
				visit[i] = false;
			}
		}
		
	}
	static void permutation2(int before_num, int depth, String str) {
		if(depth == N) {
			max_str = str;
			flag2 = 1;
			return;
		}
		for(int i = 9; i >= 0; i--) {
			if(flag2 == 1) break;
			if(before_num == -1) {
				visit2[i] = true;
				permutation2(i, 0, str + i);
				visit2[i] = false;
			}else if(!visit2[i]) {
				if(arr[depth].equals("<")) {
					if(before_num >= i) continue;
				}else {
					if(before_num <= i) continue;
				}
				visit2[i] = true;
				permutation2(i, depth + 1, str + i);
				visit2[i] = false;
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in)); //선언
		N = Integer.parseInt(bf.readLine());
		String s = bf.readLine(); //String
		StringTokenizer st = new StringTokenizer(s);
		arr = s.split(" ");
		permutation(-1, 0, "");
		permutation2(-1, 0, "");
		System.out.println(max_str);
		System.out.println(min_str);
	}

}


