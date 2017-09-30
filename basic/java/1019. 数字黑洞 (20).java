import java.util.Arrays;
import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int num=in.nextInt();
		in.close();
		do {
			int aa=desc(num);
			int bb=incr(num);
			num=aa-bb;
			System.out.printf("%04d - %04d = %04d\n", aa,bb,num);
		}while(num!=0&&num!=6174);
	}
	public static int desc(int num) {
		char []a=String.format("%04d", num).toCharArray();
		Arrays.sort(a);
		int res=0;
		for(int i=0;i<4;++i)
			res=res*10+(a[i]-'0');
		return res;
	}
	public static int incr(int num) {
		char []a=String.format("%04d", num).toCharArray();
		Arrays.sort(a);
		int res=0;
		for(int i=3;i<=0;--i)
			res=res*10+(a[i]-'0');
		return res;
	}
}

