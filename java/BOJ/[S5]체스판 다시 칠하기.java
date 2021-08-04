/**
* 첫 시작이 B일 경우의 목표배열,
* 첫 시작이 W일 경우의 목표배열을 미리 선언해두고, 현재 배열과 비교하여 다른 개수를 카운팅 한다.
* 카운팅 개수 중 최소값을 구한다.
* 전체 배열에 대하여 만들 수 있는 모든 8*8 배열에 대해 위의 동작을 반복한 뒤 전체 값 중 최소값을 구한다.
*/

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
	static char[][] arr;
	static char[][] black  = {                  //왼쪽 위가 B인 경우의 목표 배열
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'}
	};
	static char[][] white  = {                // 왼쪽 위가 W인 경우의 목표 배열
			{'W','B','W','B','W','B','W','B'},
			{'B','W','B','W','B','W','B','W'},
			{'W','B','W','B','W','B','W','B'},
			{'B','W','B','W','B','W','B','W'},
			{'W','B','W','B','W','B','W','B'},
			{'B','W','B','W','B','W','B','W'},
			{'W','B','W','B','W','B','W','B'},
			{'B','W','B','W','B','W','B','W'},
		};
	static int solve(int x, int y) {          // 8*8 배열에서 BWBW,,, WBWB,,, 를 만들기 위한 최소개수 카운팅
		int ans1 = 0;
		int ans2 = 0;
		for(int i = 0; i < 8; i++) {
			for(int j = 0; j < 8; j++) {
				if(arr[i+x][j+y] != black[i][j]) ans1++;
				if(arr[i+x][j+y] != white[i][j]) ans2++;
			}
		}
		return Math.min(ans1, ans2);
	}
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("Test5.txt"));
		Scanner sc = new Scanner(System.in);
		// 구현하세요.
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		arr = new char[n][m];
		for(int i = 0; i < n; i++) {
			 String str = sc.next();
			 for(int j = 0; j < str.length();j++) {
				 arr[i][j] = str.charAt(j);
			 }
		}
		int answer = 999999;
		for(int i = 0; i < n; i++) {                         //모든 배열에 대해 탐색
			for(int j = 0; j < m; j++) {
				if(i + 8 <= n && j + 8 <= m) {
					answer = Math.min(answer, solve(i,j));
				}
			}
		}
		System.out.println(answer);
	}
}
