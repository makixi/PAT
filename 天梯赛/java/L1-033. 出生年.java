import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int y=in.nextInt();
		int n=in.nextInt();
		in.close();
		int cnt=0;
		for(;;++cnt) {
			int a=(y+cnt)/1000,b=(y+cnt)/100%10,c=(y+cnt)/10%10,d=(y+cnt)%10;
			int mark[]=new int[10];
			int tmp=0;
			mark[a]=1;mark[b]=1;mark[c]=1;mark[d]=1;
			for(int i=0;i<10;++i)if(mark[i]==1)++tmp;
			if(tmp==n)break;
		}
		System.out.printf("%d %04d",cnt,(y+cnt));
	}
}