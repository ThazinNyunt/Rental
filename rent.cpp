#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

string convert(string & s)
{
	for(int i=0; i<s.length(); i++)
	{
		s[i]=tolower(s[i]);
	}
	return s;
}

class Owner {
private: 
	string oid;
	string oname;
public:
	void get_data(){
	cout<<"Owner ID: ";cin>>oid;
	cout<<"Owner Name: ";cin>>oname;
	}
	void show_data(){
	cout<<setw(12)<<oid<<" | "<<setw(12)<<oname<<" | "<<endl;
	}
	string get_oid(){
	return oid;
	}
	string get_oname(){
	return oname;
	}
};

class Client{
private:
	string cid;
	string cname;
public:
	void get_data(){
	cout<<"Client ID: ";cin>>cid;
	cout<<"Client Name: ";cin>>cname;
	}
	void show_data(){
	cout<<setw(12)<<cid<<" | "<<setw(20)<<cname<<" | "<<endl;
	}
	void client_theader(){
	cout<<setw(15)<<"Client ID | "<<setw(23)<<"Client Name | "<<endl;
	}
	string get_cid(){
	return cid;
	}
	string get_cname(){
	return cname;
	}
};

class Property{
private:
	string pid;
	string pcity;
	int rprice;
	string township;
	string type;
	string floor;
	string status;
	Owner o;
public:
	void get_data()
	{
		o.get_data();
		cout<<"Property ID: ";cin>>pid;
		cout<<"Property City: ";cin>>pcity;
		cout<<"Township: ";cin>>township;
		cout<<"Type [eg. House/Apartment]: ";cin>>type;
		if(type=="Apartment")
		{ cout<<"Floor: ";cin>>floor; }
		else
		{ floor = "-";	}
		
		cout<<"Rent Price: ";cin>>rprice;
		status="available";
		
	
	}
	void show_data(){
	cout<<setw(12)<<pid<<" | "<<setw(12)<<pcity<<" | "<<setw(12)<<township<<" | "<<setw(12)<<type<<" | "<<setw(9)<<floor<<" | "<<setw(12)<<rprice<<" | "<<setw(12)<<status<<" | ";o.show_data();
	}
	void property_header(){
	cout<<setw(15)<<"Property ID | "<<setw(15)<<"City | "<<setw(15)<<"Township | "<<setw(15)<<"Type | "<<setw(12)<<"Floor | "<<setw(15)<<"Rent Price | "<<setw(15)<<"Status | "<<setw(15)<<"Owner ID | "<<setw(15)<<"Owner Name | "<<endl;
	}
	string get_pid(){
	return pid;
	}
	string get_pcity(){
	return pcity;
	}
	int get_rprice(){
	return rprice;
	}
	string get_township(){
	return township;
	}
	string get_type(){
	return type;
	}
	string get_floor(){
	return floor;
	}
	string get_status(){
	return status;
	}
	void set_status(){
	status = "rented";
	}
	
};

class Rental{
private:
	string rid;
	string rcid;
	string rpid;
	int stime;
	int etime;
	Client c;
	Property p;
public:
	void get_data(){
	cout<<"Rent ID : ";cin>>rid;
	cout<<"Client ID : ";cin>>rcid;
	cout<<"Property ID : ";cin>>rpid;
	cout<<"Start Date(YYYYMMDD) eg:20200622: ";cin>>stime;
	cout<<"End Date(YYYYMMDD)   eg:20200622: ";cin>>etime;
	}
	void show_data(){
	cout<<setw(12)<<rid<<" | "<<setw(12)<<rcid<<" | "<<setw(12)<<rpid<<" | "<<setw(12)<<stime<<" | "<<setw(12)<<etime<<" | "<<endl;
	}
	string get_rid(){
	return rid;
	}
	string get_rcid(){
	return rcid;
	}
	string get_rpid(){
	return rpid;
	}
	int get_stime(){
	return stime;
	}
	int get_etime(){
	return etime;
	}
	void rental_header(){
	cout<<setw(15)<<"Rental ID | "<<setw(15)<<"Client ID | "<<setw(15)<<"Property ID | "<<setw(15)<<"Start Date | "<<setw(15)<<"End Date | "<<endl;
	}
};

int main()
{
	int no = 1;
	char ans;
	void client();
	int ch;
	
	vector<Client>vecCli;
	Client c;
	vector<Property>vecPro;
	Property p;
	vector<Rental>vecRen;
	Rental r;
	
	menu: 
		cout<<"-------Main Menu-------"<<endl;
		cout<<"1.Insert Client \n2.Insert Property \n3.Search Property \n4.Rent Property \n5.Search detail \n0.Exit \n";
		//cout<<"[Enter 1,2,3,4,0 to continue]"<<endl;
		cin>>ch;
	
	if(ch==1)
	{
		do
		{
			cout<<"Client "<<no<<endl;
			c.get_data();
			vecCli.push_back(c);
			cout<<"Any more?(y/n)?"<<endl; cin>>ans;
			no++;
			cout<<endl;
		}while(ans == 'y');
		
		cout<<"----------------Client Table-------------------"<<endl;
		c.client_theader();
		for(int i=0;i<vecCli.size();i++)
		{
			vecCli.at(i).show_data();
		}
		cout<<endl;
		
		cout<<"Enter 0 to go to main menu"<<endl;
		cin>>ch;
		if(ch==0)
		goto menu;	
	}
	else if(ch==2)
	{
		no = 1;//Rest Number
		do
		{
			cout<<"Property "<<no<<endl;
			p.get_data();
			vecPro.push_back(p);
			cout<<"Any more?(y/n)?"<<endl;cin>>ans;
			no++;
			cout<<endl;
		}while(ans == 'y');
		
		cout<<"\t\t--------------------------Property Table--------------------------"<<endl;
		p.property_header();
		for(int i=0; i<vecPro.size();i++){
			vecPro.at(i).show_data();
		}
		cout<<endl;
		
		cout<<"Enter 0 to exit"<<endl;
		cin>>ch;
		if(ch==0)
		goto menu;
	}
	else if(ch==3)
	{
		if((vecPro.size()==0) || (vecCli.size()==0))
		{
			cout<<"Please intsert Property's and Client's data First!";
			cout<<"\nEnter 0 to go back"<<endl;
			cin>>ch;
			if(ch==0)
			{	goto menu; }	
		}
		int s;
		string keyword;
		string result;
		search:
			cout<<"\nSearch Property by :"<<endl;
			cout<<"1.City \n2.Township \n3.Type \n4.Floor \n5.Price \n0.Back"<<endl;
			cin>>s;
		
		if(s==1)//Search by City
		{
			int loop=0;
			cout<<"Enter City : ";cin>>keyword;
			keyword = convert(keyword);
			for(int i=0; i<vecPro.size(); i++)
			{
				result=vecPro[i].get_pcity();
				result= convert(result);
				if(result == keyword)
				{
					if(loop==0)
					{
						cout<<"\t\t--------------------------Search Result--------------------------"<<endl;
						p.property_header();
						loop++;	
					}	
					vecPro[i].show_data();
				}				
			}
			if(loop==0)
			{
				cout<<"\nCan't find!"<<endl;
			}
			cout<<"\nEnter 0 to go back"<<endl;
				cin>>ch;
				if(ch==0)
				goto search;
		}
		else if(s==2)//Search by Township
		{
			int loop=0;
			cout<<"Enter Township : ";cin>>keyword;
			keyword = convert(keyword);
			for(int i=0; i<vecPro.size(); i++)
			{
				result=vecPro[i].get_township();
				result= convert(result);
				if(keyword==result)
				{
					if(loop==0)
					{
						cout<<"\t\t--------------------------Search Result--------------------------"<<endl;
						p.property_header();
						loop++;	
					}
					vecPro[i].show_data();	
				}				
			}
			if(loop==0)
			{
				cout<<"Can't find!"<<endl;
			}
			cout<<"\nEnter 0 to go back"<<endl;
				cin>>ch;
				if(ch==0)
				goto search;
		}
		else if(s==3)//Search by Type
		{
			int loop=0;
			cout<<"Enter Type : ";cin>>keyword;
			keyword = convert(keyword);
			for(int i=0; i<vecPro.size(); i++)
			{
				result=vecPro[i].get_type();
				result= convert(result);
				if(keyword==result)
				{
					if(loop==0)
					{
						cout<<"\t\t--------------------------Search Result--------------------------"<<endl;
						p.property_header();
						loop++;	
					}	
					vecPro[i].show_data();
				}				
			}
			if(loop==0)
			{
				cout<<"Can't find!"<<endl;
			}
			cout<<"\nEnter 0 to go back"<<endl;
				cin>>ch;
				if(ch==0)
				goto search;
		}
		else if(s==4)//Search by Floor
		{
			int loop=0;
			cout<<"Enter City : ";cin>>keyword;
			keyword = convert(keyword);
			for(int i=0; i<vecPro.size(); i++)
			{
				result=vecPro[i].get_floor();
				result= convert(result);
				if(keyword==result)
				{
					if(loop==0)
					{
						cout<<"\t\t--------------------------Search Result--------------------------"<<endl;
						p.property_header();
						loop++;
					}					
					vecPro[i].show_data();
				}					
			}
			if(loop==0)
			{
				cout<<"Can't find!"<<endl;
			}
			cout<<"\nEnter 0 to go back"<<endl;
				cin>>ch;
				if(ch==0)
				goto search;
		}
		else if(s==5)//Search by Price
		{
			int loop=0;
			int price1 =0;
			int price2 =0;
			cout<<"Enter the price range "<<endl;
			cout<<"From : ";cin>>price1;
			cout<<"  To : ";cin>>price2;
			
			for(int i=0; i<vecPro.size(); i++)
			{
				int price3=vecPro[i].get_rprice();
				
				if((price1<=price3) && (price2>=price3))
				{
					if(loop==0)
					{
						cout<<"\t\t--------------------------Search Result--------------------------"<<endl;
						p.property_header();
						loop++;
					}	
					vecPro[i].show_data();		
				}			
			}
			if(loop==0)
			{
				cout<<"Can't find!"<<endl;
			}
			cout<<"\nEnter 0 to go back"<<endl;
				cin>>ch;
				if(ch==0)
				{	goto search; }
		}
		else if(s==0)//exit
		{
			goto menu;
		}
	}
			
	else if(ch==4)//Rental Case
	{
		if((vecPro.size()==0) || (vecCli.size()==0))
		{
			cout<<"Please intsert Property's and Client's data First!";
			cout<<"\nEnter 0 to go back"<<endl;
			cin>>ch;
			if(ch==0)
			{	goto menu; }	
		}
		int temp_cid,temp_pid;
		int stop = 0; //looping preventation
		cout<<"---------Rental Case-----------"<<endl;
		no = 0; //reset number
		do{
			cout<<"Rental "<<no+1<<endl;
			r.get_data();
			if(no>0)
			{
				for(int i=0; i<vecRen.size(); i++)
				{
					int sdate1 = vecRen[i].get_stime();
					int edate1 = vecRen[i].get_etime();
					int sdate2 = r.get_stime();
					int edate2 = r.get_etime();
					string id1 = vecRen[i].get_rpid();
					string id2 = r.get_rpid();
					
					if(id1==id2 && sdate2<edate1)
					{
						do
						{
							cout<<"\nSorry! The dates for this property is invalid!"<<endl;
							cout<<"Those dates are invalid. Please refill again and choose another dates!"<<endl;
							r.get_data();
							sdate2 = r.get_stime();
						}while(sdate2<edate1);
					}					
				}
				
			}
			string rpid = r.get_rpid();
			for(int i=0; i<vecPro.size();i++)
			{
				string pid = vecPro[i].get_pid();
				if(pid == rpid)
				{
					vecPro[i].set_status();
					cout<<vecPro[i].get_status();
				}
			}
			 
			
			vecRen.push_back(r);
			cout<<"Any more?(y/n)?"<<endl;cin>>ans;
			no++;
			cout<<endl;
		
		}while(ans !='n');
		
		//-----------Client Validation------------
		for(int i=0;i<vecCli.size();i++)
		{
			if(r.get_rcid()==vecCli[i].get_cid())
			{
				temp_cid = i;
				stop = 0;
				break;
			}
			else
			{
				stop = 1;
			}
		}
		if(stop == 1)
		{
			cout<<"Sorry! Client ID "<<r.get_rcid()<<"doesn't exist."<<endl;
			return 0;
		}
		
		//----------Property Validataion-------------
		for(int i=0; i<vecPro.size();i++)
		{
			if(r.get_rpid()==vecPro[i].get_pid())
			{
				temp_pid = i;
				stop = 0;
				break;
			}
			else
			{
				stop = 1;
			}
		}
		if(stop == 1)
		{
			cout<<"Sorry? This Property ID "<<r.get_rpid()<<"doesn't exist"<<endl;
			return 0;
		}
		
		cout<<"\t----------------Rental Table----------------"<<endl;
		r.rental_header();
		for(int i=0;i<vecRen.size();i++)
		{
			vecRen.at(i).show_data();
		}
		cout<<endl;
		
		//---------Rental Detail Information-------------
		string cid2,pid2,stime2,etime2;
		string result_cname,result_pcity;
		int result_rprice;
		int temp_cid2,temp_pid2,temp_rprice2;
		
		cout<<"---------Result-------------"<<endl;
		for(int i=0; i<vecRen.size();i++)
		{
			cid2 = vecRen[i].get_rcid();
			pid2 = vecRen[i].get_rpid();
			stime2 = vecRen[i].get_stime();
			etime2 = vecRen[i].get_etime();
			
			for(int j=0; j<vecCli.size();j++)
			{
				if(vecCli[j].get_cid() == cid2)
				{
					temp_cid2 = j;
					result_cname = vecCli[j].get_cname();
					break;
				}
			}
			for(int k =0; k<vecPro.size();k++)
			{
				if(vecPro[k].get_pid()==pid2)
				{
					temp_pid2 = k;
					result_pcity = vecPro[k].get_pcity();
					result_rprice = vecPro[k].get_rprice();
				}
			}
			cout<<endl;
			cout<<"Rental ID - "<<vecRen[i].get_rid()<<endl;
			cout<<"Client Name - "<<result_cname<<endl;
			cout<<"Prpoerty Address - "<<result_pcity<<endl;
			cout<<"Rent Price - "<<result_rprice<<endl;
			cout<<"Rent Start Date - "<<vecRen[i].get_stime()<<endl;
			cout<<"Rent End Date - "<<vecRen[i].get_etime()<<endl;
			
			cout<<"\nEnter 0 to go back"<<endl;
			cin>>ch;
			if(ch==0)
			{	goto menu; }
			
		}//End of Rental Case
	}
	else if(ch==5)//Search Propery By Status
	{
		if((vecPro.size()==0) || (vecCli.size()==0))
		{
			cout<<"Please intsert Property's and Client's data First!";
			cout<<"\nEnter 0 to go back"<<endl;
			cin>>ch;
			if(ch==0)
			{	goto menu; }	
		}
		int search;
		psearch:
			cout<<"-----Search Property-----"<<endl;
			cout<<"1.All \n2.Rented \n3.Available \n0.Back"<<endl;
			cin>>search;
		
		if(search==1)//Search all Properties
		{
			cout<<"\t\t--------------------------Property List--------------------------"<<endl;
			p.property_header();
			for(int i=0; i<vecPro.size();i++)
			{
				vecPro[i].show_data();
			}
			cout<<endl;
			
			cout<<"\nEnter 0 to go back"<<endl;
			cin>>ch;
			if(ch==0)
			{	goto menu; }
		}
		else if(search==2)//Search Rented Property
		{
			cout<<"\t\t--------------------------Rented Property--------------------------"<<endl;
			p.property_header();
			for(int i=0; i<vecPro.size();i++)
			{
				if(vecPro[i].get_status()=="rented")
				{
					vecPro[i].show_data();
				}
			}
			cout<<endl;
			
			cout<<"\nEnter 0 to go back"<<endl;
			cin>>ch;
			if(ch==0)
			{	goto menu; }
		}
		else if(search==3)//Search Available Property
		{
			cout<<"\t\t--------------------------Available Property--------------------------"<<endl;
			p.property_header();
			for(int i=0; i<vecPro.size();i++)
			{
				if(vecPro[i].get_status()=="available")
				{
					vecPro[i].show_data();
				}
			}
			cout<<endl;
			
			cout<<"\nEnter 0 to go back"<<endl;
			cin>>ch;
			if(ch==0)
			{	goto menu; }
		}
	}
	else if(ch==0)
	{
		cout<<"  ---Bye---";	
	}
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	

	 

