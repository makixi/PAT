import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		char c=in.next().charAt(0);
		in.close();
		int row=(int)Math.round(n*1.0/2);
		for(int i=0;i<row;++i) {
			for(int j=0;j<n;++j)System.out.print(c);
			System.out.println();
		}
	}	
}
