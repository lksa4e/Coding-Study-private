import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Solution {
	static int N;
	static int answer = 0;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int tc = 1; tc <= 10; tc++) {			
			PriorityQueue<Integer> pq1 = new PriorityQueue<Integer>();  // 오름차
			PriorityQueue<Integer> pq2 = new PriorityQueue<Integer>(Collections.reverseOrder()); // 내림차
			N = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i = 0; i < 100; i++) {
				int num = Integer.parseInt(st.nextToken());
				pq1.add(num);
				pq2.add(num);
			}
			for(int i = 0; i < N; i++) {
				int min_num = pq1.poll();
				int max_num = pq2.poll();
				pq1.add(min_num + 1);
				pq2.add(max_num - 1);
			}
			System.out.println("#"+tc+" "+(pq2.poll() - pq1.poll()));
		}
	}
}


