#include"Question82.h"

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
    ListNode* h = new ListNode(0, head);
    ListNode* current = h;
    while (current->next && current->next->next)
    {
        if (current->next->val == current->next->next->val)
        {
            int x = current->next->val;
            while (current->next && current->next->val == x)
            {
                current->next = current->next->next;
            }
        }
        else
        {
            current = current->next;
        }
    }
    return h->next;
}int main()
{
    /*
    存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现 的数字。

返回同样按升序排列的结果链表。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]
输入：head = [1,1,1,2,3]
输出：[2,3]

提示：

链表中节点数目在范围 [0, 300] 内
-100 <= Node.val <= 100
题目数据保证链表已经按升序排列

    */

    cout << "Press any key to exit" << endl;
    int pass = getchar();
    return 0;
}