import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int m=in.nextInt();
		int []a=new int[n+m];
		while(m>n)m-=n;
		for(int i=m;i<m+n;++i)a[i]=in.nextInt();
		for(int i=0;i<m;++i)a[i]=a[n+i];
		for(int i=0;i<n;++i) {
			if(i!=0)System.out.print(" ");
			System.out.print(a[i]);
		}
	}
}
