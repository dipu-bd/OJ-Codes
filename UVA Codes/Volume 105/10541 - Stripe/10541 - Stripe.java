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
    public static int arr[] = new int[210];
    public static int cum[] = new int[210];
    public static BigInteger save[][] = new BigInteger[110][210]; 
    public static boolean _save[][];
    
    public static Scanner sc = new Scanner(System.in);
    
    public static void main(String args[])
    {
        int test = sc.nextInt();
        for(int cas = 1; cas <= test; ++cas)
        {
            int n = sc.nextInt();
            int k = sc.nextInt(); 
            for(int i = 1; i <= k; ++i)
            {
                arr[i] = sc.nextInt();
                cum[i] = cum[i - 1] + arr[i];
                if(i > 1) cum[i]++;
            }
            
            _save = new boolean[110][210]; 
            System.out.println(recur(k, n));
        }
    }
    
    public static BigInteger recur(int p, int t)
    {
        if(t < 0) return BigInteger.ZERO;
        if(p == 0) return BigInteger.ONE;
        if(t == 0) return BigInteger.ZERO;
        
        if(_save[p][t]) return save[p][t];
        
        _save[p][t] = true;
        save[p][t] = BigInteger.ZERO;
        
        int b = cum[p - 1] + p - 2;
        int e = t - arr[p];
        if(p > 1) --e;
        if(b < 0) b = 0;
        
        for(int i = b; i <= e; ++i)
        {
            save[p][t] = save[p][t].add(recur(p - 1, i));
        }
        
        return save[p][t];
    } 
}