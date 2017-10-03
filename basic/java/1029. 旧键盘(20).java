import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main{
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		String ori=in.nextLine().toUpperCase();
		String real=in.nextLine().toUpperCase();
		in.close();
		Set<Character> set=new HashSet<>();
		int i=0,j=0;
		while(i<ori.length()) {
			char c=ori.charAt(i++);
			if(j<real.length()) {
				if(c!=real.charAt(j)) {
					if(!set.contains(c)) {
						System.out.print(c);
						set.add(c);
					}
				}else ++j;
			}else if(!set.contains(c)) {
				System.out.print(c);
				set.add(c);
			}
		}
	}
}
