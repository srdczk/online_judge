#include <bits/stdc++.h>

using namespace std;

struct Node {
    int dis;
    double price;
    Node() {}
    Node(int d, double p): dis(d), price(p) {}
};

bool cmp(const Node &a, const Node &b) {
    return a.dis < b.dis;
}

int main() {
    int C, D, Da, n;
    scanf("%d%d%d%d", &C, &D, &Da, &n);
    vector<Node> ns(n);
    for (int i = 0; i < n; ++i) {
        cin >> ns[i].price >> ns[i].dis;
    }
    sort(ns.begin(), ns.end(), cmp);
    int maxD = C * Da;
    if (ns[0].dis) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    for (int i = 1; i < ns.size(); ++i) {
        if (ns[i].dis - ns[i - 1].dis > maxD) {
            if (ns[i - 1].dis + maxD < D) {
                double d = (double)(ns[i - 1].dis + maxD);
                printf("The maximum travel distance = %.2f\n", d);
                return 0;
            }
            break;
        }
    }
    if (ns[n - 1].dis + maxD < D) {
        double d = (double)(ns[n - 1].dis + maxD);
        printf("The maximum travel distance = %.2f\n", d);
        return 0;
    }
    while (ns[ns.size() - 1].dis >= D) {
        ns.pop_back();
    }
    int i = 0;
    double sumP = 0, curC = 0;
    while (i < ns.size()) {
        int x = i + 1;
        while (x < ns.size()) {
            if (ns[x].dis - ns[i].dis > maxD) break;
            if (ns[x].price < ns[i].price) break;
            x++;
        }
        if (x == ns.size()) {
            //如果到最后都没找到
            if (ns[i].dis + maxD >= D) {
                //在这里充满,可以结束了
                //需要的油量
                double need = (double)(D - ns[i].dis) / Da;
                if (curC < need) sumP += (need - curC) * ns[i].price;
                printf("%.2f\n", sumP);
                return 0;
            } else {
                //就是没有找到比他小的而已
                //在这里充满,开到最小的地方去
                sumP += (double)(C - curC) * ns[i].price;
                //找到最小的地方:
                double MIN = 100000000.0;
                int u = -1;
                for (int k = i + 1; k < x; ++k) {
                    if (ns[k].price < MIN) {
                        MIN = ns[k].price;
                        u = k;
                    }
                }
                //消耗的油量
                curC = C - (ns[u].dis - ns[i].dis) / (double)Da;
                i = u;
                //奔跑到此地冲油
            }
        } else if (ns[x].dis - ns[i].dis > maxD) {
            //在能跑的范围内没有比他小的
            //充满跑到最小的地方再冲
            sumP += (double)(C - curC) * ns[i].price;
                //找到最小的地方:
                double MIN = 100000000.0;
                int u = -1;
                for (int k = i + 1; k < x; ++k) {
                    if (ns[k].price < MIN) {
                        MIN = ns[k].price;
                        u = k;
                    }
                }
                //消耗的油量
                curC = C - (ns[u].dis - ns[i].dis) / (double)Da;
                i = u;
                //奔跑到此地冲油
        } else {
            //有一个比他更小的
            //充刚好能到那里的电
            //x 这里 油价更加小
            //保证刚好到此地
            double d = (double)(ns[x].dis - ns[i].dis);
            double need = d / (double)Da;
            if (curC < need) {
                sumP += (need - curC) * ns[i].price;
                curC = need;
            }
            curC -= need;
            i = x;
        }
    }
    return 0;
}
