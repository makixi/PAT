import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		String str=in.nextLine();
		int maxlen=str.length(),res=0;
		for(int i=0;i<maxlen;++i) {
			int tmp=1;
			for(int j=1;j+i<maxlen&&j<=i;++j) {
				if(str.charAt(i-j)!=str.charAt(i+j))break;
				tmp+=2;
			}
			res=Math.max(res, tmp);
			tmp=0;
			for(int j=1;j+i<maxlen&&j<=i+1;++j) {
				if(str.charAt(i-j+1)!=str.charAt(i+j))break;
				tmp+=2;
			}
			res=Math.max(res, tmp);
		}
		System.out.print(res);
	}
	
}

