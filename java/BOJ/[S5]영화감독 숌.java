/*
* 문제 링크 : https://www.acmicpc.net/problem/1436
666이 들어가는 10000개의 숫자를 순서대로 세도 1억의 범위를 넘어가지 않는다. 따라서 모든 경우를 탐색하는
부르트 포스 알고리즘으로 해결할 수 있다.
*/
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
	
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("Test5.txt"));
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int num = 0;
		String str="";
		for(int i = 666; i <= 99999999; i++) {
			str = Integer.toString(i);
			if(str.contains("666")) num++;
			if(num == N) break;
		}
		System.out.println(Integer.parseInt(str));
	}
}
