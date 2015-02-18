/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.*;
import java.math.*;

/**
 *
 * @author Dipu
 */
class Main {

    public static Scanner sc = new Scanner(System.in);
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        int test = sc.nextInt();
        for(int cas = 1; cas <= test; ++cas)
        {
            BigDecimal sum = BigDecimal.ZERO;
            while(sc.hasNext())
            {
                BigDecimal bd = sc.nextBigDecimal();
                if(bd.equals(BigDecimal.ZERO)) break;
                sum = sum.add(bd);
            }
            
            String res = sum.stripTrailingZeros().toPlainString();
            if(res.contains(".")) 
            {
                while(res.endsWith("0")) res = res.substring(0, res.length() - 1);
                if(res.startsWith(".")) res = "0" + res;
                if(res.endsWith(".")) res = res.substring(0, res.length() - 1);
            }
            System.out.println(res);
        }
    }
    
}
