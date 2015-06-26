/**
* @author Sudipto Chandra Das
* @email dipu.sudipta@gmail.com
* @univ SUST
*/

import java.util.Scanner;
import java.math.BigInteger;

class Main {
    
    public static BigInteger nCk(long n, long k)
    {
        if(2 * k > n) return nCk(n, n - k);
        
        BigInteger up = BigInteger.ONE;
        BigInteger down = BigInteger.ONE;
        for (long i = 1; i <= k; ++i)
        {
            down = down.multiply(BigInteger.valueOf(i));
            up = up.multiply(BigInteger.valueOf(n - i + 1));
        } 
        return up.divide(down);
    }
    
    public static void main(String args[])
    {
        int k;
        long n;
        long arr[] = new long[10];
        Scanner sc = new Scanner(System.in);
        
        while (sc.hasNext())
        {
            //take input
            k = sc.nextInt();
            if(!sc.hasNext()) return;
            n = sc.nextLong();
            for (int i = 0; i < k; ++i)
            { 
                long l = sc.nextLong();
                n -= l; 
                arr[i] = sc.nextLong() - l + 1;
            }
            
            //process using inclusion exclusion
            BigInteger res = BigInteger.ZERO;
            if(n < 0)
            {
                System.out.println(res);
                continue;
            }
            
            for (int m = (1 << k) - 1; m >= 0; --m)
            {
                long p = n;
                int popc = 0;
                for (int i = 0; i < k; ++i) //iterate to build n
                {
                    if ((m & (1 << i)) != 0)
                    {
                        ++popc;
                        p -= arr[i];
                    }
                }
                
                if (p >= 0)
                {
                    if ((popc & 1) == 0) //inclusion
                    {
                        res = res.add(nCk(p + k - 1, k - 1));
                    }
                    else //exclusion
                    {
                        res = res.subtract(nCk(p + k - 1, k - 1));
                    }
                } 
            }
            
            //show final result
            System.out.println(res);
        }
    }
}
