#include"mysql.hpp"
#include<cstdio>
#include<cstdlib>
#include<unistd.h>
#include<string>
#include<iostream>
using namespace std;
int main(void)
{
  string header;
  //string first_line = "HTTP/1.0 200 OK\n";
  string body;
  body.resize(10000);
  char Who[64];
  char *info=NULL;
  int lenstr=0;
  /*
   * Get the data by post method from index.html
   */
  lenstr=atoi(getenv("CONTENT_LENGTH"));
  info=(char *)malloc(lenstr+1);
  fread(info,1,lenstr,stdin);
  string data = info;       
  sscanf(info,"Who=%[^&]",Who);
  free(info);
  string who = Who;
  Mysql mysql;
  mysql.ConnectDatabase();
  string qu = "delete from message where ID='"+who+"'";
  mysql.modifydata2(qu);
  body = "<body>\r\n\
             删除成功\r\n\
   <a href=\"#\" onClick=\"javascript :history.back(-1);\">返回</a>\r\n";
   header += "Content-type: text/html;charset=utf-8\r\n\r\n";
   cout<<header+body<<endl;
}
