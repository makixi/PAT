import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		String a,b,res="";
		a=in.next();b=in.next();
		in.close();
		while(a.length()<b.length())a="0"+a;
		while(b.length()<a.length())b="0"+b;
		int i=a.length()-1,j=b.length()-1;
		int pos=1;
		while(i!=-1&&j!=-1) {
			if(pos%2==1) res="0123456789JQK".charAt((a.charAt(i)-'0'+b.charAt(j)-'0')%13)+res;
			else res="1234567890123456789".charAt((b.charAt(j)-'0'-(a.charAt(i)-'0'))+9) +res;
			++pos;--i;--j;
		}
		System.out.print(res);
	}
}