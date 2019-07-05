#include"mysql.hpp"
#include<cstdio>
#include<cstdlib>
#include<unistd.h>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
int main(void)
{
#if 1
  string header;
  string body;
  body.resize(10000);
  char ret[64];
  char *info=NULL;
  int lenstr=0;
  lenstr=atoi(getenv("CONTENT_LENGTH"));
  info=(char *)malloc(lenstr+1);
  fread(info,1,lenstr,stdin);
  string data = info;       
  sscanf(info,"ret=%[^&]",ret);
  free(info);
#endif
  Mysql mysql;
  mysql.ConnectDatabase();
  string rett = ret;
  vector<vector<string> > m;
  mysql.QueryDatabase3("select username,access from user order by access asc",m);
#if 1
  string html;
  html.resize(1000);
  for(size_t i = 0; i < m.size(); ++i)
  {
 html +="<form name = \"input1\"\
                        action = \"/cgi-bin/mg.cgi\" method = \"post\" id = \"form5\">\
                        <div style=\"padding-left:20px; padding-top:0px\">\
                        "+m[i][0]+"-------------------"+m[i][1]+"\
                        <select name=\"cz\">\
                                <option value=\"update\">审核</option>\
                                <option value=\"delete\">删除</option>\
                        </select>\
                        <input type=\"text\" style=\"display:none;\" value=\""+m[i][0]+"\" name = \"Who\">\
                        <input type = \"submit\" value= \"确认\" style='font-size:10px'>\
                        </div>\
                        </form>";
  }
    //cout<<"success"<<endl;
#if 0
         body = "<body background=\"http://212.129.243.64/bj.png\"\r\n\
                 style=\" background-repeat:no-repeat;\r\n\
                 background-size:100% 100%;\r\n\
                 background-attachment: fixed;\">\r\n\
                 成功\r\n\
                 <a href=\"http://212.129.243.64/\">hehe</a>\r\n\
                 <a href=\"#\" onClick=\"javascript :history.back(-1);\">返回</a>\r\n\
                 </body>";

#endif
                body = "<body background=\"http://212.129.243.64/1.jpg\"\
                        style=\" background-repeat:no-repeat;background-size:100% 100%;\
                        background-attachment: fixed;\">\
                        <title>用户管理</title>\
                        <div style = \"height:500px;padding-top:305px;\">\
                        <div style=\"background:url(http://212.129.243.64/mokuai.png);\
                        display:block;width:400;float:left;margin-left:30px;\
                        background-repeat: no-repeat;background-size:100% 100%;\">\
                        <form name = \"input1\"\
                        action = \"/cgi-bin/manger.cgi\" method = \"post\" id = \"form1\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+rett+"\" name = \"ret\">\
                        <div style=\"padding-left:110px; padding-top:0px\">\
                        <input type = \"submit\" value= \"用户管理\" style='font-size:40px'>\
                        </div>\
                        </form>\
                        <form name = \"input\" action = \"/cgi-bin/manger2.cgi\" method = \"post\" id = \"form2\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+rett+"\" name = \"ret\">\
                        <div style=\"padding-left:110px; padding-top:10px\">\
                        <input type = \"submit\" value= \"公告管理\" style='font-size:40px'>\
                        </div>\
                        </form>\
                        <form name = \"input\" action = \"/cgi-bin/manger3.cgi\" method = \"post\" id = \"form3\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+rett+"\" name = \"ret\">\
                        <div style=\"padding-left:110px; padding-top:17px\">\
                        <input type = \"submit\" value= \"课程管理\" style='font-size:40px'>\
                        </div>\
                        </form>\
                        <form name = \"input\" action = \"/cgi-bin/manger4.cgi\" method = \"post\" id = \"form4\">\
                        <input type=\"text\" style=\"display:none;\" value=\""+rett+"\" name = \"ret\">\
                        <div style=\"padding-left:110px; padding-top:20px\">\
                        <input type = \"submit\" value= \"留言管理\" style='font-size:40px'>\
                        </div>\
                        </form>\
                        </div>\
                        <div style =\"display:block;float:right; width:50%;\">\
                        <h3>用户管理</h3>\
                        "+html+"\
                        </div>\
                        </div>\
                        </body>";

  header += "Content-type: text/html;charset=utf-8\r\n\r\n";
  cout<<header+body<<endl;
#endif
  return 0;
} 
