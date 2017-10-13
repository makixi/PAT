import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		long n=in.nextLong();
		long suma=0,sumb=1;
		for(int i=0;i<n;++i) {
			String[] ss=in.next().split("/");
			long a=Long.parseLong(ss[0]),b=Long.parseLong(ss[1]);
			long gcdVal=(suma==0||sumb==0)?1:gcd(Math.abs(suma),Math.abs(sumb));
			sumb/=gcdVal;suma/=gcdVal;
			gcdVal=(a==0||b==0)?1:gcd(Math.abs(a),Math.abs(b));
			a/=gcdVal;b/=gcdVal;
			suma=sumb*a+suma*b;
			sumb=b*sumb;
		}
		long integer=suma/sumb;
		suma-=(sumb*integer);
		long gcdVal=(suma==0||sumb==0)?1:gcd(Math.abs(suma),Math.abs(sumb));
		suma/=gcdVal;sumb/=gcdVal;
		if(integer!=0) {
			System.out.print(integer);
			if(suma!=0)System.out.print(" ");
		}
		if(suma!=0)System.out.print(suma+"/"+sumb);
		if(integer==0&&suma==0)System.out.print(0);
	}	
	
	public static long gcd(long a,long b) {
		if(b==0)return a;
		return gcd(b,a%b);
	}
}
