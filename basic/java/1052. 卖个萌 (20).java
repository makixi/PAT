import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		List<String> hand=solve(in.nextLine());
		List<String> eye=solve(in.nextLine());
		List<String> mouth=solve(in.nextLine());
		int k=in.nextInt();
		for(int i=0;i<k;++i) {
			int a=in.nextInt();
			int b=in.nextInt();
			int c=in.nextInt();
			int d=in.nextInt();
			int e=in.nextInt();
			a--;b--;c--;d--;e--;
			if(a<0||b<0||c<0||d<0||a>=hand.size()||e>=hand.size()||b>=eye.size()||d>=eye.size()||c>=mouth.size()) {
				System.out.println("Are you kidding me? @\\/@");
			}
			else
				System.out.println(hand.get(a)+"("+eye.get(b)+mouth.get(c)+eye.get(d)+")"+hand.get(e));
		}
		in.close();
	}
	public static List<String> solve(String s){
		List<String> list=new ArrayList<>();
		String tmp="";
		boolean st=false;
		for(int i=0;i<s.length();++i) {
			if(s.charAt(i)=='[') st=true;
			else  if(st&&s.charAt(i)==']') {
				st=false;
				list.add(tmp);
				tmp="";
			}else if(st)tmp+=s.charAt(i);
		}
		return list;
	}
}