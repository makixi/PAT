import java.util.Random;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int c=(in.nextInt()+in.nextInt());
		if(c<0) {
			System.out.print('-');
			c=-c;
		}
		String a=Integer.valueOf(c).toString();
		String res="";
		for(int i=a.length()-1,j=0;i>=0;--i,++j) {
			res+=a.charAt(i);
			if(j%3==2)res+=',';
		}
		if(res.charAt(res.length()-1)==',')res=res.substring(0, res.length()-1);
		for(int i=res.length()-1;i>=0;--i) {
			System.out.print(res.charAt(i));
		}
	}

}

