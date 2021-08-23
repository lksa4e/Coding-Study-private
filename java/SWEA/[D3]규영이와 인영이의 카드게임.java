import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Solution6808np_김경준 {
	static int T,left_win,right_win;
	static int[] arr = new int[9];
	static int[] temp = new int[9];
	static StringBuilder sb = new StringBuilder();
	
	static void check() {
		int answer = 0;
		for(int i = 0; i < 9; i++)
			answer += (arr[i] > temp[i]) ? arr[i]+ temp[i]: -(arr[i]+temp[i]);  // 규영이가 이기면 규영이점수 아니면 반대
		if(answer > 0) left_win++;
		else right_win++;
	}
	static boolean next_permutation(int[] arr) {
		int N = arr.length;
		int i = N-1;
		// 뒤쪽 출발, 내림차 아닐 때
		while(i > 0 && arr[i-1] >= arr[i]) --i;
		if(i == 0) return false;
		
		int j = N-1;
	    // 뒤쪽 중 가장 작은숫자
		while(arr[i-1] >= arr[j]) --j;
		swap(arr, i-1,j);
		// sort
		int k = N-1;
		while(i < k) swap(arr, i++, k--);
		return true;
	}
	static void swap(int[] arr, int fst, int snd) {
		int temp = arr[fst];
		arr[fst] = arr[snd];
		arr[snd] = temp;
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			boolean[] visit = new boolean[19];
			for (int i = 0; i < 9; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
				visit[arr[i]] = true;  // 사용되었는지 아닌지 여부 체크
			}
			int cnt = 0;
			for(int i = 1; i <= 18; i++) {  // 규영이가 사용 안한 카드면 인영이한테 주기
				if(!visit[i]) temp[cnt++] = i;
			}
			left_win = 0; right_win = 0;
			Arrays.sort(temp);
			do {
				check();
			}while(next_permutation(temp));
			sb.append("#"+tc+" "+left_win+" "+right_win+"\n");
		}
		System.out.println(sb);
	}
}