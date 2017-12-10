import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

class Main{ 
    public static void main(String args[]) { 
    	Scanner in=new Scanner(System.in);
    	int n=in.nextInt();
    	Map<Integer,Integer> m=new HashMap<>();
    	for(int i=1;i<=n;++i) {
    		m.put(in.nextInt(), i);
    	}
    	int k=in.nextInt();
    	for(int i=1;i<=k;++i) {
    		int tmp=in.nextInt();
    		if(m.get(tmp)==null)System.out.printf("%04d: Are you kidding?\n",tmp);
    		else if(m.get(tmp)==1) {
    			System.out.printf("%04d: Mystery Award\n",tmp);
    			m.put(tmp, -1);
    		}else if(isprime(m.get(tmp))) {
    			System.out.printf("%04d: Minion\n",tmp);
    			m.put(tmp, -1);
    		}else if(m.get(tmp)==-1)System.out.printf("%04d: Checked\n",tmp);
    		else {
    			System.out.printf("%04d: Chocolate\n",tmp);
    			m.put(tmp, -1);
    		}
    	}
    } 
    
    public static boolean isprime(int num) {
    	if(num<=1)return false;
    	for(int i=2;i*i<=num;++i)
    		if(num%i==0)return false;
    	return true;
    }

}
