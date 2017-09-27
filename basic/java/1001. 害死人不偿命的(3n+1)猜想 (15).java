import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		int n,res=0;
		Scanner in=new Scanner(System.in);
		n=in.nextInt();
		in.close();
		while(n!=1) {
			if(n%2!=0)n=3*n+1;
			n/=2;
			res++;
		}
		System.out.println(res);
	}
}
