import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	public static final int maxn=1010;
	public static boolean vis[]=new  boolean [maxn];
	public static int ans[]=new int[maxn];
	public static int n,cnt=0;
	public static List<ArrayList<Integer>>v=new ArrayList<ArrayList<Integer>>();
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		for(int i=0;i<maxn;++i)v.add(new ArrayList<>());
		n=in.nextInt();
		for(int i=1;i<=n;++i) {
			int k=in.nextInt();
			for(int j=0;j<k;++j) {
				int tmp=in.nextInt();
				v.get(i).add(tmp);
				v.get(tmp).add(i);
			}
		}
		int res=0;
		for(int i=1;i<=n;++i) {
			Queue<Integer> q=new LinkedList<>();
			q.add(i);
			if(!vis[i])++cnt;
			for(int j=1;j<=n;++j)ans[j]=0;
			ans[i]=1;
			while(!q.isEmpty()) {
				int u=q.poll();
				vis[u]=true;
				res=Math.max(res, ans[u]-2);
				for(int j=0;j<v.get(u).size();++j) {
					if(ans[v.get(u).get(j)]!=0)continue;
					ans[v.get(u).get(j)]=ans[u]+1;
					q.add(v.get(u).get(j));
				}
			}
		}
		System.out.print(cnt+" "+res);
	}

}

