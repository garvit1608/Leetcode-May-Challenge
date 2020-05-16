/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *oddEvenList(struct ListNode *head)
{

  if (head == NULL || head->next == NULL || (head->next && head->next->next == NULL))
    return head;

  struct ListNode *ptr = head, *evenStart = NULL, *prev = NULL, *current = head;
  int count;
  for (count = 1; current->next != NULL; count++)
  {

    if (count == 2)
    {
      evenStart = current;
    }

    ptr = current;
    prev = current;
    current = current->next;

    if (ptr->next)
      ptr->next = ptr->next->next;
  }

  if (count % 2 == 0)
  {
    prev->next = evenStart;
  }
  else
  {
    current->next = evenStart;
  }

  return head;
}