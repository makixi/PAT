import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static final int maxn=51;
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt(),maxd=0;
		node v[]=new  node[n];
		for(int i=0;i<n;++i) {
			v[i]=new node(in.nextInt(),in.nextInt(),in.nextInt());
			maxd=Math.max(maxd, v[i].d);
		}
		in.close();
		Arrays.sort(v);
		int dp[]=new int [maxd+1];
		int res=0;
		for(int i=0;i<n;++i)
			for(int j=maxd;j>=v[i].l;--j)
				if(j<=v[i].d) {
					dp[j]=Math.max(dp[j], dp[j-v[i].l]+v[i].p);
					res=Math.max(res, dp[j]);
				}
		System.out.print(res);
	}
	
	
}

class node implements Comparable<node>{
	int p,l,d;
	
	node(int pp,int ll,int dd){
		this.p=pp;
		this.l=ll;
		this.d=dd;
	}
	
	@Override
	public int compareTo(node a) {
		if(this.d<a.d)return -1;
		if(this.d>a.d)return 1;
		return 0;
	}
}