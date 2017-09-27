import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int[]a=new int[n];
		boolean[]mark=new boolean[10001];
		for(int i=0;i<n;++i) {
			a[i]=in.nextInt();
			int num=a[i];
			while(num!=1) {
				if(num%2!=0)num=num*3+1;
				num/=2;
				if(mark[num]==true)break;
				mark[num]=true;
			}
		}
		in.close();
		LinkedList<Integer>list=new LinkedList<Integer>();
		for(int i=0;i<n;++i) 
			if(mark[a[i]]==false)list.add(a[i]);
		int[]res=new int[list.size()];
		for(int i=0;i<res.length;++i)res[i]=list.get(i);
		Arrays.sort(res);
		for (int i = res.length - 1; i > 0; i--) 
			System.out.print(res[i] + " ");
		System.out.print(res[0]);
	}
}
