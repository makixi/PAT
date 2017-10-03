import java.util.Arrays;
import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		String[] s=in.nextLine().split("[.E]");
		in.close();
		int pow=Integer.parseInt(s[2]);
		int z=Integer.parseInt(s[0]);
		if(pow>=0) {
			System.out.print(z);
			boolean point=true;
			if(s[1].length()<=pow)point=false;
			int i;
			for(i=0;i<s[1].length()&&pow>0;++i,--pow)
				System.out.print(s[1].charAt(i));
			if(point) {
				System.out.print(".");
				for(;i<s[1].length();++i)
					System.out.print(s[1].charAt(i));
			}
			while(pow>0) {
				System.out.print("0");
				pow--;
			}
		}else {
			if(z<0) {
				System.out.print("-");
				z=-z;
			}
			System.out.print("0.");
			for (int i = 1; i < Math.abs(pow); i++) {
				System.out.print("0");
			}
			System.out.print(z);
			System.out.print(s[1]);
		}
	}
	
}
