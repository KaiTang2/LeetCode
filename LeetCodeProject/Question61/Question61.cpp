#include"Question61.h"
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (!head)
    {
        return head;
    }
    ListNode* h = new ListNode(0, head);
    int len = 1;
    while (head->next)
    {
        len++;
        head = head->next;
    }
    head->next = h->next;
    len = len - k % len;
    while (len > 0)
    {
        head = head->next;
        len--;
    }
    h = head;
    head = head->next;
    h->next = nullptr;
    return head;

}
int main()
{
    /*
    给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
    输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
输入：head = [0,1,2], k = 4
输出：[2,0,1]
    */
    vector<int> val = { 1,2,3,4,5 };
    ListNode* node0 = new ListNode(0);
    ListNode* head = new ListNode(-1,node0);
    for (int v : val)
    {
        node0->next = new ListNode(v);
        node0 = node0->next;
    }
    node0 = head;
    while (node0)
    {
        cout << node0->val << " ";
        node0 = node0->next;
    }
    cout << endl;
    head = rotateRight(head, 3);
    node0 = head;
    while (node0)
    {
        cout << node0->val << " ";
        node0 = node0->next;
    }
    cout << endl;
    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}