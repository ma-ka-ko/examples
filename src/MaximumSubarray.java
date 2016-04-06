import java.util.Arrays;
import java.util.Scanner;




public class MaximumSubarray 
{
	public static final boolean DEBUG = true;
	
	public static void debug(String s)
	{
		if(DEBUG)
			System.out.println(s);
	}
	
	public static long solve(int[] A)
	{

		
		long sum = A[0];
		int size = A.length;
		//long R[][] = new long[size][size];
		
		/*for (int x =0; x < A.length; x++)
		{
			//R[0][x] = A[x];
			//System.out.print(A[x]+" ");
			sum = Math.max(A[x] , sum);
		}*/
		//System.out.println();
		//printArray(size,R);
		
		for(int start = 0; start < size; start++)
		{
			long previous = A[start];
			sum = Math.max(previous , sum);
			long current = 0;
			for (int take = 1; take < size - start; take++)
			{
				//R[take][start] = A[take] + R[take-1][start] ;
				
				//debug("Sum: "+sum);
				//debug("Start: " + start + ", Take: "+ take);
				current = A[start + take] + previous ;
				//debug("Current: " + current + " = Previous: "+ previous + " + A[start + take]: " + A[start + take]);
				//printArray(size, R);
				//sum = Math.max(R[take][start] , sum);
				sum = Math.max(current , sum);
				//debug("Math.max(current , sum): "+ sum);
				//debug("----------------------");
				previous = current;
			}
			//debug("Previoius === " + previous);
		}
		
		//printArray(size, R);
		
		return sum;
	}

	private static void printArray(int size, long[][] R) 
	{
		System.out.print("\t");
		String line = "";
		for (int y =0; y <size; y++)
		{
			System.out.print( y+ "\t");
			line += "----------";
		}
		System.out.print("\n"+line+"\n");
			
		for(int x =0; x < size; x++)
		{
			System.out.print("  " + x + "  |\t");
			for (int y =0; y <size; y++)
			{
				System.out.print(R[x][y] + "    \t");
			}
			System.out.print("\n");
		}
		System.out.print("\n"+line+"\n");
	}
	
	public static void main(String[] args) 
	{
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		for(int t = 0; t<T; t++)
		{
			int N = in.nextInt();
			int[] A = new int[N];
			
			A[0] = in.nextInt();;
			int sum = A[0];
			for(int n=1; n<N; n++)
			{
				int a = in.nextInt();
				A[n] = a;
				sum = Math.max(Math.max(sum,sum+a), a);
				
			}
			//System.out.print("\n");
			long subsum = solve(A);
			
			System.out.println(subsum + " " + sum);
		}
		
	}

}
