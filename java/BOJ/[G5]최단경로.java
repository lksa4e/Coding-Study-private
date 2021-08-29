import java.io.*;
import java.util.*;

public class Main1753_김경준 {
	static int V,E,K;
	static int dist[];
	static List<List<Pair>> list = new ArrayList<List<Pair>>();
	static StringBuilder sb = new StringBuilder();

	static class Pair implements Comparable<Pair> {  // Vertex, w 표현을 위한 Pair 클래스
		int idx, cost;
		public Pair(int idx, int cost) {
			this.idx = idx;
			this.cost = cost;
		}
		@Override
		public int compareTo(Pair o) {
			return Integer.compare(this.cost, o.cost);
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(br.readLine());
		init();
		for(int i = 0; i < E ; i++) {
			st = new StringTokenizer(br.readLine());
			int fst = Integer.parseInt(st.nextToken());
			int snd = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			list.get(fst).add(new Pair(snd,w));  // 방향 그래프 -> 한쪽만 지정
		}
		dijk(K);
		for(int i = 1; i <= V; i++) {
			// 다익스트라 완료 후 dist[i]가 초기값인 경우 -> 도달할 수 없음 -> INF 출력
			if(dist[i] == Integer.MAX_VALUE) sb.append("INF" + "\n");
			else sb.append(dist[i] + "\n");
		}
		System.out.print(sb);
	}
	
	static void dijk(int start) {
		PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
		pq.offer(new Pair(start, 0));
		dist[start] = 0;
		while(!pq.isEmpty()) {
			Pair current = pq.poll();
			if(dist[current.idx] < current.cost) continue;  //기존 최단경로보다 더 긴 루트로 온 경우 ->pass
			
			for(int i = 0; i < list.get(current.idx).size(); i++) {
				int nidx = list.get(current.idx).get(i).idx;  // 다음 vertex의 index
				int ncost = dist[current.idx] + list.get(current.idx).get(i).cost; // 다음 vertex까지의가중치합
				if(dist[nidx] > ncost) {
					dist[nidx] = ncost;
					pq.offer(new Pair(nidx, ncost));
				}
			}
		}
	}
	static void init() {  // 사용하는 변수, 배열 초기화
		dist = new int[V + 1];
		for(int i = 1; i <= V; i++) dist[i] = Integer.MAX_VALUE;
		list = new ArrayList<List<Pair>>();
		for(int i = 0; i <= V ; i++) 
			list.add(new ArrayList<Pair>());
	}
}


