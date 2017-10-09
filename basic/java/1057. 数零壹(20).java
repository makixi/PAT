import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws java.io.IOException{
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		String str=in.readLine();in.close();
		int sum=0,cnt0=0,cnt1=0;
		for(int i=0;i<str.length();++i)
			if(Character.isAlphabetic(str.charAt(i)))
				if(Character.isUpperCase(str.charAt(i)))sum+=str.charAt(i)-'A'+1;
				else sum+=str.charAt(i)-'a'+1;
		while(sum>0) {
			if(sum%2==1)cnt1++;
			else cnt0++;
			sum>>=1;
		}
		System.out.print(cnt0+" "+cnt1);
	}

}

