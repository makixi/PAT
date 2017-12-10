import java.util.Scanner;

public class Main{
	public static final int maxn=100001;
	public static int cnt[]=new int[maxn];
	public static int ran[]=new int[maxn];
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt(),tmp,mark=0;
		for(int i=0;i<n;++i) {
			tmp=in.nextInt();
			cnt[tmp]++;
			ran[i]=tmp;
		}
		for(int i=0;i<n;++i)
			if(cnt[ran[i]]==1) {
				mark=ran[i];
				break;
			}
		if(mark==0)System.out.println("None");
		else System.out.println(mark);
	}
}