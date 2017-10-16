import java.util.Scanner;

public class Main {
	
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int cntodd=0;
		for(int i=0;i<n;++i)
			if((in.nextInt())%2==1)cntodd++;
		in.close();
		System.out.printf("%d %d", cntodd,n-cntodd);
	}	
	
}
