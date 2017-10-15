import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException{
		BufferedReader in= new BufferedReader(new InputStreamReader(System.in));
		String []str=in.readLine().split(":");
		in.close();
		int times=Integer.parseInt(str[0])*60+Integer.parseInt(str[1]);
		if(times<=12*60)System.out.print("Only "+str[0]+":"+str[1]+".  Too early to Dang.");
		else {
			for(int i=times-12*60;i>0;i-=60)System.out.print("Dang");
		}
	}	
	
}
