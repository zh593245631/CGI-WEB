#include"mysql.hpp"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
  string id,title,data;
  vector<vector<string> > v;
  Mysql mysql;
  mysql.ConnectDatabase();
#if 0
  mysql.QueryDatabase("Message",v);
  for(auto &e:v)
  {
    for(auto&c:e)
      cout<<c;
    cout<<endl;
  }
#endif

  string ID,CON;
  cout<<"ID"<<endl;
  cin>>ID;
  cout<<"CON"<<endl;
  cin>>CON;
 string qu;
 qu +="update resource set content='"+CON+"' where ID='"+ID+"'";
  cout<<mysql.modifydata2(qu)<<endl;
  return 0;
}
