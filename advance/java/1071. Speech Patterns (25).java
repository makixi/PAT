import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

class Main{ 
    public static void main(String args[]) { 
    	Scanner in=new Scanner(System.in);
    	String str=in.nextLine().toLowerCase();
    	String tmp="";
    	Map<String,Integer>m=new HashMap<>();
    	for(int i=0;i<str.length();++i)
    		if(Character.isDigit(str.charAt(i))||Character.isAlphabetic(str.charAt(i)))
    			tmp+=str.charAt(i);
    		else {
    			if(tmp.length()>0) {
    				int num=0;
    				if(m.get(tmp)!=null)num=m.get(tmp);
    				m.put(tmp, num+1);
    			}
    			tmp="";
    		}
    	in.close();
    	if(tmp.length()>0) {
    		int num=0;
			if(m.get(tmp)!=null)num=m.get(tmp);
			m.put(tmp, num+1);
    	}
    	int maxn=0;
    	for(Map.Entry<String, Integer> entry:m.entrySet())
    		if(entry.getValue()>maxn) {
    			maxn=entry.getValue();
    			tmp=entry.getKey();
    		}
    	System.out.print(tmp+" "+maxn);
    } 

}


