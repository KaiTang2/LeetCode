#include"Question83.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* deleteDuplicates(ListNode* head) {
    if (!head)
    {
        return head;
    }
    ListNode* current = head;
    while (current->next)
    {
        if (current->val == current->next->val)
        {
            current->next = current->next->next;
        }
        else
        {
            current = current->next;
        }

    }
    return head;
}
int main()
{
    /*
    存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，使每个元素 只出现一次 。
返回同样按升序排列的结果链表。
输入：head = [1,1,2]
输出：[1,2]
输入：head = [1,1,2,3,3]
输出：[1,2,3]
    */
    ListNode* node9 = new ListNode(9);
    ListNode* node8 = new ListNode(9, node9);
    ListNode* node7 = new ListNode(7, node8);
    ListNode* node6 = new ListNode(7, node7);
    ListNode* node5 = new ListNode(7, node6);
    ListNode* node4 = new ListNode(5, node5);
    ListNode* node3 = new ListNode(5, node4);
    ListNode* node2 = new ListNode(1, node3);
    ListNode* node1 = new ListNode(1, node2);
    ListNode* node0 = new ListNode(1, node1);
    deleteDuplicates(node0);
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