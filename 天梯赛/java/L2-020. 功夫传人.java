import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static double r;
	public static double res=0;
	public static List<node> v=new LinkedList<>();
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		double z=in.nextDouble();
		r=in.nextDouble();
		r=(100-r)/100;
		for(int i=0;i<n;++i) {
			int k=in.nextInt();
			v.add(new node());
			if(k==0)v.get(i).times=in.nextDouble();
			else {
				for(int j=0;j<k;++j) {
					v.get(i).child.add(in.nextInt());
				}
			}
		}
		dfs(0,z);
		System.out.print((int)res);
	}
	
	public static void dfs(int curr,double kung) {
		if(v.get(curr).times>0) {
			res+=kung*v.get(curr).times;
			return;
		}
		for(int i=0;i<v.get(curr).child.size();++i)
			dfs(v.get(curr).child.get(i),kung*r);
	}
}

class node{
	List<Integer> child;
	double times;
	node(){
		child=new LinkedList<>();
		times=0;
	}
}
