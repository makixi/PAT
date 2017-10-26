import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		node v[]=new node[n+1];
		for(int i=1;i<=n;++i)v[i]=new node(0,0,0);
		for(int i=1;i<=n;++i) {
			v[i].id=i;
			int k=in.nextInt();
			for(int j=0;j<k;++j) {
				int a=in.nextInt(),b=in.nextInt();
				v[a].total+=b;
				v[a].getnum++;
				v[i].total-=b;
			}
		}
		Arrays.sort(v, 1, n+1);
		for(int i=1;i<=n;++i)
			System.out.printf("%d %.2f\n", v[i].id,(v[i].total*1.0)/100);
	}
	
	
}

class node implements Comparable<node>{
	int id,total,getnum;
	
	node(int ii,int tt,int gg){
		this.id=ii;
		this.total=tt;
		this.getnum=gg;
	}
	
	@Override
	public int compareTo(node a) {
		if(this.total!=a.total) {
			if(this.total>a.total)return -1;
			return 1;
		}
		if(a.getnum!=this.getnum) {
			if(this.getnum>a.getnum)return -1;
			return 1;
		}
		if(this.id<a.id)return -1;
		if(this.id>a.id)return 1;
		return 0;
	}
	
}