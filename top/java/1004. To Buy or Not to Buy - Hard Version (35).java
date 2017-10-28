import java.util.Arrays;
import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	
	public static final int maxn=100;
	public static boolean vis[]=new boolean [maxn];
	public static int minn,n;
	public static node want=new node();
	public static node bead[]=new node[100];
	
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		for(int i=0;i<100;++i)bead[i]=new node();
		String need=in.next();
		for(int i=0;i<need.length();++i) {
			want.total++;
			want.cnt[ver(need.charAt(i))]++;
		}
		n=in.nextInt();
		for(int i=0;i<n;++i) {
			String tmp=in.next();
			for(int j=0;j<tmp.length();++j) {
				bead[i].cnt[ver(tmp.charAt(j))]++;
				bead[i].total++;
			}
		}
		for(int i=0;i<100;++i)
			for(int j=0;j<62;++j)
				if(bead[i].cnt[j]>0&&want.cnt[j]>0)
					bead[i].used+=Math.min(bead[i].cnt[j], want.cnt[j]);
		Arrays.sort(bead,0,n);
		minn=0;
		for(int i=0;i<62;++i) 
			if(want.cnt[i]>0) {
				int x=0;
				for(int j=0;j<n;++j) {
					x+=bead[j].cnt[i];
					if(x>=want.cnt[i])break;
				}
				if(x<want.cnt[i])minn+=(want.cnt[i]-x);
			}
		if(minn>0)System.out.print("No "+minn);
		else {
			minn=0x7fffffff;
			Arrays.fill(vis, false);
			dfs(new node());
			System.out.print("Yes "+minn);
		}
	}
	
	public static int ver(int c) {
		return (c>=97?c-61:(c>=65?c-55:c-48));
	}
	
	public static boolean check(node no) {
		for(int i=0;i<62;++i)if(no.cnt[i]<want.cnt[i])return false;
		return true;
	}
	
	public static int num(node no) {
		int x=0;
		for(int i=0;i<62;++i)x+=Math.max(0, no.cnt[i]-want.cnt[i]);
		return x;
	}
	
	public static node add(node a,node b) {
		node c=new node();
		for(int i=0;i<62;++i)c.cnt[i]=a.cnt[i]+b.cnt[i];
		return c;
	}
	
	public static void dfs(node no) {
		if(minn<=num(no))return;
		if(check(no)) {
			minn=num(no);
			return;
		}
		for(int i=0;i<n;++i) {
			if(!vis[i]) {
				vis[i]=true;
				dfs(add(no,bead[i]));
				vis[i]=false;
			}
		}
	}
}

class node implements Comparable<node>{
	int cnt[]=new int [62];
	int used,total;
	
	node(){
		this.used=0;this.total=0;
		for(int i=0;i<62;++i)this.cnt[i]=0;
	}
	
	@Override
	public int compareTo(node a) {
		if(this.used<a.used)return 1;
		return -1;
	}
}