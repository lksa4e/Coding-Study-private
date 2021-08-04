/**
* 문제 링크 : https://www.acmicpc.net/problem/1181
1. Comparator 구현

Collections.sort(origin, new Comparator<String>() {
//	        @Override
//	        public int compare(String s1, String s2) {
//	        	if(s1.length() == s2.length()) return s1.compareTo(s2);
//	        	else return s1.length() - s2.length();
//	        }
//	    });

2. method 선언

public static int cmp(String s1, String s2) {
		if(s1.length() == s2.length()) {
			return s1.compareTo(s2);
		}else {
			return s1.length()-s2.length();
		}
	}
  
origin.sort(Main::cmp);

3. lamda식 표현 (lamda식을 사용할 경우 하나의 조건밖에 사용 X);
Collections.sort(origin, (s1, s2) -> s1.length() - s2.length());
*
*/

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
	public static int cmp(String s1, String s2) {
		if(s1.length() == s2.length()) {
			return s1.compareTo(s2);
		}else {
			return s1.length() - s2.length();
		}
	}
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("Test5.txt"));
		Scanner sc = new Scanner(System.in);
		List<String> origin = new ArrayList<String>();
		
		int n = sc.nextInt();
		
		for(int i = 0; i < n; i++) {
			String str = sc.next();
			if(!origin.contains(str)) {
				origin.add(str);
			}
		}
		
//		Collections.sort(origin, (s1, s2) -> s1.length() - s2.length());
		origin.sort(Main::cmp);
//		
//		Collections.sort(origin, new Comparator<String>() {
//	        @Override
//	        public int compare(String s1, String s2) {
//	        	if(s1.length() == s2.length()) return s1.compareTo(s2);
//	        	else return s1.length() - s2.length();
//	        }
//	    });
		
		for(String data : origin) {
			System.out.println(data);
		}
	}
}
