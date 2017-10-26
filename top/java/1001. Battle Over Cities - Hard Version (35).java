import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static final int maxn=100010;
	public static final int inf=0x3f3f3f3f;
	public static int fa[]=new int[maxn];
	public static int cost[]=new int[maxn];
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt(),m=in.nextInt();
		node v[]=new node[m];
		for(int i=0;i<m;++i) {
			v[i]=new node(in.nextInt(),in.nextInt(),in.nextInt(),in.nextInt());
		}
		Arrays.sort(v);
		int res=0;
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=n;++j)fa[j]=j;
			int cnt=n-2;
			cost[i]=0;
			for(int j=0;j<m;++j) {
				if(v[j].a==i||v[j].b==i)continue;
				int fx=find(v[j].a),fy=find(v[j].b);
				if(fx==fy)continue;
				--cnt;
				fa[fx]=fy;
				if(v[j].s==0)cost[i]+=v[j].c;
			}
			if(cnt>0)cost[i]=inf;
			res=Math.max(res, cost[i]);
		}
		if(res!=0) {
			boolean first=true;
			for(int i=1;i<=n;++i)
				if(cost[i]==res) {
					if(!first)System.out.print(" ");
					first=false;
					System.out.print(i);
				}
		}else System.out.print(res);
	}

	public static int find(int x) {
		int a=x;
		while(x!=fa[x])x=fa[x];
		while(a!=fa[a]) {
			int tmp=a;
			a=fa[a];
			fa[tmp]=x;
		}
		return x;
	}
}

class node implements Comparable<node>{
	int a,b;
	int c,s;

	node(int aa,int bb,int cc,int ss){
		this.a=aa;
		this.b=bb;
		this.c=cc;
		this.s=ss;
	}

	@Override
	public int compareTo(node n1) {
		if(n1.s==s) {
			if(c<n1.c)return -1;
			else return 1;
		}
		if(n1.s<s)return -1;
		return 1;
	}
}