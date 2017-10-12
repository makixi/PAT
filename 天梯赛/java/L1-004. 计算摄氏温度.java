import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int f=in.nextInt();
		int c=5*(f-32)/9;
		System.out.print("Celsius = "+c);
	}	
}
