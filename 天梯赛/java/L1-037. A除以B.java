import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a=in.nextInt(),b=in.nextInt();
		System.out.print(a+"/");
		if(b<0)System.out.print("("+b+")=");
		else System.out.print(b+"=");
		if(b==0)System.out.print("Error");
		else System.out.printf("%.2f",1.0*a/b);
	}
}