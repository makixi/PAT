import java.util.Scanner;

public class Main{
	public static void main(String args[]) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int a[]=new int[101];
		for(int i=0;i<n;++i) {
			int tmp=in.nextInt();
			a[tmp]++;
		}
		int k=in.nextInt();
		for(int i=0;i<k;++i) {
			int tmp=in.nextInt();
			if(i!=0)System.out.print(" ");
			System.out.print(a[tmp]);
		}
		in.close();
	}
}

