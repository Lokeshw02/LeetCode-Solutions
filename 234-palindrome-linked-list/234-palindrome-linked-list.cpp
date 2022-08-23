/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL) 
            return head ;
        
        ListNode* newHead = reverse(head->next) ;
        
        head->next->next = head ;
        head->next = NULL ;
        
        return newHead ;
    }
    
    ListNode * middle(ListNode * head){
       ListNode * slow = head ;
       ListNode * fast = head->next ;
       
        while(fast != NULL && fast->next != NULL){
            slow = slow->next ;
            fast = fast->next->next ;
        }
        return slow ;
    }
    
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true ;
        ListNode* mid = middle(head) ;
        ListNode* last = reverse(mid->next) ;
        ListNode* curr = head ;
        
        while(last != NULL){
            if(last->val != curr->val )
                return false ;
            
            last = last->next ;
            curr = curr->next ;
        }
        
        return true ;
    }
};