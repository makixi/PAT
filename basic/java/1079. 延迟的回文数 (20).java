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
    	BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
    	String str=in.readLine();
    	if(str.equals(reverse(str))) {
    		System.out.print(str+" is a palindromic number.");
    	}
    	else {
    		boolean success=false;
    		for(int i=0;i<10;++i) {
    			System.out.print(str+" + "+reverse(str)+" = ");
    			str=(new BigInteger(str).add(new BigInteger(reverse(str)))).toString();
    			System.out.println(str);
    			if(str.equals(reverse(str))) {
    				System.out.print(str+" is a palindromic number.");
    				success=true;
    				break;
    			}
    		}
    		if(!success) {
    			System.out.print("Not found in 10 iterations.");
    		}
    	}
    } 
    
    public static String reverse(String str) {
    	String res="";
    	for(int i=str.length()-1;i>=0;--i)res+=str.charAt(i);
    	return res;
    }

}
