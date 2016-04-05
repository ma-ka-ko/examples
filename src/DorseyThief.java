import java.util.Collections;
import java.util.Scanner;
import java.util.ArrayList;
import java.lang.Runtime;



public class DorseyThief 
{
	public static final boolean DEBUG = false;
	
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
		
		public Sold (int v, int g)
		{
			this.v = v;
			this.g = g;
		}
		
		@Override
		public String toString()
		{
			return "v="+v+", g="+g;
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
			if(this.g == b.g) return this.v - b.v;
			return this.g - b.g;
		}
		@Override
		public String toString()
		{
			return this.v + "-" + this.g;
		}
	}
	
	public static Sold knapsack(ArrayList<Buyer> buyers, int totalGrams, int index)
	{
		Sold s = new Sold();
		if ( index < 0 || totalGrams == 0)
			return s;
		
		Buyer b = buyers.get(index);
		debug(b.toString());
		if (b.g > totalGrams)
		{
			debug(b + " X");
			return knapsack(buyers, totalGrams, index-1);
		}
		else
		{
			Sold with = knapsack(buyers, totalGrams-b.g, index -1);
			with.v += b.v;
			with.g += b.g;
			Sold without = knapsack(buyers, totalGrams, index-1);
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
	
	public static Sold dp_knapsack(ArrayList<Buyer> buyers, int totalGrams)
	{
		int n = buyers.size();
		Sold[][] K = new Sold[n+1][totalGrams+1];
		for (int i=0; i<=n; i++)
		{
			for (int g=0; g <= totalGrams;g++)
			{
				//debug("i = "+i+" g = "+g);
				if(i == 0 || g == 0)
					K[i][g] = new Sold(0,0);
				else
				{
					Buyer b1 = buyers.get(i-1);
					//debug(b1.toString());
					if ( b1.g <= g )
					{
						Sold t =  K[i-1][g - b1.g];
						Sold without = K[i-1][g];
						int withV = b1.v + t.v;
						int withG = b1.g + t.g; 
								
						//Sold with = new Sold( b1.v + t.v,  b1.g + t.g );
						
						if (withV >= without.v && withG >= without.g)
							K[i][g] = new Sold(withV,withG);
						else
							K[i][g] = without;
					}
					else
						K[i][g] = K[i-1][g];
				}
				//debug("i = "+i+", g = "+g + "  ===> " +K[i][g]);
			}
		}
		/*
		System.out.print("  \t");
		for (int y =0; y <=totalGrams; y++)
		{
			System.out.print("  "+ y+ "     "+ "\t");
		}
		System.out.print("\n");
			
		for(int x =0; x <=n; x++)
		{
			System.out.print("  " + x + "  \t");
			for (int y =0; y <=totalGrams; y++)
			{
				System.out.print(K[x][y] + "\t");
			}
			System.out.print("\n");
		}
		*/
		return K[n][totalGrams];
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
		//Collections.sort(buyers);
		//debug(buyers.toString());
		//System.out.println(buyers.toString());
		//Sold s = knapsack(buyers,x,n-1);
		Sold s = dp_knapsack(buyers,x);
		if (s.g == x)
			System.out.println(s.v);
		else
			System.out.println("Got caught!");
	}

}
