import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static int table[][][]=new int[1300][130][70];
	public static boolean vis[][][]=new boolean [1300][130][70];
	public static int dx[]={0,0,1,0,0,-1};
	public static int dy[]= {0,1,0,0,-1,0};
	public static int dz[]= {1,0,0,-1,0,0};
	public static int m,n,l,t;
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int res=0;
		m=in.nextInt();n=in.nextInt();l=in.nextInt();t=in.nextInt();
		for(int i=0;i<l;++i)
			for(int j=0;j<m;++j)
				for(int k=0;k<n;++k)
					table[j][k][i]=in.nextInt();
		in.close();
		for(int i=0;i<l;++i)
			for(int j=0;j<m;++j)
				for(int k=0;k<n;++k)
					if(!vis[j][k][i]&&table[j][k][i]!=0)res+=bfs(j,k,i);
		System.out.print(res);
	}

	public static boolean judge(int x,int y,int z) {
		if(x<0||y<0||z<0||x>=m||y>=n||z>=l)return false;
		if(vis[x][y][z])return false;
		if(table[x][y][z]==0)return false;
		return true;
	}
	
	public static int bfs(int x,int y,int z) {
		int cnt=0;
		Queue<node> q=new LinkedList<>();
		vis[x][y][z]=true;
		q.add(new node(x,y,z));
		while(!q.isEmpty()) {
			node tmp=q.poll();
			cnt++;
			for(int i=0;i<6;++i) {
				int nx=tmp.x+dx[i];
				int ny=tmp.y+dy[i];
				int nz=tmp.z+dz[i];
				if(judge(nx,ny,nz)) {
					vis[nx][ny][nz]=true;
					q.add(new node(nx,ny,nz));
				}
			}
		}
		if(cnt>=t)return cnt;
		return 0;
	}
}

class node{
	int x,y,z;
	node(int x,int y,int z){
		this.x=x;
		this.y=y;
		this.z=z;
	}
}