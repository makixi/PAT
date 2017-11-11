import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static final int maxn=21;
	public static boolean v[][]=new boolean [maxn][maxn];
	public static boolean vis[]=new boolean [maxn];
	public static int n;
	public static boolean success;
	public static int res[]=new int[maxn];
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		Arrays.fill(vis, false);
		for(int i=0;i<maxn;++i)Arrays.fill(v[i], false);
		n=in.nextInt();
		success=false;
		for(int i=1;i<=n;++i) {
			String str=in.next();
			for(int j=0;j<n;++j) {
				if(str.charAt(j)=='W')v[i][j+1]=true;
				if(str.charAt(j)=='L')v[j+1][i]=true;
			}
		}
		vis[1]=true;
		dfs(1,1);
		if(!success)System.out.print("No Solution");
		else
			for(int i=1;i<=n;++i) {
				if(i!=1)System.out.print(" ");
				System.out.print(res[i]);
			}
	}
	
	public static void dfs(int u,int cnt) {
		if(success)return;
		res[cnt]=u;
		if(cnt==n&&v[u][1]) {
			success=true;
			return;
		}
		if(cnt>=n)return;
		boolean flag=false;
		for(int i=1;i<=n;++i)
			if(!vis[i]&&v[i][1]) {
				flag=true;
				break;
			}
		if(!flag)return;
		for(int i=1;i<=n;++i)
			if(!vis[i]&&v[u][i]) {
				vis[i]=true;
				dfs(i,cnt+1);
				vis[i]=false;
			}
	}
	
}

