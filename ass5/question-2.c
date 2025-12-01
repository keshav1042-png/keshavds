void countAndDelete(Node*& head, int key){
    int count=0;
    Node* curr=head,*prev=NULL;
    while(curr){
        if(curr->data==key){
            count++;
            if(!prev){ head=curr->next; delete curr; curr=head; }
            else { prev->next=curr->next; delete curr; curr=prev->next; }
        } else { prev=curr; curr=curr->next; }
    }
    cout<<"Count: "<<count<<"\n";
}
