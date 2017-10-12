import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Vector;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int ad=in.nextInt(),n=in.nextInt(),k=in.nextInt();
		Vector<Integer> v1=new Vector<>();
		Vector<Integer> v2=new Vector<>();
		Vector<Integer> v3=new Vector<>();
		int val[]=new int [100000+10];
		int nex[]=new int[100000+10];
		for(int i=0;i<n;++i) {
			int tmp=in.nextInt();
			val[tmp]=in.nextInt();
			nex[tmp]=in.nextInt();
		}
		for(;ad!=-1;ad=nex[ad]) {
			if(val[ad]<0)v1.add(ad);
			else if(val[ad]>k)v3.add(ad);
			else v2.add(ad);
		}
		for(int i=0;i<v2.size();++i)
			v1.insertElementAt(v2.get(i), v1.size());
		for(int i=0;i<v3.size();++i)
			v1.insertElementAt(v3.get(i), v1.size());
		for(int i=0;i<v1.size();++i) {
			System.out.printf("%05d %d ",v1.get(i),val[v1.get(i)]);
			if(i==v1.size()-1)System.out.printf("-1");
			else System.out.printf("%05d\n",v1.get(i+1));
		}
	}	
}
