import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

class Main{ 
    public static void main(String args[]) { 
    	Scanner in=new Scanner(System.in);
    	int m=in.nextInt();
    	int n=in.nextInt();
    	int half=m*n/2;
    	Map<Integer,Integer> ma=new HashMap<>();
    	for(int i=0;i<n;++i) {
    		for(int j=0;j<m;++j) {
    			int num=in.nextInt();
    			int tmp=0;
    			if(ma.get(num)!=null)tmp=ma.get(num);
    			ma.put(num, ++tmp);
    			if(tmp>half) {
    				System.out.print(num);
    				break;
    			}
    		}
    	}
    } 

}


