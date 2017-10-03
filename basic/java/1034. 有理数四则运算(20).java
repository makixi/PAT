import java.util.Scanner;

public class Main{
	static boolean isInf;
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		String []input=in.nextLine().split("[\\s/]");
		long a=Integer.parseInt(input[0]);
		long b=Integer.parseInt(input[1]);
		long c=Integer.parseInt(input[2]);
		long d=Integer.parseInt(input[3]);
		add(a,b,c,d);
		sub(a,b,c,d);
		mul(a,b,c,d);
		divi(a,b,c,d);
		
	}
	public static long gcd(long a,long b) {
		if(b==0)return a;
		return gcd(b,a%b);
	}
	public static void print(long a,long b) {
		if(b==0) {
			System.out.print("Inf");
			isInf=true;
			return;
		}
		if(a==0) {
			System.out.print("0");
			return;
		}
		long mo=gcd(a,b);a/=mo;b/=mo;
		long inte=a/b;
		a=a-inte*b;
		if(a>0&&b<0) {
			a=-a;b=-b;
		}
		if(inte<0)a=Math.abs(a);
		if(inte!=0) {
			if(inte<0) {
				System.out.print("("+inte);
				if(a!=0) {
					System.out.print(" "+a);
					if(b!=1) {
						System.out.print("/");
						System.out.print(b);
					}
				}
				System.out.print(")");
			}else {
				System.out.print(inte);
				if(a!=0) {
					System.out.print(" "+a);
					if(b!=1) {
						System.out.print("/");
						System.out.print(b);}
				}
			}
			return;
		}
		if(a<0) {
			System.out.print("("+a);
			if(b!=1) {
				System.out.print("/");
				System.out.print(b);
			}
			System.out.print(")");
		}else {
			System.out.print(a);
			if(b!=1) {
				System.out.print("/");
				System.out.print(b);
			}
		}
	}
	public static void add(long a,long b,long c,long d) {
		boolean isInf=false;
		print(a,b);
		System.out.print(" + ");
		print(c,d);
		System.out.print(" = ");
		if(isInf)System.out.print("Inf");
		else print(b*c+a*d,b*d);
		System.out.println();
	}
	public static void sub(long a,long b,long c,long d) {
		boolean isInf=false;
		print(a,b);
		System.out.print(" - ");
		print(c,d);
		System.out.print(" = ");
		if(isInf)System.out.print("Inf");
		else print(-b*c+a*d,b*d);
		System.out.println();
	}
	public static void mul(long a,long b,long c,long d) {
		boolean isInf=false;
		print(a,b);
		System.out.print(" * ");
		print(c,d);
		System.out.print(" = ");
		if(isInf)System.out.print("Inf");
		else print(a*c,b*d);
		System.out.println();
	}
	public static void divi(long a,long b,long c,long d) {
		boolean isInf=false;
		print(a,b);
		System.out.print(" / ");
		print(c,d);
		System.out.print(" = ");
		if(isInf)System.out.print("Inf");
		else print(a*d,b*c);
		System.out.println();
	}
	
}