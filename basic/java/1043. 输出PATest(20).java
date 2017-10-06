import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
	public static void main(String args[])throws IOException{
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		String s=in.readLine();
		int v[]=new int[6];
		for(int i=0;i<s.length();++i)
			if(s.charAt(i)=='P')v[0]++;
			else if(s.charAt(i)=='A')v[1]++;
			else if(s.charAt(i)=='T')v[2]++;
			else if(s.charAt(i)=='e')v[3]++;
			else if(s.charAt(i)=='s')v[4]++;
			else if(s.charAt(i)=='t')v[5]++;
		int flag=0;
		for(int i=0;i<6;i=(i+1)%6) {
			if(flag>=6)break;
			if(v[i]!=0) {
				if(i==0)System.out.print('P');
				else if(i==1)System.out.print('A');
				else if(i==2)System.out.print('T');
				else if(i==3)System.out.print('e');
				else if(i==4)System.out.print('s');
				else System.out.print('t');
				v[i]--;
				flag=0;
			}else flag++;
		}
	}
}
