#include <bits/stdc++.h>
using namespace std;

 class reservations
 {
     public:
         string ReservationID;
         string travelername;
         string travelermobilenumber;
         string takeoffairport;
         string destinationairport;


         reservations()
         {
             ReservationID="";
             travelername="";
             travelermobilenumber="";
             takeoffairport="";
             destinationairport="";

         }

        reservations(string x,string y,string z,string l,string o)
        {
            ReservationID=x;
            travelername=y;
            travelermobilenumber=z;
            takeoffairport=l;
            destinationairport=o;
        }

};

 class DLLNode {

  public:
    reservations info;
    DLLNode  *next, *prev;
    DLLNode()
    {
        next=prev=0;
    }


    DLLNode(const reservations& el, DLLNode *n = 0, DLLNode *p = 0) {
        info = el; next = n; prev = p;
    }

};
 class DoublyLinkedList
  {
      DLLNode *head,*tail;

public:

    DoublyLinkedList()
   {
       head = tail = 0;

    }




    void Reserveaticket(const reservations& el)
    {
            if (head == 0)
            {
                head = tail = new DLLNode(el);
            }
      else
       {
          head = new DLLNode(el,head,0);
           head->next->prev = head;
       }

    }



   void CancelaticketbyID  (string el)
   {
       reservations s=head->info;
    if (head != 0)
         if (head == tail && s.ReservationID== el) {
              delete head;
              head = tail = 0;
         }
         else if (s.ReservationID== el) {
               DLLNode*tmp = head;
              head = head->next;
              head->prev=0;
              delete tmp;
         }
         else {
                     DLLNode *pred= head;
                     DLLNode *tmp=head->next;
                    while(tmp != 0 && ((tmp->info).ReservationID != el)){
                        pred = pred->next;
                        tmp = tmp->next;
                     }
                     if (tmp != 0) { //the target exists in List
                          pred->next = tmp->next;
                          if(tmp!=tail)
                          {
                            tmp->next->prev=pred;

                          }

                          if (tmp == tail)
                             tail = pred;
                          delete tmp;
                     }
	   }
    }

   void insertionSortbyID()
    {
        for(DLLNode *tmp=head->next,*ptr;tmp!=0;tmp=tmp->next)
        {
             //DLLNode *por=tmp;
             reservations h=tmp->info;


            for(ptr=tmp;ptr!=head&&h.ReservationID<(ptr->prev->info).ReservationID; )
            {

                ptr->info=ptr->prev->info;

                ptr=ptr->prev;

            }


            ptr->info=h;



        }
    }


  void  Checkforreservationbyname(string el)
  {
	DLLNode * current;
    bool flag=false;
	current = head;
	while (current != 0)
	{
	    if(current->info.travelername==el)
        {
            flag=true;
            break;
        }
        else
        {
            current = current->next;

        }



	}
	if(flag)
    {
        cout<<"Traveler found "<<endl;
    }
    else
    {
        cout<<"Traveler not found"<<endl;
    }
  }

  void  updateforreservationbyID(string id,string name,string number,string takeoff,string dist)
  {
	DLLNode * current;
    bool flag=false;
	current = head;
	while (current != 0)
	{
	    if(current->info.ReservationID==id)
        {
            current->info.travelername=name;
            current->info.travelermobilenumber=number;
            current->info.takeoffairport=takeoff;
            current->info.destinationairport=dist;

            flag=true;
            break;
        }
        else
        {
            current = current->next;

        }



	}
	if(flag)
    {
        cout<<"traveler "<<id<<" is updated all it is information"<<endl;
    }
    else
    {
        cout<<"Traveler not found"<<endl;
    }
  }



  void  print_ascending()
  {
	DLLNode * current;

	current = head;
    int c=1;
	while (current != 0)
	{
	    cout<<"traveler"<<c<<endl;
	    cout<<"..............................."<<endl;
		cout<<(current->info).ReservationID<<" "<<endl;
		cout<<(current->info).travelername<<" "<<endl;
		cout<<(current->info).travelermobilenumber<<" "<<endl;
		cout<<(current->info).takeoffairport<<" "<<endl;
		cout<<(current->info).destinationairport<<" "<<endl;
		cout<<"..............................."<<endl;
		cout<<endl;
		current = current->next;
		c++;
	}
  }




  void  print_descending ()
  {
	DLLNode * current;

	current = tail;
    int c=1;
	while (current != 0)
	{
	    cout<<"traveler"<<c<<endl;
	    cout<<"..............................."<<endl;
		cout<<(current->info).ReservationID<<" "<<endl;
		cout<<(current->info).travelername<<" "<<endl;
		cout<<(current->info).travelermobilenumber<<" "<<endl;
		cout<<(current->info).takeoffairport<<" "<<endl;
		cout<<(current->info).destinationairport<<" "<<endl;
		cout<<"..............................."<<endl;
		cout<<endl;
		current = current->prev
		;
		c++;
	}
  }

    void addReservarion()
  {
    reservations r;

    getline(cin, r.ReservationID);
    r.ReservationID += '\n';
    getline(cin, r.travelername);
    r.travelername += '\n';
    getline(cin, r.travelermobilenumber);
    r.travelermobilenumber += '\n';
    getline(cin, r.takeoffairport);
    r.takeoffairport += '\n';
    getline(cin, r.destinationairport);
    r.destinationairport += '\n';
   //======================================================================
   // below you can write one or more reservation
   //======================================================================
   fstream file("test.txt", ios::out); //opening file in writing mode (ios::out)
   file.write(r.ReservationID.c_str(), r.ReservationID.size());
   file.write(r.travelername.c_str(), r.travelername.size());
   file.write(r.travelermobilenumber.c_str(), r.travelermobilenumber.size());
   file.write(r.takeoffairport.c_str(), r.takeoffairport.size());
   file.write(r.destinationairport.c_str(), r.destinationairport.size());
   file.close(); //close the file
   //===================================================================
}


  void readReservation()
  {
      reservations r;
      fstream file("test.txt", ios::in); //opening file in reading mode (ios::in)
     //read a line, lines are separated by newline  (\n)
     getline(file, r.ReservationID);
     getline(file, r.travelername);
     getline(file, r.travelermobilenumber);
     getline(file, r.takeoffairport);
      getline(file, r.destinationairport);
      Reserveaticket(r);
      file.close(); //close the file


}

 void addReservarion2(int n)
  {
      int i=0;

    while(i<n)
    {
        reservations r;

    getline(cin, r.ReservationID);
    r.ReservationID += '\n';
    getline(cin, r.travelername);
    r.travelername += '\n';
    getline(cin, r.travelermobilenumber);
    r.travelermobilenumber += '\n';
    getline(cin, r.takeoffairport);
    r.takeoffairport += '\n';
    getline(cin, r.destinationairport);
    r.destinationairport += '\n';

   fstream file("test.txt", ios::out);
   file.write(r.ReservationID.c_str(), r.ReservationID.size());
   file.write(r.travelername.c_str(), r.travelername.size());
   file.write(r.travelermobilenumber.c_str(), r.travelermobilenumber.size());
   file.write(r.takeoffairport.c_str(), r.takeoffairport.size());
   file.write(r.destinationairport.c_str(), r.destinationairport.size());
   file.close();

     readReservation();
      i++;

    }

}



};

int main()
{

        DoublyLinkedList  *n = new DoublyLinkedList ();
        n->addReservarion2(3);
        n->print_ascending();











    return 0;
}
