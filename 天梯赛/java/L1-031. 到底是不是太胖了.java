import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n=in.nextInt();
		while(n!=0) {
			n--;
			int h=in.nextInt(),w=in.nextInt();
			double wei=(h-100)*0.9*2;
			if(Math.abs(w*1.0-wei)<wei*0.1)System.out.println("You are wan mei!");
			else if((w*1.0-wei)>=wei*0.1)System.out.println("You are tai pang le!");
			else System.out.println("You are tai shou le!");
		}
		in.close();
	}
}