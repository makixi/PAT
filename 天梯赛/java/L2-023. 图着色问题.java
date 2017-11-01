import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
	public static final int maxn=501;
	public static boolean e[][]=new boolean [maxn][maxn];
	public static int color[]=new int [maxn];
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt(),m=in.nextInt(),k=in.nextInt();
		for(int i=0;i<m;++i) {
			int a=in.nextInt(),b=in.nextInt();
			e[a][b]=e[b][a]=true;
		}
		int q=in.nextInt();
		for(int cas=0;cas<q;++cas) {
			boolean flag=true;
			Set<Integer> s=new HashSet<>();
			for(int i=1;i<=n;++i) {
				color[i]=in.nextInt();
				s.add(color[i]);
			}
			if(k!=s.size())flag=false;
			for(int i=1;i<=n;++i) {
				if(!flag)break;
				for(int j=i+1;j<=n;++j)
					if(e[i][j]&&color[j]==color[i]) {
						flag=false;
						break;
					}
			}
			if(flag)System.out.println("Yes");
			else System.out.println("No");
		}
	}


}

