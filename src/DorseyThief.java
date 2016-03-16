import java.util.Scanner;
import java.util.ArrayList;
import java.lang.Runtime;


public class DorseyThief 
{
	public static class Buyer
	{
		public int v;
		public int a;
		public Buyer(int v, int a)
		{
			this.v = v;
			this.a = a;
		}
	}
	
	public static int knapsac(ArrayList<Buyer> buyers)
	{
		for(Buyer b: buyers)
		{
			System.out.println(b.v+" "+b.a);
		}
		return 0;
	}
	
	
	public static void main(String[] args) 
	{
		Runtime rt = Runtime.getRuntime();
		ArrayList<Buyer> buyers = new ArrayList<Buyer>();
		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		int x = in.nextInt();
		System.out.println(n + " " + x);
		for(int p = 0; p<n; p++)
		{
			int v = in.nextInt();
			int a = in.nextInt();
			Buyer b = new Buyer(v,a);
			buyers.add(b);
			
			//System.out.println(rt.maxMemory());
			System.out.println(rt.totalMemory());
			//System.out.println(v+" "+a);
		}
		knapsac(buyers);
	}

}
