import java.util.Scanner;

class Main{ 
    public static void main(String args[]) { 
    	Scanner in=new Scanner(System.in);
    	int k=in.nextInt();
    	int init[]=new int[55];
    	int res[]=new int[55];
    	int order[]=new int[55];
    	for(int i=1;i<=54;++i) {
    		order[i]=in.nextInt();
    		init[i]=i;
    	}
    	for(int j=0;j<k;++j) {
    		for(int i=1;i<=54;++i)res[order[i]]=init[i];
    		for(int i=1;i<=54;++i)init[i]=res[i];
    	}
    	String c="SHCDJ";
    	for(int i=1;i<=54;++i) {
    		res[i]-=1;
    		System.out.print((char)c.charAt(res[i]/13));
    		System.out.print((res[i]%13+1));
    		if(i!=54)System.out.print(" ");
    	}
    } 

}
