import java.util.Scanner;

public class Main{
	public static void main(String args[]) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		char c=in.next().charAt(0);
		in.close();
		int row=(int)((1.0*n)/2+0.5);
		for(int i=1;i<=row;++i) {
			for(int j=1;j<=n;++j) {
				if(i==1||i==row)System.out.print(c);
				else {
					if(j==1||j==n)System.out.print(c);
					else System.out.print(" ");
				}
			}
			System.out.println();
		}
	}
}