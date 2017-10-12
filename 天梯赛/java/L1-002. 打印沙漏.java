import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		char c=in.next().charAt(0);
		int rest=0,i,num;
		for(i=6,num=1;true;num+=i,i+=4)
			if(n>=num&&n<num+i) {
				rest=n-num;break;
			}
		i-=4;
		int level=(i-2)/4;
		for(int j=level;j>=0;--j) {
			for(int k=j;k<level;++k)
				System.out.print(' ');
			for(int k=0;k<2*j+1;++k)
				System.out.print(c);
			System.out.println();
		}
		for(int j=1;j<=level;++j) {
			for(int k=j;k<level;++k)
				System.out.print(' ');
			for(int k=0;k<2*j+1;++k)
				System.out.print(c);
			System.out.println();
		}
		System.out.print(rest);
	}	
}
