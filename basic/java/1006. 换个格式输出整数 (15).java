import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		in.close();
		int a=n/100;
		int b=n%100/10;
		int c=n%10;
		for(;a!=0;--a)System.out.print("B");
		for(;b!=0;--b)System.out.print("S");
		for(int i=1;i<=c;++i)System.out.print(i);
	}
}
