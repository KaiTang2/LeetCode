#include"0206.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
ListNode* frontPointer;

bool check(ListNode* current)
{
    if (current != NULL)
    {
        if (!check(current->next))
        {
            return false;
        }
        if (current->val == frontPointer->val)
        {
            frontPointer = frontPointer->next;
            return true;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool isPalindrome(ListNode* head) {
    if (head == nullptr)
    {
        return false;
    }
    frontPointer = head;
    return check(head);
}

int main()
{
	/*
	编写一个函数，检查输入的链表是否是回文的。

 

示例 1：

输入： 1->2
输出： false 
示例 2：

输入： 1->2->2->1
输出： true 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-linked-list-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    next->next = new ListNode(10);
    next = next->next;
    next->next = nullptr;
    /*next->next = new ListNode(11);
    next = next->next;
    next->next = nullptr;*/
    for (int i = 9; i >= 0; i--)
    {
        next->next = new ListNode(i);
        next = next->next;
        next->next = nullptr;
    }
    next = head;
    while (next != nullptr)
    {
        cout << next->val << " ";
        next = next->next;
    }
    cout << endl;
    
	frontPointer = new ListNode(0);
    cout << isPalindrome(head) << endl;
	int press = getchar();
	return 1;
}