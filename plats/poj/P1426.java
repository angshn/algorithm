package plats.poj;

import java.util.LinkedList;
import java.util.Scanner;

public class P1426 {
    static int n;
    static boolean to_target = false;
    public static void dfs(long x,int dep) {
        if(dep > 19 || to_target){
            return;
        }
        if(x%n ==0){
            System.out.println(x);
            to_target = true;
            return ;
        }
        dfs(x*10,dep+1);
        dfs(x*10+1,dep+1);
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        while (cin.hasNextInt()) {
            to_target = false;
            n = cin.nextInt();
            if (n == 0)
                break;
            dfs(1L,0);
        }
        cin.close();

    }
}
