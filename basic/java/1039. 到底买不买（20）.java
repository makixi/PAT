import java.util.Arrays;
import java.util.Scanner;

public class Main{
	public static void main(String args[]) {
		Scanner in=new Scanner(System.in);
		char []curr=in.next().toCharArray();
		char []want=in.next().toCharArray();
		in.close();
		Arrays.sort(curr);
		Arrays.sort(want);
		int cnt=0;
		for(int i=0,j=0;j<want.length;) {
			if(i!=curr.length) {
				if(curr[i]==want[j]) {
					++i;++j;
				}else if(curr[i]>want[j]) {
					++j;
					++cnt;
				}else {
					++i;
					if(i==curr.length)cnt+=curr.length-i;
				}
			}else {
				cnt+=curr.length-j;break;
			}
		}
		if (cnt == 0)	System.out.println("Yes " + (curr.length - want.length));
		else System.out.println("No " + cnt);
	}
}

