import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException{
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		String n=in.readLine();
		in.close();
		boolean odd=true,negative=false;
		int i=0,cnt2=0;
		if(n.charAt(i)=='-') {
			negative=true;++i;
		}
		for(;i<n.length();++i) {
			if(n.charAt(i)=='2') ++cnt2;
			if((i==n.length()-1)&&((n.charAt(i)-'0')%2==0))odd=false;
		}
		double res=0;
		if(negative) {
			if(!odd) res=(1.0*cnt2)/(n.length()-1)*1.5*2*100;
			else res=(1.0*cnt2)/(n.length()-1)*1.5*100;
		}else {
			if(!odd)res=(1.0*cnt2)/(n.length())*2*100;
			else res=(1.0*cnt2)/(n.length())*100;
		}
		System.out.printf("%.2f%%", res);
	}	
	
}
