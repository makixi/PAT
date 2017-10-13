import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		in.close();
		int max=(int)Math.sqrt(n);
		boolean success=false;
		for(int len=12;len>=1;--len) {
			for(int be=2;be<=max;++be) {
				long sum=1;
				for(int j=be;j<be+len;++j)
					sum*=j;
				if(n%sum==0) {
					System.out.println(len);
					for(int j=be;j<be+len;++j) {
						if(j!=be)System.out.print("*");
						System.out.print(j);
					}
					success=true;
					break;
				}
			}
			if(success)break;
		}
		if(!success)System.out.printf("1\n%d", n);
	}	
}
