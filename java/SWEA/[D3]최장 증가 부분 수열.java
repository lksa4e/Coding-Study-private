import java.io.*;
import java.util.*;

public class Solution3307_김경준 {
	static int N,T;

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = null;
		
		T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			N = Integer.parseInt(br.readLine());
			
			int arr[] = new int[N];
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < N; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}
			
			List<Integer> lis = new ArrayList<Integer>();  // lis를 만들어줄 arraylist
			for(int i = 0; i < N; i++) {
				if(i == 0) lis.add(arr[i]); // 초기상태는 무조건 add
				else {
					if(lis.get(lis.size()-1) < arr[i]) lis.add(arr[i]);  // 가장 뒤의 값보다 크면 -> lis 증가 
					else {
						int index = Collections.binarySearch(lis, arr[i]); // 아닌 경우 lis에 들어갈 위치 찾기
						if(index < 0) index = -(index + 1);
						lis.set(index, arr[i]);
					}
				}
			}
			sb.append("#"+tc+" "+lis.size()+"\n");
		}
		System.out.print(sb);
	}
}