#include <bits/stdc++.h>

using namespace std;
struct Node {
    string name, sex, id;
    int grade;
};
vector<Node> a, b;
int main() {
    int n;
    cin >> n;
    while (n--) {
        Node node;
        cin >> node.name >> node.sex >> node.id >> node.grade;
        if (node.sex == "M") a.push_back(node);
        else b.push_back(node);
    }
    sort(a.begin(), a.end(), [](const Node &x, const Node &y) {return x.grade < y.grade; });
    sort(b.begin(), b.end(), [](const Node &x, const Node &y) {return x.grade > y.grade; });
    if (!a.size() || !b.size()) {
        if (!b.size()) printf("Absent\n");
        else printf("%s %s\n", b[0].name.data(), b[0].id.data());
        if (!a.size()) printf("Absent\n");
        else printf("%s %s\n", a[0].name.data(), a[0].id.data());
        printf("NA\n");
    } else {
        if (!b.size()) printf("Absent\n");
        else printf("%s %s\n", b[0].name.data(), b[0].id.data());
        if (!a.size()) printf("Absent\n");
        else printf("%s %s\n", a[0].name.data(), a[0].id.data());
        printf("%d\n", b[0].grade - a[0].grade);
    }
    return 0;
}
