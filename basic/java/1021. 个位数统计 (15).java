import java.util.Arrays;
import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		String n=in.next();
		in.close();
		int cnt[]=new int [10];
		Arrays.fill(cnt, 0);
		for(int i=0;i<n.length();++i) {
			++cnt[n.charAt(i)-'0'];
		}
		for(int i=0;i<9;++i)
			if(cnt[i]!=0)System.out.println(i+":"+cnt[i]);
	}
	
}
