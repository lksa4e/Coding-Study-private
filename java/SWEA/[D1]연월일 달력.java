/*
문제 링크 : https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QLkdKAz4DFAUq
substring을 통해 슬라이스를 한 후, switch case를 통해 월마다 날짜 검사를 한다.
*/
 
import java.util.*;
import java.io.FileInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		
		System.setIn(new FileInputStream("res/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N, a, b, sum = 0;
		String str;
		N = Integer.parseInt(br.readLine());
		for(int i = 1; i <= N; i++) {
			int flag = 0;
			str = br.readLine();
			int month = Integer.parseInt(str.substring(4, 6));
			int day = Integer.parseInt(str.substring(6, 8));
			switch(month) {
			case 0:
				flag = 1;
				break;
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if(day == 0 || day > 31) flag = 1;
				break;
			case 2:
				if(day == 0 || day > 28) flag = 1;
			default:
				if(day == 0 || day > 30) flag = 1;
			}
			System.out.print("#"+ i +" ");
			if(flag == 1) {
				System.out.println(-1);
			}else {
				for(int j = 0; j < 8; j++) {
					System.out.print(str.charAt(j));
					if(j == 3 || j == 5) System.out.print('/');
				}
				System.out.println();
			}
		}
		//System.out.println("#" + i + " " + arr[N/2]);
	}
}
