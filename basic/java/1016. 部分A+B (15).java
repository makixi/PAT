import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		String a=in.next();
		int da=in.nextInt();
		String b=in.next();
		int db=in.nextInt();
		in.close();
		long aa=0,bb=0;
		for(int i=0;i<a.length();++i)
			if(a.charAt(i)==da+'0')
				aa=aa*10+da;
		for(int i=0;i<b.length();++i)
			if(b.charAt(i)==db+'0')
				bb=bb*10+db;
		System.out.print(aa+bb);
	}
}

