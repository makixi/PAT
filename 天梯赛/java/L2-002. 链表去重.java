import java.util.Arrays;
import java.util.Scanner;
import java.util.Vector;

public class Main {
	public static final int maxn=1000001;
	public static boolean vis[]=new boolean[maxn];
	public static int nex[]=new int [maxn];
	public static int val[]=new int [maxn];
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int fad=in.nextInt(),n=in.nextInt();
		Vector<Integer> v1=new Vector<>();
		Vector<Integer> v2=new Vector<>();
		for(int i=0;i<n;++i) {
			int tmp=in.nextInt();
			val[tmp]=in.nextInt();nex[tmp]=in.nextInt();
		}
		while(fad!=-1) {
			if(!vis[Math.abs(val[fad])]) {
				vis[Math.abs(val[fad])]=true;
				v1.add(fad);
			}else v2.add(fad);
			fad=nex[fad];
		}
		for(int i=0;i<v1.size();++i) {
			if(i!=v1.size()-1)System.out.printf("%05d %d %05d\n", v1.get(i),val[v1.get(i)],v1.get(i+1));
			else System.out.printf("%05d %d -1\n", v1.get(i),val[v1.get(i)]);
		}
		for(int i=0;i<v2.size();++i) {
			if(i!=v2.size()-1)System.out.printf("%05d %d %05d\n", v2.get(i),val[v2.get(i)],v2.get(i+1));
			else System.out.printf("%05d %d -1\n", v2.get(i),val[v2.get(i)]);
		}
	}
}
