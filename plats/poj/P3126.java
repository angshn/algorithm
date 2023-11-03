package plats.poj;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;
public class P3126{

    static boolean is_prime(long  n){
        if(n<=1) return false;
        for (long i = 2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }

    static int a,b;
    static int vis[] = new int[10001];
    static void bfs(){

        LinkedList<Pair> q = new LinkedList<Pair>();
        q.add(makePair(0, a));
        Arrays.fill(vis, 0);
        vis[a]=1;
        while(!q.isEmpty()){
            Pair p = q.remove();
            if(p.y == b){
                System.out.println(p.x);
                return ;
            }
            char[] s = String.valueOf(p.y).toCharArray();
            for(int i=0;i<4;i++){
                for(int j=0;j<10;j++){
                    if(i==0 && j== 0) continue;
                    char old = s[i];
                    s[i] = (char)(j + '0');
                    int x= Integer.valueOf(String.valueOf(s)).intValue();
                    if(is_prime(x) && vis[x] == 0){
                        vis[x] = 1;
                        q.add(makePair(p.x + 1, x));
                    }
                    s[i] = old;
                }
            }
        }
    }
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int t = cin.nextInt();
        for (int k = 0; k < t; k++) {
            a = cin.nextInt();
            b = cin.nextInt();
            bfs();
        }
        cin.close();
    }
    static Pair makePair(int _x,int _y){
        return new Pair(_x, _y);
    }
    static class Pair{
        int x,y;
        public Pair(int _x,int _y){
            x = _x;y = _y;
        }
    }

}

