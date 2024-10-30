import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.StringTokenizer;

/*
1
2 100
1 2 409

1
2 100
1 2 409 2

1
5 50
1 3 100 1
1 5 10 2
2 3 123 2
5 4 55 1
 */
public class E2 {

	static long lastOne;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			long reqSum=fs.nextLong();
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) nodes[i]=new Node();
			for (int i=1; i<n; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
//				int w=fs.nextInt(); int type=1; //type=fs.nextInt();
				int w=fs.nextInt(), type=fs.nextInt();
				nodes[a].adj.add(nodes[b]);
				nodes[a].costs.add(w);
				nodes[a].types.add(type);
				nodes[b].adj.add(nodes[a]);
				nodes[b].costs.add(w);
				nodes[b].types.add(type);
			}
			nodes[0].dfs0(null, 0, -1);
			PriorityQueue<Item> ones=new PriorityQueue<>();
			PriorityQueue<Item> twos=new PriorityQueue<>();
			long curSum=0;
			lastOne=(long)1e18;
			for (Node nn:nodes) {
				//root
				if (nn.parentEdgeType==-1) continue;
				
				Item i=new Item(nn.nLeaves, nn.parEdgeWeight, nn.parentEdgeType);
				if (i.type==1)
					ones.add(i);
				else
					twos.add(i);
				curSum+=i.curCost();
			}
			int ans=0;
			while (curSum>reqSum) {
				if (benefitOfOne(ones)>=curSum-reqSum) {
					ans++;
					break;
				}
//				System.out.println(ones+" "+twos);
				if (benefitOfTwo(ones)>=benefitOfOne(twos)) {
//					System.out.println("Taking two ones");
					curSum-=benefitOfTwo(ones);
					takeTwo(ones);
				}
				else {
//					System.out.println("Taking one two");
					curSum-=benefitOfOne(twos);
					takeOne(twos);
				}
				ans+=2;
			}
//			System.out.println("Finished with "+curSum+" "+reqSum);
			if (curSum+lastOne<=reqSum) {
				ans--;
			}
			System.out.println(ans);
		}
	}
	
	static long benefitOfTwo(PriorityQueue<Item> pq) {
		if (pq.isEmpty()) return 0;
		Item first=pq.remove();
		int originalWeight=first.curWeight;
		long ans=first.benefitIfTake();
		first.curWeight/=2;
		long ans2=Math.max(first.benefitIfTake(), benefitOfOne(pq));
		first.curWeight=originalWeight;
		pq.add(first);
		return ans+ans2;
	}
	
	static void takeTwo(PriorityQueue<Item> pq) {
//		System.out.println("Benefit1: "+benefitOfOne(pq));
		takeOne(pq);
//		System.out.println("Benefit1: "+benefitOfOne(pq));
		lastOne=benefitOfOne(pq);
		takeOne(pq);
	}
	
	static void takeOne(PriorityQueue<Item> pq) {
//		System.out.println("Benefit2: "+benefitOfOne(pq));
		Item i=pq.remove();
		i.curWeight/=2;
		pq.add(i);
	}
	
	static long benefitOfOne(PriorityQueue<Item> pq) {
		if (pq.isEmpty()) return 0;
		return pq.peek().benefitIfTake();
	}
	
	static class Item implements Comparable<Item> {
		int nTimes;
		int curWeight;
		int type;
		public Item(int nTimes, int curWeight, int type) {
			this.nTimes=nTimes;
			this.curWeight=curWeight;
			this.type=type;
		}
		
		long curCost() {
			return curWeight*(long)nTimes;
		}
		
		long benefitIfTake() {
			long diff=curWeight-curWeight/2;
			return diff*nTimes;
		}
		
		public int compareTo(Item o) {
			return -Long.compare(benefitIfTake(), o.benefitIfTake());
		}
		
		public String toString() {
			return "curWeight: "+curWeight;
		}
	}
	
	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		ArrayList<Integer> costs=new ArrayList<>();
		ArrayList<Integer> types=new ArrayList<>();
		int nLeaves;
		int parEdgeWeight, parentEdgeType;
		
		public void dfs0(Node par, int parEdgeWeight, int parEdgeType) {
			this.parEdgeWeight=parEdgeWeight;
			this.parentEdgeType=parEdgeType;
//			System.out.println("Current size: "+adj.size());
			if (adj.size()==1 && par!=null) {
				nLeaves++;
				return;
			}
			for (int i=0; i<adj.size(); i++) {
				Node o=adj.get(i);
				if (o==par) continue;
				o.dfs0(this, costs.get(i), types.get(i));
				nLeaves+=o.nLeaves;
			}
		}
	}

	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}