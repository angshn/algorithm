// package plats.poj;

import java.util.*;
import java.util.concurrent.LinkedBlockingDeque;
import java.util.concurrent.LinkedBlockingQueue;

public class P3278{
    static final int N = (int)1e5+10;
    static final int LEFT_LIMITS = 0;
    static final int RIGHT_LIMITS = (int)1e5;
    static final boolean[] vis = new boolean[N];
    static int n,k;
    public static boolean in_range(int pos){
        return pos >=LEFT_LIMITS && pos <=RIGHT_LIMITS;
    }

    public static void bfs(int start){
        Queue<Pair> q= new LinkedBlockingQueue<Pair>(N);
        q.add(new Pair(0,start));
        while(!q.isEmpty()){
            Pair p = q.remove();

            if(p.y == k){
                System.out.println(p.x);
                break;
            }
            if(in_range(p.y-1) && !vis[p.y-1]){
                vis[p.y-1] = true;
                q.add(new Pair(p.x+1, p.y-1));
            }
            if(in_range(p.y+1) && !vis[p.y+1]){
                vis[p.y+1] = true;
                q.add(new Pair(p.x+1, p.y+1));
            }
            if(in_range(p.y<<1) && !vis[p.y<<1]){
                vis[p.y<<1] = true;
                q.add(new Pair(p.x+1, p.y<<1));
            }

        }

    }
    public static void main(String[] args) {
        Scanner cin= new Scanner(System.in);
        int t = cin.nextInt();
        for(int z=0;z<t;z++){
            for(int i=0;i<N;i++){
                vis[i] = false;
            }
            n = cin.nextInt();
            k = cin.nextInt();
            if(n>=k) {
                System.out.println(n-k);
            }
            else 
                bfs(n);
        }

    }

    
}

class Pair{
    int x,y;
    public Pair(int _x,int _y){
        x = _x;
        y = _y;
    }

    
}