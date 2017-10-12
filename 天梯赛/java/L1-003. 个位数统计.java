import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		String n=in.nextLine();
		in.close();
		int cnt[]=new int[10];
		for(int i=0;i<n.length();++i)
			cnt[n.charAt(i)-'0']++;
		for(int i=0;i<10;++i)
			if(cnt[i]!=0)System.out.println(i+":"+cnt[i]);
	}	
}
