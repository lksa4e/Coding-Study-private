import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
	static int N, M;
	static BitSet bitset = new BitSet(20000001);
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < N; i++) {
			bitset.set(Integer.parseInt(st.nextToken()) + 10000000);
		}
		M = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < M; i++) {
			if(bitset.get(Integer.parseInt(st.nextToken()) + 10000000) == true) sb.append(1 +" ");
			else sb.append(0+" ");
		}
		System.out.print(sb.toString());
	}
}
