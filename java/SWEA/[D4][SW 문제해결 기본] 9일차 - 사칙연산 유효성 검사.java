import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Solution1233_김경준 {
	static int N, answer;
	static String[] arr;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = null;
		for(int tc = 1; tc <= 10; tc++) {
			N = Integer.parseInt(br.readLine());
			answer = 1;
			for(int i = 0; i < N; i++) {
				arr = br.readLine().split(" ");
				if(answer == 0) continue; // 연산 불가하면 아래연산 스킵
				if(arr.length == 4) {   // 자식 있을 때, 부모가 숫자면 연산 불가
					if(Character.isDigit(arr[1].charAt(0))) answer = 0;
				}else{
					switch(arr[1].charAt(0)) { // 리프노드일때 연산자면 연산 불가
					case '+': case '-': case '*': case '/':
						answer = 0;
						break;
					}
				}
			}
			sb.append("#").append(tc).append(" ").append(answer).append("\n");
		}
		System.out.println(sb.toString());
	}
}