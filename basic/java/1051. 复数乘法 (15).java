import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		double r1=in.nextDouble();
		double p1=in.nextDouble();
		double r2=in.nextDouble();
		double p2=in.nextDouble();
		in.close();
		double r=r1*r2*Math.cos(p1+p2),p=r1*r2*Math.sin(p1+p2);
		if(r>-0.005&&r<0)System.out.print("0.00");
		else System.out.printf("%.2f",r);
		if(p>-0.005&&p<0)System.out.print("+0.00i");
		else if(p>-0.005)System.out.printf("+%.2fi", p);
		else System.out.printf("%.2fi", p);
	}
}