import java.util.Collections;
import java.util.Scanner;
import java.util.ArrayList;
import java.lang.Runtime;



public class DorseyThief 
{
	public static final boolean DEBUG = true;
	
	public static void debug(String s)
	{
		if(DEBUG)
			System.out.println(s);
	}
	
	public static class Sold
	{
		public int v;
		public int g;
		public Sold ()
		{
			this.v = 0;
			this.g = 0;
		}
		
	}
	
	public static class Buyer implements Comparable<Buyer>
	{
		public int v;
		public int g;
		public Buyer(int v, int g)
		{
			this.v = v;
			this.g = g;
		}
		@Override
		public int compareTo(Buyer b) 
		{
			//return b.g  - this.g;
			return this.g - b.g;
		}
		@Override
		public String toString()
		{
			return this.v + "-" + this.g;
		}
	}
	
	public static Sold knapsac(ArrayList<Buyer> buyers, int totalGrams, int index)
	{
		Sold s = new Sold();
		if ( index < 0 || totalGrams == 0)
			return s;
		
		Buyer b = buyers.get(index);
		debug(b.toString());
		if (b.g > totalGrams)
		{
			debug(b + " X");
			return knapsac(buyers, totalGrams, index-1);
		}
		else
		{
			Sold with = knapsac(buyers, totalGrams-b.g, index -1);
			with.v += b.v;
			with.g += b.g;
			Sold without = knapsac(buyers, totalGrams, index-1);
			if (with.v >= without.v)
			{
				debug(b + " V");
				return with;
			}
			else
			{
				debug(b + " X");
				return without;
			}
		}
	}
	
	
	public static void main(String[] args) 
	{
		Runtime rt = Runtime.getRuntime();
		ArrayList<Buyer> buyers = new ArrayList<Buyer>();
		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		int x = in.nextInt();
		//System.out.println(n + " " + x);
		for(int p = 0; p<n; p++)
		{
			int v = in.nextInt();
			int g = in.nextInt();
			Buyer b = new Buyer(v,g);
			buyers.add(b);
		}
		debug(buyers.toString());
		Collections.sort(buyers);
		debug(buyers.toString());
		Sold s = knapsac(buyers,x,n-1);
		if (s.g == x)
			System.out.println(s.v);
		else
			System.out.println("Got caught!");
	}

}
