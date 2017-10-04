import java.util.Scanner;

public class Main{
	public static void main(String args[]) {
		Scanner in=new Scanner(System.in);
		Coin p=new Coin(in.next().split("[.]"));
		Coin a=new Coin(in.next().split("[.]"));
		in.close();
		Coin result = new Coin();
		result.total=a.total-p.total;
		if(result.total<0) {
			System.out.print("-");
			result.total=-result.total;
		}
		result.galleon=result.total/29/17;
		result.sickle=result.total/29%17;
		result.kunt=result.total%29;
		System.out.print(result.galleon+"."+result.sickle+"."+result.kunt);
	}
}

class Coin{
	int galleon;
	int sickle;
	int kunt;
	int total;
	
	public Coin() {
		this.galleon=0;
		this.sickle=0;
		this.kunt=0;
		this.total=0;
	}
	
	public Coin(String ss[]) {
		this.galleon=Integer.parseInt(ss[0]);
		this.sickle=Integer.parseInt(ss[1]);
		this.kunt=Integer.parseInt(ss[2]);
		this.total=this.galleon*29*17+this.sickle*29+this.kunt;
	}
}