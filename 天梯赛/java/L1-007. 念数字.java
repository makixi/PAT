import java.util.Scanner;

public class Main {
	public static final String[] chinese= {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		String n=in.nextLine();
		in.close();
		boolean first=true;
		if(n.charAt(0)=='-') {
			System.out.print("fu ");
			first=false;
		}
		for(int i=(first)?0:1;i<n.length();++i) {
			System.out.print(chinese[n.charAt(i)-'0']);
			if(i!=n.length()-1)System.out.print(" ");
		}
	}	
}
