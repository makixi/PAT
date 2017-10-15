import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		boolean mark[]=new boolean [100000];
		for(int i=0;i<n;++i) {
			int k=in.nextInt();
			for(int j=0;j<k;++j) {
				int tmp=in.nextInt();
				if(k!=1)mark[tmp]=true;
			}
		}
		int m=in.nextInt();
		boolean first=true;
		for(int i=0;i<m;++i) {
			int tmp=in.nextInt();
			if(!mark[tmp]) {
				if(!first)System.out.print(" ");
				first=false;
				System.out.printf("%05d",tmp);
				mark[tmp]=true;
			}
		}
		in.close();
		if(first)System.out.print("No one is handsome");
	}	
	
}
