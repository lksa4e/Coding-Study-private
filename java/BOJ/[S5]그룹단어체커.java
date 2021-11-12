import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class BOJ1316_S5_그룹단어체커 {
	static int N,M;
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();
		
		Map<String, String> pokemon = new HashMap<String, String>();
		N = Integer.parseInt(br.readLine());
		int count = 0;
		
		for(int i = 1; i <= N; i++) {
			String str = br.readLine();
			boolean visit[] = new boolean[26];
			char before_char = str.charAt(0);
			boolean flag = true;
			for(int j = 0; j < str.length(); j++) {
				char current_char = str.charAt(j);
				
				if(before_char != current_char) {
					visit[before_char-'a'] = true;
					if(visit[current_char-'a'] == true) {
						flag = false;
						break;
					}
					before_char = current_char;
				}
			}
			if(flag) count++;
		}
		
		System.out.print(count);
	}
}
