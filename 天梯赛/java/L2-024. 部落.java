import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static final int maxn=10001;
	public static int fa[]=new int [maxn];
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		Set<Integer> s=new HashSet<>();
		for(int i=1;i<maxn;++i)fa[i]=i;
		for(int i=0;i<n;++i) {
			int k=in.nextInt(),a=in.nextInt();
			s.add(a);
			for(int j=0;j<k-1;++j) {
				int b=in.nextInt();
				s.add(b);
				unite(a,b);
			}
		}
		int cnt=0;
		for(int i=1;i<=s.size();++i)find(i);
		for(int i=1;i<=s.size();++i)if(fa[i]==i)cnt++;
		System.out.println(s.size()+" "+cnt);
		int q=in.nextInt();
		for(int i=0;i<q;++i) {
			int a=in.nextInt(),b=in.nextInt();
			if(fa[a]!=fa[b])System.out.println("N");
			else System.out.println("Y");
		}
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
	
	public static void unite(int a,int b) {
		int x=find(a),y=find(b);
		if(x!=y)fa[x]=y;
	}
}

