class DynamicArray {
public:
    int * arr = nullptr;
    int last = -1;
    int maxCap = 0;
    DynamicArray(int capacity) {
        maxCap = capacity;
        arr = (int *)malloc(capacity * sizeof(int));
        if (arr == nullptr)
        {
            std::printf("Failed to allocate memory");
        }
    }
    ~DynamicArray()
    {
        free(arr);
    }
    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(last + 1 >= maxCap){
            resize();
        }
        last++;
        arr[last] = n;
    }

    int popback() {
        int val = arr[last];
        --last;
        return val;
    }

    void resize() {
        maxCap *= 2;
        arr = (int *)realloc(arr, maxCap * sizeof(int));
        if (arr == nullptr)
        {
            std::printf("Failed to resize array");
        }
    }

    int getSize() {
        return last + 1;
    }

    int getCapacity() {
        return maxCap;
    }
};