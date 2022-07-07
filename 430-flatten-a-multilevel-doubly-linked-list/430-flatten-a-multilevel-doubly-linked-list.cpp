/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        stack<Node*> st;
        Node* curr=head;
        Node* ans= head;
        Node* res= ans;
        
        while(curr!= NULL)
        {
            //checking in straight linked list
            if(curr!=head)
            {
                ans->next= curr;
                curr->prev= ans;
                ans= ans->next;
            }
            
            //if child exist
            if(curr->child != NULL)
            {
                if(curr->next!= NULL)
                {
                    st.push(curr->next);
                }
                
                Node* temp= curr->child;
                temp-> prev= ans;
                curr-> child= NULL;
                curr= temp;
                ans->next= curr;
            }
            
            //traverse the next element
            else
            {
                curr= curr->next;
                if(curr== NULL && !st.empty())
                {
                    curr= st.top();
                    st.pop();
                }
            }
        }
        
        return res;
    }
};