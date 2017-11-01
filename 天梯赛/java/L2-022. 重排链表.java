import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static final int maxn=100000+1;
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int fad=in.nextInt(),n=in.nextInt();
		int cnt=0,num=2;
		node v[]=new node[maxn];
		for(int i=0;i<maxn;++i) {
			v[i]=new node();v[i].num=maxn;
		}
		for(int i=0;i<n;++i) {
			int ad=in.nextInt();
			v[ad].val=in.nextInt();
			v[ad].nad=in.nextInt();
			v[ad].ad=ad;
		}
		for(int i=fad;i!=-1;i=v[i].nad)++cnt;
		for(int i=1;fad!=-1;fad=v[fad].nad,++i) {
			v[fad].num=num;
			if(i<cnt/2)num+=2;
			else if(i==cnt/2&&(cnt&1)==1)num+=1;
			else if(i==cnt/2)num-=1;
			else num-=2;
		}
		Arrays.sort(v);
		for(int i=0;i<cnt;++i) {
			System.out.printf("%05d %d ", v[i].ad,v[i].val);
			if(i==cnt-1)System.out.println(-1);
			else System.out.printf("%05d\n", v[i+1].ad);
		}
	}


}

class node implements Comparable<node>{
	int nad;
	int val;
	int ad;
	int num;
	
	@Override
	public int compareTo(node a) {
		if(this.num<a.num)return -1;
		if(this.num==a.num)return 0;
		return 1;
	}
}
