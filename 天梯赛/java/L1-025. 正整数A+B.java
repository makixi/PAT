import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String str[]=in.nextLine().trim().split("\\s");
		in.close();
		int a=0,b=0;
		boolean flag1=true,flag2=true;
		if(str.length>2)flag2=false;
		try {
			a=Integer.valueOf(str[0]);
			if(a<=0||a>1000)flag1=false;
		}catch(Exception e) {flag1=false;}
		try {
			b=Integer.valueOf(str[1]);
			if(b<=0||b>1000)flag2=false;
		}catch(Exception e) {flag2=false;}
		if(flag1)System.out.print(a+" + ");
		else System.out.print("? + ");
		if(flag2)System.out.print(b+" = ");
		else System.out.print("? = ");
		if(flag1&&flag2)System.out.print(a+b);
		else System.out.print("?");
	}
}