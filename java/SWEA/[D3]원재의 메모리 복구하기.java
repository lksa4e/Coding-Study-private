import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
	static int T;
	static String s;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		T = Integer.parseInt(br.readLine());
		for(int i = 1; i <= T; i++) {
			s = br.readLine();
			char flag = '0';
			int answer = 0;
			for(int j = 0; j < s.length(); j++) {
				if(s.charAt(j) != flag) {
					answer++;
					if(flag == '1') flag = '0';
					else flag = '1';
				}
			}
			System.out.println("#"+ i + " " +answer);
		}
	}
}
