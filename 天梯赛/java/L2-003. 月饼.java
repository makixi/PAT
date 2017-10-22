import java.util.Arrays;
import java.util.Scanner;
import java.util.Vector;

public class Main {
	public static final int maxn=510;
	public static final int inf=0x3f3f3f3f;
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt(),d=in.nextInt();
		node v[]=new node [n];
		for(int i=0;i<n;++i) {
			v[i]=new node();
			v[i].save=in.nextDouble();
		}
		for(int i=0;i<n;++i) {
			v[i].sale=in.nextDouble();
			v[i].unite=v[i].sale/v[i].save;
		}
		in.close();
		Arrays.sort(v);
		int i=0;
		double maxsum=0;
		while(d>0&&i<v.length) {
			if(v[i].save<=d) {
				d-=v[i].save;
				maxsum+=v[i].sale;
				++i;
			}else {
				maxsum+=v[i].unite*d;
				d=0;
			}
		}
		System.out.printf("%.2f",maxsum);
	}
}

class node implements Comparable<node>{
	double save;
	double sale;
	double unite;
	
	@Override
	public int compareTo(node a) {
		if(unite>a.unite)return -1;
		return 1;
	}
}