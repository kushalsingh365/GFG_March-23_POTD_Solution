class Solution {

  public:

    vector<Node*> findAnagrams(struct Node* head, string s) {

        // code here

        vector<Node*> res;

        vector<int> window(26,0),required_window(26,0);

        for(auto it : s){

            required_window[it- 'a']++;

        }

        int n=s.length();

        Node* temp=head,*temp1=head;

        int prev=-1;

        int i=0,j=0;

        while(temp1){

            if(j-i<n-1){

                window[temp1->data - 'a']++;

                j++;

            }else{

                window[temp1->data - 'a']++;

                j++;

                if(window==required_window){

                    if(prev < i){

                        res.push_back(temp);

                        prev=j-1;

                    }

                }

                window[temp->data - 'a']--;

                i++;

                temp=temp->next;

            }

            temp1=temp1->next;

        }

        vector<Node*> finalres;

        for(auto it : res){

            Node* t=it;

            int i=0;

            while(++i<n){

                t=t->next;

            }

            t->next=nullptr;

            finalres.push_back(it);

        }

        return finalres;

    }

};
