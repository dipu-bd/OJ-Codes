/**
 @author Sudipto Chandra Das
 @email dipu.sudipta@gmail.com
 @univ SUST
*/

import java.io.*;
import java.util.*;
import java.math.*;

class Main
{
    public static Scanner sc = new Scanner(System.in);
    
    public static void main(String args[])
    {
        BigInteger fact[] = new BigInteger[350];
        fact[0] = BigInteger.ONE;
        for(int i = 1; i <= 310; ++i)
        {
            fact[i] = fact[i - 1].multiply(BigInteger.valueOf(i));
        }
        
        while(sc.hasNext())
        {
           int n = sc.nextInt();
           int p = sc.nextInt();
           if((n % 2 != 0) || (n < 2 * p))
           {
               System.out.println("0");
           }
           else 
           {
               n -= 2 * p;
               if(n == 0)
               {
                   System.out.println("1");
               }
               else
               {
                   BigInteger res = fact[n - 2].multiply(BigInteger.valueOf(n + 1));
                   System.out.println(res);
               }
           }
       }
    }
}