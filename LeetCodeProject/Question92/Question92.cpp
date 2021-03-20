#include"Question92.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* reverseBetween(ListNode* head, int left, int right) {
    int num = 0;
    ListNode* h = new ListNode(-1);
    h->next = head;
    ListNode* pre = h;
    ListNode* cur = new ListNode();
    ListNode* nex = new ListNode();
    while (num < left - 1)
    {
        pre = pre->next;
        num++;
    }
    cur = pre->next;
    for (int i = left; i < right; i++)
    {
        nex = cur->next;
        cur->next = nex->next;
        nex->next = pre->next;
        pre->next = nex;
    }
    return h->next;
}

int main()
{
    /*
    给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


输入：head = [1,2,3,4,5], left = 2, right = 4
输出：[1,4,3,2,5]
    */
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    ListNode* next = head->next;
    for (int i = 2; i < 10; i++)
    {
        next->next = new ListNode(i);
        next = next->next;
        next->next = nullptr;
    }
    next = head;
    while (next!=nullptr)
    {
        cout << next->val << " ";
        next = next->next;
    }
    cout << endl;
    next = reverseBetween(head, 1,2);
    while (next != nullptr)
    {
        cout << next->val << " ";
        next = next->next;
    }
    cout << endl;
    int pass = getchar();
    return 0;
}