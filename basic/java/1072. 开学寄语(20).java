import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt(),m=in.nextInt();
		boolean mark[]=new boolean [10000];
		for(int i=0;i<m;++i) {
			int tmp=in.nextInt();mark[tmp]=true;
		}
		int cntStu=0,cntTh=0;
		for(int i=0;i<n;++i) {
			String name=in.next();
			int k=in.nextInt();
			boolean first=true;
			for(int j=0;j<k;++j) {
				int tmp=in.nextInt();
				if(mark[tmp]) {
					if(first) {
						cntStu++;
						first=false;
						System.out.print(name+":");
					}
					cntTh++;
					System.out.printf(" %04d",tmp);
				}
			}
			if(!first)System.out.println();
		}
		in.close();
		System.out.print(cntStu+" "+cntTh);
	}
	
}
