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
        BigInteger fib[] = new BigInteger[250];
        fib[0] = BigInteger.valueOf(1);
        fib[1] = BigInteger.valueOf(2);
        for(int i = 2; i <= 210; ++i)
        {
            fib[i] = fib[i - 1].add(fib[i - 2]); 
        } 
        
        boolean newline = false;
        while(sc.hasNext())
        {
            String a = sc.next();
            String b = sc.next(); 
            
            BigInteger num1 = BigInteger.ZERO;
            for(int i = 0, j = a.length() - 1; j >= 0; --j, ++i)
            {
                if(a.charAt(j) == '1')
                    num1 = num1.add(fib[i]);
            }
            
            BigInteger num2 = BigInteger.ZERO;
            for(int i = 0, j = b.length() - 1; j >= 0; --j, ++i)
            {
                if(b.charAt(j) == '1')
                    num2 = num2.add(fib[i]);
            }
            
            BigInteger num = num1.add(num2);
            
            String res = ""; 
            for(int i = 205; i >= 0; --i)
            {
                if(num.compareTo(fib[i]) >= 0)
                {
                    num = num.subtract(fib[i]);
                    res += "1";
                }
                else if(res.length() > 0)
                {
                    res += "0";
                }
            }
            if(res.length() == 0) 
                res += "0";
            
            if(newline) System.out.println();
            else newline = true;
            System.out.println(res);
        }
    }
}