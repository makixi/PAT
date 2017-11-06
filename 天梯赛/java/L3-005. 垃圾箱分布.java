import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static final int inf=0x3f3f3f3f;
	public static final int maxn=1050;
	public static int e[][]=new int[maxn][maxn];
	public static boolean vis[]=new boolean[maxn];
	public static int dis[]=new int[maxn];
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt(),m=in.nextInt(),k=in.nextInt(),ds=in.nextInt();
		Arrays.fill(e, inf);
		for(int i=0;i<k;++i) {
			int a=0,b=0;
			String s=in.next(),t=in.next();
			int tmpdis=in.nextInt();
			if(s.charAt(0)=='G') {
				s=s.substring(1);
				a=n+Integer.valueOf(s);
			}else a=Integer.valueOf(s);
			if(t.charAt(0)=='G') {
				t=t.substring(1);
				b=n+Integer.valueOf(t);
			}else b=Integer.valueOf(t);
			e[a][b]=e[b][a]=tmpdis;
		}
		int resid=-1;
		double resdis=-1,resave=inf;
		for(int curr=n+1;curr<=n+m;++curr) {
			double mindis=inf,ave=0;
			Arrays.fill(dis, inf);
			Arrays.fill(vis,false);
			dis[curr]=0;
			for(int i=0;i<n+m;++i) {
				int u=-1,minn=inf;
				for(int j-1;j<=n+m;++j)
					if(!vis[j]&&dis[j]<minn) {
						minn=dis[j];
						u=j;
					}
				if(u==-1)break;
				vis[u]=true;
				for(int j=1;j<=n+m;++j)
					if(!vis[j]&&dis[j]>dis[u]+e[u][j])
						dis[j]=dis[u]+e[u][j];
			}
			for(int i=1;i<=n;++i) {
				if(dis[i]>ds) {
					mindis=-1;break;
				}
				mindis=Math.min(mindis, dis[i]);
				ave+=1.0*dis[i];
			}
			if(mindis==-1)continue;
			ave/=n;
			if(mindis>resdis) {
				resid=curr;
				resdis=mindis;
				resave=ave;
			}else if(mindis==resdis&&ave<resave) {
				resave=ave;
				resid=curr;
			}
		}
		if(resid==-1)System.out.print("No Solution");
		else {
			System.out.println("G"+(resid-n));
			System.out.printf("%.1f %.1f", resid,resave);
		}
	}

	
	
}

