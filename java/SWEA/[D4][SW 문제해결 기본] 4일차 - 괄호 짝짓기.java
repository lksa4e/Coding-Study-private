import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class S0805 {
	static int N, T;
	static Stack<Character> st;
	static String s;
	static int answer;
	static final Map<Character,Character> m = new HashMap<Character, Character>(){
		{put('}','{'); put(')','('); put('>','<'); put(']','[');}
	};
	private static void solve() {
		answer = 1;
		st = new Stack<Character>();
		for(int i = 0, size = s.length(); i < size; i++) {
			if(s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '[' || s.charAt(i) == '<') { // 여는 괄호는 푸쉬
				st.add(s.charAt(i));
			}else { // 닫는 괄호
				if(m.get(s.charAt(i)) != st.peek()){  // 이전 괄호랑 매칭 안되면 return
					answer = 0;
					return;
				}else st.pop(); // 매칭되면 pop
			}
		}
		if(!st.isEmpty()) answer = 0;
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		for(int t = 1; t <= 10; t++){
			br.readLine();
			s = br.readLine();
			solve();
			System.out.println("#"+ t +" "+ answer);
		}
	}
}
