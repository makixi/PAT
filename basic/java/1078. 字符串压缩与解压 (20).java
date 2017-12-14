import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

class Main{ 
    public static void main(String args[]) throws java.io.IOException{ 
    	Scanner in=new Scanner(System.in);
    	
    	char c=in.next().charAt(0);
    	in.nextLine();
    	String str=in.nextLine();
    	if(c=='C') {
    		char pre=str.charAt(0);
    		int cnt=1;
    		for(int i=1;i<str.length();++i)
    			if(str.charAt(i)==pre)++cnt;
    			else {
    				if(cnt>1) {System.out.print(cnt);System.out.print(pre);}
    				else System.out.print(pre);
    				cnt=1;
    				pre=str.charAt(i);
    			}
    		if(cnt>1) {System.out.print(cnt);System.out.print(pre);}
			else System.out.print(pre);
    	}else {
    		int cnt=0;
    		for(int i=0;i<str.length();++i)
    			if(Character.isDigit(str.charAt(i)))cnt=cnt*10+str.charAt(i)-'0';
    			else {
    				if(cnt==0)System.out.print(str.charAt(i));
    				else while(cnt!=0) {System.out.print(str.charAt(i));--cnt;}
    				cnt=0;
    			}
    	}
    } 
    

}
