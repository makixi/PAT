import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt(),k=in.nextInt(),m=in.nextInt();
		node v[]=new node[n];
		for(int i=0;i<n;++i) {
			double minn=101,maxn=-1,sum=0;
			for(int j=0;j<k;++j) {
				int tmp=in.nextInt();
				sum+=tmp;
				minn=Math.min(minn, tmp);
				maxn=Math.max(maxn, tmp);
			}
			v[i]=new node((sum-maxn-minn)/(k-2));
		}
		in.close();
		Arrays.sort(v);
		for(int i=m-1;i>=0;--i) {
			System.out.printf("%.3f", v[i].ave);
			if(i!=0)System.out.print(" ");
		}
	}
	

}

class node implements Comparable<node>{
	double ave;
	
	node(double aa){
		this.ave=aa;
	}
	
	@Override
	public int compareTo(node a) {
		if(this.ave<a.ave)return 1;
		return -1;
	}
}import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt(),k=in.nextInt(),m=in.nextInt();
		node v[]=new node[n];
		for(int i=0;i<n;++i) {
			double minn=101,maxn=-1,sum=0;
			for(int j=0;j<k;++j) {
				int tmp=in.nextInt();
				sum+=tmp;
				minn=Math.min(minn, tmp);
				maxn=Math.max(maxn, tmp);
			}
			v[i]=new node((sum-maxn-minn)/(k-2));
		}
		in.close();
		Arrays.sort(v);
		for(int i=m-1;i>=0;--i) {
			System.out.printf("%.3f", v[i].ave);
			if(i!=0)System.out.print(" ");
		}
	}
	

}

class node implements Comparable<node>{
	double ave;
	
	node(double aa){
		this.ave=aa;
	}
	
	@Override
	public int compareTo(node a) {
		if(this.ave<a.ave)return 1;
		return -1;
	}
}