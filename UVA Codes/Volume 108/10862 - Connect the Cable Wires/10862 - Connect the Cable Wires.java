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
        //build res
        int mxsz = 2010;
        BigInteger res[] = new BigInteger[mxsz];
        res[0] = BigInteger.ZERO;
        res[1] = BigInteger.ONE;
        for(int i = 2; i < mxsz; ++i)
        {
            res[i] = res[i - 1].multiply(BigInteger.valueOf(3));
            res[i] = res[i].subtract(res[i - 2]);
        }
        
        while(sc.hasNext())
        {
            int n = sc.nextInt();
            if(n == 0) break;
            System.out.println(res[n]);
        }
    }
}