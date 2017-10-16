import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static final char output[]= {'G','P','L','T'};
	public static void main(String[] args) throws IOException{
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		String n=in.readLine().toUpperCase();
		in.close();
		int a[]=new int [4];
		for(int i=0;i<n.length();++i)
			if(n.charAt(i)=='G')++a[0];
			else if(n.charAt(i)=='P')++a[1];
			else if(n.charAt(i)=='L')++a[2];
			else if(n.charAt(i)=='T')++a[3];
		int curr=0;
		while(a[0]!=0||a[1]!=0||a[2]!=0||a[3]!=0) {
			if(a[curr]!=0) {
				System.out.print(output[curr]);
				a[curr]--;
			}
			curr=(curr+1)%4;
		}
	}	
	
}
