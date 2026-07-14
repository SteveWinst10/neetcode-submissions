class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer,Integer> map = new HashMap<>();
    for(int num: nums){
        map.merge(num, 1, Integer::sum);
    }
    System.out.println(map);


    PriorityQueue<Map.Entry<Integer, Integer>> maxHeap = new PriorityQueue<>(
            Comparator.comparingInt((Map.Entry<Integer, Integer> entry) -> entry.getValue())
    );

    for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
        maxHeap.offer(entry);
        if (maxHeap.size() > k) {
            maxHeap.poll();
        }
    }

    int[] resultInt = new int[k];
    for (int i = 0; i < k; i++) {
        resultInt[i] = maxHeap.poll().getKey();
    }
    return resultInt;
    }
}
