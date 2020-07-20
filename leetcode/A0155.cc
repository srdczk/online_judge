class MinStack {
public:
    static const int kMaxV = 10010;
    int s1[kMaxV], s2[kMaxV];
    int tt = 0;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s1[++tt] = x;
        if (tt == 1) s2[tt] = x;
        else s2[tt] = min(x, s2[tt - 1]);
    }
    
    void pop() {
        --tt;
    }
    
    int top() {
        return s1[tt];
    }
    
    int getMin() {
        return s2[tt];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */