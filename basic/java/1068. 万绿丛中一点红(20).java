import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int m=in.nextInt(),n=in.nextInt(),tol=in.nextInt();
		int [][]maze=new int [n][m];
		Map<Integer,Integer> mark=new HashMap<>();
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j) {
				maze[i][j]=in.nextInt();
				int tmp;
				if(mark.get(maze[i][j])==null) {
					tmp=0;
				}
				else {
					tmp=mark.get(maze[i][j]);
					mark.remove(maze[i][j]);
				}
				
				mark.put(maze[i][j], tmp+1);
			}
		in.close();
		int dx[]= {0,0,1,-1,1,-1,1,-1};
		int dy[]= {1,-1,0,0,1,-1,-1,1};
		int cnt=0,x=0,y=0,res=0;
		for(int i=0;i<n;++i) {
			for(int j=0;j<m;++j) {
				if(mark.get(maze[i][j]).intValue()==1) {
					boolean flag=true;
					for(int k=0;k<8;++k) {
						int ni=i+dx[k];
						int nj=j+dy[k];
						if(ni>=0&&nj>=0&&ni<n&&nj<m&&Math.abs(maze[i][j]-maze[ni][nj])<=tol)flag=false;
					}
					if(flag) {
						cnt++;
						x=i;y=j;
						res=maze[i][j];
					}
				}
			}
		}
		if (cnt == 0)System.out.print("Not Exist");
		else if (cnt > 1) System.out.print("Not Unique");
		else System.out.print("("+(y+1)+", "+(x+1)+"): "+res);
	}
	
}
