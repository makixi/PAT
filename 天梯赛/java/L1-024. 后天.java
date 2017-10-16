import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int d=in.nextInt();
		in.close();
		d=(d+1)%7+1;
		System.out.print(d);
	}	
	
}
