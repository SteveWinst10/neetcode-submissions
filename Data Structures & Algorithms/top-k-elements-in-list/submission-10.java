class Solution {
    public int[] topKFrequent(int[] nums, int k) {
      HashMap<Integer,Integer> map = new HashMap<>();
    for(int num: nums){
        map.merge(num, 1, Integer::sum);
    }
    System.out.println(map);
    List<List<Integer>> frequency = new ArrayList<>(nums.length+1);
    for (int i = 0; i <= nums.length; i++) {
        frequency.add(new ArrayList<>());
    }
    for (int i = 0; i < nums.length; i++) {
        frequency.add(new ArrayList<>());
    }
    map.forEach((key, value) -> {
        frequency.get(value).add(key);
    });
    int[] result = new int[k];
    int i=0;
    outer:
    for(int j = frequency.size() - 1; j >= 0; j--){
        for (int element : frequency.get(j)) {
            result[i] = element;
            ++i;
            if (i == k) {
                break outer;
            }
        }
    }
    System.out.println(frequency);
    return result;
}
}