import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.io.IOException;

public class Main{
	public static final String str[]=new String [] {"zero","one","two","three","four",
			"five","six","seven","eight","nine","ten"};
	public static void main(String[] args) throws java.io.IOException{
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		String n=in.readLine();
		List<String> ans=new LinkedList<>();
		in.close();
		int res=0;
		for(int i=0;i<n.length();++i)
			res+=(n.charAt(i)-'0');
		if(res==0) {
			System.out.print("zero");
			return;
		}
		while(res>0) {
			ans.add(str[res%10]);
			res/=10;
		}
		for(int i=ans.size()-1;i>=0;--i) {
			System.out.print(ans.get(i));
			if(i!=0)System.out.print(" ");
		}
	}
}

