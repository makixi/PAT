import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int m=in.nextInt(),n=in.nextInt();
		int a=in.nextInt(),b=in.nextInt();
		int alter=in.nextInt();
		for(int i=0;i<m;++i) {
			for(int j=0;j<n;++j) {
				if(j!=0)System.out.print(" ");
				int tmp=in.nextInt();
				if(tmp>=a&&tmp<=b)System.out.printf("%03d",alter);
				else System.out.printf("%03d",tmp);
			}
			System.out.println();
		}
		in.close();
	}
	
}
