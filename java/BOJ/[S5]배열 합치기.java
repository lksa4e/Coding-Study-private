/**
문제 링크 : https://www.acmicpc.net/problem/11728
N+M 크기의 배열을 선언한 후 sort 라이브러리를 활용하던가,
merge sort를 구현하여 정렬한다.

*/
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class P11728 {
	static int N, M;
	static int[] arr1;
	static int[] arr2;
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr1 = new int[N];
		arr2 = new int[M];
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0 ; i < N; i++) arr1[i] = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0 ; i < M; i++) arr2[i] = Integer.parseInt(st.nextToken());
		
		int left_point = 0, right_point = 0;
		for(int i = 0; i < N+M; i++) {
			if(left_point == N) sb.append(arr2[right_point++]).append(" ");
			else if(right_point == M) sb.append(arr1[left_point++]).append(" ");				
			else {
				if(arr1[left_point] < arr2[right_point]) {
					sb.append(arr1[left_point++]).append(" ");
				}else sb.append(arr2[right_point++]).append(" ");				
			}
		}
		System.out.println(sb.toString());
	}
}
