import java.io.*;
import java.util.*;

public class BOJ2239_스도쿠 {
	static int map[][] = new int[9][9];
	static boolean row_visit[][] = new boolean[9][9];          
	static boolean col_visit[][] = new boolean[9][9];
	static boolean area_visit[][][] = new boolean[3][3][9];
	static boolean find_flag = false;
	static StringBuilder sb = new StringBuilder(); 
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = null;
		for(int i = 0; i < 9; i++) {
			str = br.readLine();
			for(int j = 0; j < 9; j++) {
				map[i][j] = str.charAt(j) - '0';
				
				if(map[i][j] == 0) continue;
				
				row_visit[i][map[i][j] - 1] = true;
				col_visit[j][map[i][j] - 1] = true;
				area_visit[i / 3][j / 3][map[i][j] - 1] = true;
			}
		}
		dfs(0);
		System.out.println(sb);
	}
	
	static void dfs(int count) {
		if(count == 81) {
			find_flag = true;
			print();
			return;
		}
		
		int x = count / 9;
		int y = count % 9;
		
		if(map[x][y] == 0) {
			boolean list[] = returnPossibleNum(x, y);
			for(int i = 0; i < 9; i++) {
				if(!list[i]) {
					setVisit(x, y, i, true);
					dfs(count + 1);
					if(find_flag == true) return;
					setVisit(x,y,i, false);
				}
			}
		}else {
			dfs(count + 1);
		}
	}
	
	static void print() {
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++)
				sb.append(map[i][j]);
			sb.append("\n");
		}
	}
	
	static void setVisit(int row, int col, int num, boolean flag) {
		row_visit[row][num] = flag;
		col_visit[col][num] = flag;
		area_visit[row/3][col/3][num] = flag;
		
		map[row][col] = flag ? num + 1 : 0;
	}
	
	static boolean[] returnPossibleNum(int x, int y){
		boolean[] temp = new boolean[9];
		
		for(int i = 0; i < 9; i++) {
			if(row_visit[x][i]) temp[i] = true;
			if(col_visit[y][i]) temp[i] = true;
			if(area_visit[x/3][y/3][i]) temp[i] = true;
		}
		return temp;		
	}
}
