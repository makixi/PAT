import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static final int maxn=101;
	public static int relation[][]=new int[maxn][maxn];
	public static int fri[]=new int [maxn];
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt(),m=in.nextInt(),k=in.nextInt();
		for(int i=1;i<=n;++i)fri[i]=i;
		for(int i=0;i<m;++i) {
			int a=in.nextInt(),b=in.nextInt();
			relation[a][b]=in.nextInt();
			relation[b][a]=relation[a][b];
			if(relation[a][b]==1)unite(a,b);
		}
		for(int i=0;i<=n;++i)find(i);
		for(int i=0;i<k;++i) {
			int a=in.nextInt(),b=in.nextInt();
			if(relation[a][b]==1)System.out.println("No problem");
			else if(relation[a][b]==0)System.out.println("OK");
			else if(relation[a][b]==-1&&fri[a]==fri[b])System.out.println("OK but...");
			else System.out.println("No way");
		}
		in.close();
	}
	
	public static int find(int x) {
		int a=x;
		while(x!=fri[x])x=fri[x];
		while(a!=fri[a]) {
			int tmp=a;
			a=fri[a];
			fri[tmp]=x;
		}
		return x;
	}
	
	public static void unite(int a,int b) {
		int x=find(a),y=find(b);
		if(x!=y)fri[x]=y;
	}
}
