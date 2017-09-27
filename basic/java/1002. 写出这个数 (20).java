import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static void main(String args[]) {
		String n;
		int sum=0;
		Scanner in=new Scanner(System.in);
		n=in.nextLine();
		in.close();
		for(int i=0;i<n.length();++i)sum+=n.charAt(i)-'0';
		Stack<String> s=new Stack<>();
		do {
			int tmp=sum%10;
			switch(tmp) {
			case 0:s.push("ling");break;
			case 1:s.push("yi");break;
			case 2:s.push("er");break;
			case 3:s.push("san");break;
			case 4:s.push("si");break;
			case 5:s.push("wu");break;
			case 6:s.push("liu");break;
			case 7:s.push("qi");break;
			case 8:s.push("ba");break;
			case 9:s.push("jiu");break;
			}
			sum/=10;
		}while(sum!=0);
		System.out.print(s.pop());
		while(!s.empty())System.out.print(" " +s.pop());
	}
}
