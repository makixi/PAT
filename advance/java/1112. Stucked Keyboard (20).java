import java.util.ArrayList;
import java.util.Date;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

class Main{ 
    public static void main(String args[]) { 
    	Scanner in=new Scanner(System.in);
    	int k=in.nextInt();
    	String a=in.next();
    	Set<Character> bad=new HashSet<>();
    	Set<Character> good=new HashSet<>();
    	Set<Character> print=new HashSet<>();
    	int cnt=1;
    	char pre=' ';
    	for(int i=0;i<a.length();++i) {
    		if(a.charAt(i)==pre)cnt++;
    		else {
    			if(cnt%k!=0)good.add(pre);
    			cnt=1;
    		}
    		if(cnt%k==0)bad.add(a.charAt(i));
    		pre=a.charAt(i);
    	}
    	for(Character c:good) {
    		if(bad.contains(c))bad.remove(c);
    	}
    	for(int i=0;i<a.length();++i) {
    		if(bad.contains(a.charAt(i))&&!print.contains(a.charAt(i))) {
    			System.out.print(a.charAt(i));
    			print.add(a.charAt(i));
    		}
    	}
    	System.out.println();
    	for(int i=0;i<a.length();++i) {
    		System.out.print(a.charAt(i));
    		if(bad.contains(a.charAt(i)))i+=k-1;
    	}
    } 

}

