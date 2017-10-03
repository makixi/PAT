import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main{
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		String badKey=in.nextLine();
		String input=in.nextLine();
		Set<Character> s=new HashSet<>();
		boolean up=true;
		for(int i=0;i<badKey.length();++i) {
			char c=badKey.charAt(i);
			if(c=='+') {
				up=false;//continue;
			}
			s.add(c);
			s.add(Character.toLowerCase(c));
		}
		String res="";
		for(int i=0;i<input.length();++i) {
			char c=input.charAt(i);
			if(Character.isUpperCase(c)) {
				if(up&&!s.contains(c))res+=c;
			}else if(!s.contains(c))res+=c;
			
		}
		System.out.println(res);
	}
	
}