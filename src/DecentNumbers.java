import java.io.*;
import java.util.*;

public class DecentNumbers
{
    public static String getDecentNumber(int digits)
    {
        String rv="";
        int fives = 0;
        int trees = 0;
        while(digits > 0)
        {
            System.out.println(digits );
            if (digits % 3 == 0)
            {
                fives = fives + digits/3;
                digits = 0;
            }
            else if(digits / 5 > 0)
            {
                trees ++;
                digits -= 5;
            }
            else if (digits % 5 == 0)
            {
                trees = trees + digits/5;
                digits = 0;
            } 
            else if(digits / 3 > 0)
            {
                fives ++;
                digits -= 3;
            }
            else
            {
                return "-1";
            }
        }
        for (int x=0; x < fives; x++)
        {
            rv += "555";
        }
        for (int x=0; x < trees; x++)
        {
            rv += "33333";
        }
        return rv;
    }
    
    public static String fastDecentNumber(int d)
    {
        int trees = 0;
        for(int x =0; x<=(d/5); x++)
        {
            //System.out.println(x);
            if ( (d-5*x) %3 == 0)
            {
                trees = x;
                break;
            }
        }
        //System.out.println("trees = " + trees);
        if( trees == 0)
        {
            if (d%3 == 0)
                for (int x=0; x< d; x++)
                    System.out.print('5');
            else
                System.out.print("-1");
        }
        else
        {
            for (int x=0; x< (d-5*trees); x++)
                System.out.print('5');
            for (int x=0; x< (5*trees); x++)
                System.out.print('3');
        }
        return "";
 
    }

    public static void main(String[] args) throws IOException
    {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int x = 0; x<t; x++)
        {
            int d = in.nextInt();
            String dn = fastDecentNumber(d);
            System.out.println(dn);
        }
        
    }
}
