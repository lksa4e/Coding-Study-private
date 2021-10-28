import java.io.*;
import java.util.*;

public class Main {
	static int num1, num2;
	static Map<Integer, String> m = new HashMap<Integer, String>();
	static Map<String, Integer> m2 = new HashMap<String, Integer>();
	static PriorityQueue<String> pq = new PriorityQueue<String>();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		init(); // Map 초기화
		num1 = Integer.parseInt(st.nextToken());
		num2 = Integer.parseInt(st.nextToken());
		for(int i = num1; i <= num2; i++) {
			pq.offer(change_itos(i));      // String 순서로 정렬하기 위해 String 우선순위 큐 사용
		}
		
		int cnt = 0;
		while(!pq.isEmpty()) {
			sb.append(change_stoi(pq.poll()) + " ");  // String으로 저장되어 있으니 int로 변환해서 출력
			cnt++;
			if(cnt % 10 == 0) sb.append("\n");
		}
		System.out.print(sb);
	}
	//String -> int 변형 함수
	static int change_stoi(String str) {
		int num = 0;
		StringTokenizer st = new StringTokenizer(str);
		
		if(st.countTokens() != 1) {  // 입력값이 10보다 커서 eigth zero 처럼 공백 기준으로 변형된 숫자인 경우
			int num1 = m2.get(st.nextToken());  // 앞쪽 알파벳을 숫자로 change
			int num2 = m2.get(st.nextToken());  // 뒤쪽 알파벳을 숫자로 change
			num = num1 * 10 + num2;             // 하나의 숫자로 합치기
		}else {
			num = m2.get(st.nextToken());       // 10보다 작은 경우 그냥 변형
		}
		return num;
	}
	// int -> String 변형 함수
	static String change_itos(int num) {
		String str = null;
		if(num < 10) str = m.get(num);             // 입력값이 10보다 작으면 그냥 단일 알파벳 변형
		else {                                     // 입력값이 10보다 크면 띄어쓰기 기준으로 2개로 나눔
			String temp1 = m.get(num / 10);        // 10의 자리 숫자 알파벳 변형
			String temp2 = " " + m.get(num % 10);  // 1의 자리 숫자 알파벳 변형
			str = temp1.concat(temp2);             // 합치기 
		}
		return str;
	}
	// String -> int , int -> String 변형을 위한 Map의 초기 세팅
	static void init() {
		m.put(0, "zero"); 
		m.put(1, "one");
		m.put(2, "two");
		m.put(3, "three");
		m.put(4, "four");
		m.put(5, "five");
		m.put(6, "six");
		m.put(7, "seven");
		m.put(8, "eight");
		m.put(9, "nine");
		m2.put("zero", 0);
		m2.put("one", 1);
		m2.put("two", 2);
		m2.put("three", 3);
		m2.put("four", 4);
		m2.put("five", 5);
		m2.put("six", 6);
		m2.put("seven", 7);
		m2.put("eight", 8);
		m2.put("nine", 9);
	}
}
