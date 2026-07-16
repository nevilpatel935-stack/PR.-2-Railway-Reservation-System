#include<iostream>
using namespace std;

class Train{
	private:
		int trainNumber;
		char trainName[50];
		char source[50];
		char destination[50];
		char trainTime[20];
		
		static int trainCount;
	public:
		Train()
		{
		    trainNumber = 0;
		    trainCount++;
		}
		
		 ~Train()
	    {
	        trainCount--;
	    }
		
		void setData()
		{
		    cout<<"Enter Train Number : ";
		    cin>>trainNumber;
		
		    cin.ignore();
		
		    cout<<"Enter Train Name : ";
		    cin.getline(trainName,50);
		
		    cout<<"Enter Source : ";
		    cin.getline(source,50);
		
		    cout<<"Enter Destination : ";
		    cin.getline(destination,50);
		
		    cout<<"Enter Train Time : ";
		    cin.getline(trainTime,20);
		}
		
		void getData()
		{
		    cout<<"Train Number : "<<trainNumber<<endl;
		    cout<<"Train Name : "<<trainName<<endl;
		    cout<<"Source : "<<source<<endl;
		    cout<<"Destination : "<<destination<<endl;
		    cout<<"Train Time : "<<trainTime<<endl;
		}
		
		int getTrainNumber()
		{
		    return trainNumber;
		}
		
};

  int Train::trainCount=0;
  
int main()
{
    Train t[100];

    int choice;
    int total=0;

    do
    {
        cout<<"\n----- Railway Reservation System -----"<<endl;
        cout<<"1.Add Train"<<endl;
        cout<<"2.Display All"<<endl;
        cout<<"3.Search Train"<<endl;
        cout<<"4.Exit"<<endl;
        
        cout<<endl;

        cout<<"Enter Choice : ";
        cin>>choice;

        switch(choice)
        {
        case 1:

            t[total].setData();

            total++;

            break;

        case 2:

            for(int i=0;i<total;i++)
            {
                t[i].getData();
            }

            break;

       case 3:
		{
		    int search;
		    bool found = false;
		
		    cout<<"Enter Train Number : ";
		    cin>>search;
		
		    for(int i=0; i<total; i++)
		    {
		        if(t[i].getTrainNumber() == search)
		        {
		            t[i].getData();
		            found = true;
		        }
		    }
		
		    if(found == false)
		    {
		        cout<<"Train Not Found"<<endl;
		    }
		
		    break;
		}

        case 4:

            cout<<"Thank You"<<endl;

            break;

        default:

            cout<<"Invalid Choice"<<endl;
        }

    }while(choice!=4);

    return 0;
}
