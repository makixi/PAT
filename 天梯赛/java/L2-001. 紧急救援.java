import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static final int maxn=510;
	public static final int inf=0x3f3f3f3f;
	public static int help[]=new int [maxn];
	public static int e[][]=new int [maxn][maxn];
	public static int dis[]=new int [maxn];
	public static int num[]=new int [maxn];
	public static int pre[]=new int [maxn];
	public static int pathnum[]=new int [maxn];
	public static boolean vis[]=new boolean [maxn];
	public static int maxhelp=0,cnt=0;
	
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt(),m=in.nextInt(),s=in.nextInt(),d=in.nextInt();
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				e[i][j]=inf;
		Arrays.fill(dis, inf);
		for(int i=0;i<n;++i)help[i]=in.nextInt();
		for(int i=0;i<m;++i) {
			int a=in.nextInt(),b=in.nextInt();
			e[a][b]=in.nextInt();e[b][a]=e[a][b];
		}
		dis[s]=0;num[s]=help[s];
		pathnum[s]=1;
		for(int i=0;i<n;++i) {
			int u=-1,minn=inf;
			for(int j=0;j<n;++j)
				if(!vis[j]&&dis[j]<minn) {
					minn=dis[j];u=j;
				}
			if(u==-1)break;
			vis[u]=true;
			for(int j=0;j<n;++j)
				if(!vis[j]&&e[u][j]!=inf) 
					if(dis[j]>dis[u]+e[u][j]) {
						dis[j]=dis[u]+e[u][j];
						pathnum[j]=pathnum[u];
						num[j]=num[u]+help[j];
						pre[j]=u;
					}else if(dis[j]==dis[u]+e[u][j]) {
						pathnum[j]+=pathnum[u];
						if(num[u]+help[j]>num[j]) {
							num[j]=num[u]+help[j];
							pre[j]=u;
						}
					}
		}
		System.out.println(pathnum[d]+" "+num[d]);
		dfs(d,s);
	}
	
	public static void dfs(int u,int s) {
		if(u==s) {
			System.out.print(u);
			return;
		}
		dfs(pre[u],s);
		System.out.print(" "+u);
	}
}
