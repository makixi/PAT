import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt(),j=0;
		in.nextLine();
		String pre=in.nextLine();
		pre=reverse(pre);
		for(int i=0;i<n-1;++i) {
			String curr=in.nextLine();
			curr=reverse(curr);
			for(j=0;j<Math.min(curr.length(),pre.length());++j)
				if(pre.charAt(j)!=curr.charAt(j))break;
			pre=pre.substring(0,j);
		}
		if(pre.length()>0) {
			pre=reverse(pre);
			System.out.print(pre);
		}else System.out.print("nai");
	}
	
	public static String reverse(String str) {
		String res="";
		for(int i=str.length()-1;i>=0;--i)
			res+=str.charAt(i);
		return res;
	}
}