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
        while(sc.hasNext())
        {
            BigInteger n = sc.nextBigInteger();
            int d = sc.nextInt();
            if(n.equals(BigInteger.ZERO) && d == 0) break;
            BigInteger res = n.pow(d);
            System.out.println(res);
        }
    }
}