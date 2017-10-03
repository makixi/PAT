import java.util.Arrays;
import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		int d=in.nextInt();
		Cake[] mm=new Cake[n];
		for(int i=0;i<n;++i) {
			mm[i]=new Cake();
			mm[i].save=in.nextDouble();
		}
		for(int i=0;i<n;++i) {
			mm[i].price=in.nextDouble();
			mm[i].pricePeer=mm[i].price/mm[i].save;
		}
		in.close();
		Arrays.sort(mm);
		int curr=0,index=0;
		double res=0;
		while(curr<d) {
			if(curr+mm[index].save<=d) {
				curr+=mm[index].save;
				res+=mm[index].price;
				++index;
			}else {
				res+=mm[index].pricePeer*(d-curr);
				curr=d;
			}
		}
		System.out.printf("%.2f", res);
	}
}
class Cake implements Comparable<Cake>{
	double save;
	double price;
	double pricePeer;
	@Override
	public int compareTo(Cake c) {
		if(this.pricePeer>c.pricePeer)return -1;
		else if(this.pricePeer<c.price)return 1;
		return 0;
	}
}